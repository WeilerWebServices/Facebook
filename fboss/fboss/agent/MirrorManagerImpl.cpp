// Copyright 2004-present Facebook. All Rights Reserved.

#include "MirrorManagerImpl.h"

#include "folly/IPAddress.h"

#include "fboss/agent/SwSwitch.h"
#include "fboss/agent/state/DeltaFunctions.h"
#include "fboss/agent/state/Interface.h"
#include "fboss/agent/state/Mirror.h"
#include "fboss/agent/state/Route.h"
#include "fboss/agent/state/RouteTable.h"
#include "fboss/agent/state/RouteTableRib.h"
#include "fboss/agent/state/SwitchState.h"
#include "fboss/agent/state/Vlan.h"

template <typename AddrT>
using NeighborEntryT =
    typename facebook::fboss::MirrorManagerImpl<AddrT>::NeighborEntryT;

namespace facebook::fboss {

template <typename AddrT>
std::shared_ptr<Mirror> MirrorManagerImpl<AddrT>::updateMirror(
    const std::shared_ptr<Mirror>& mirror) {
  const AddrT destinationIp =
      getIPAddress<AddrT>(mirror->getDestinationIp().value());
  const auto state = sw_->getState();
  const auto nexthops = resolveMirrorNextHops(state, destinationIp);

  auto newMirror = std::make_shared<Mirror>(
      mirror->getID(),
      mirror->getEgressPort(),
      mirror->getDestinationIp(),
      mirror->getSrcIp(),
      mirror->getTunnelUdpPorts(),
      mirror->getDscp(),
      mirror->getTruncate());

  for (const auto& nexthop : nexthops) {
    const auto entry =
        resolveMirrorNextHopNeighbor(state, mirror, destinationIp, nexthop);

    if (!entry) {
      continue;
    }

    const auto egressPort = entry->getPort().phyPortID();
    std::optional<AddrT> srcIp = newMirror->getSrcIp()
        ? getIPAddress<AddrT>(mirror->getSrcIp().value())
        : std::optional<AddrT>(std::nullopt);
    newMirror->setMirrorTunnel(resolveMirrorTunnel(
        state,
        destinationIp,
        srcIp,
        nexthop,
        entry,
        newMirror->getTunnelUdpPorts()));
    newMirror->setEgressPort(egressPort);
    break;
  }

  if (*mirror == *newMirror) {
    return std::shared_ptr<Mirror>(nullptr);
  }
  return newMirror;
}

template <typename AddrT>
RouteNextHopEntry::NextHopSet MirrorManagerImpl<AddrT>::resolveMirrorNextHops(
    const std::shared_ptr<SwitchState>& state,
    const AddrT& destinationIp) {
  const auto route =
      sw_->longestMatch<AddrT>(state, destinationIp, RouterID(0));
  if (!route || !route->isResolved()) {
    return RouteNextHopEntry::NextHopSet();
  }
  return route->getForwardInfo().getNextHopSet();
}

template <typename AddrT>
std::shared_ptr<NeighborEntryT<AddrT>>
MirrorManagerImpl<AddrT>::resolveMirrorNextHopNeighbor(
    const std::shared_ptr<SwitchState>& state,
    const std::shared_ptr<Mirror>& mirror,
    const AddrT& destinationIp,
    const NextHop& nexthop) const {
  std::shared_ptr<NeighborEntryT> neighbor;
  if (!nexthop.isResolved()) {
    return std::shared_ptr<NeighborEntryT>(nullptr);
  }
  AddrT mirrorNextHopIp = getIPAddress<AddrT>(nexthop.addr());
  InterfaceID mirrorEgressInterface = nexthop.intf();

  auto interface =
      state->getInterfaces()->getInterfaceIf(mirrorEgressInterface);
  auto vlan = state->getVlans()->getVlanIf(interface->getVlanID());

  if (interface->hasAddress(mirrorNextHopIp)) {
    /* if mirror destination is directly connected */
    neighbor = vlan->template getNeighborEntryTable<AddrT>()->getEntryIf(
        destinationIp);
  } else {
    neighbor = vlan->template getNeighborEntryTable<AddrT>()->getEntryIf(
        mirrorNextHopIp);
  }

  if (!neighbor || neighbor->zeroPort() ||
      !neighbor->getPort().isPhysicalPort() ||
      (mirror->configHasEgressPort() &&
       neighbor->getPort().phyPortID() != mirror->getEgressPort().value())) {
    /* TODO: support mirroring over LAG port */
    return std::shared_ptr<NeighborEntryT>(nullptr);
  }
  return neighbor;
}

template <typename AddrT>
MirrorTunnel MirrorManagerImpl<AddrT>::resolveMirrorTunnel(
    const std::shared_ptr<SwitchState>& state,
    const AddrT& destinationIp,
    const std::optional<AddrT>& srcIp,
    const NextHop& nextHop,
    const std::shared_ptr<NeighborEntryT>& neighbor,
    const std::optional<TunnelUdpPorts>& udpPorts) {
  const auto interface = state->getInterfaces()->getInterfaceIf(nextHop.intf());
  const auto iter = interface->getAddressToReach(neighbor->getIP());

  if (udpPorts.has_value()) {
    return MirrorTunnel(
        srcIp ? srcIp.value() : iter->first,
        destinationIp,
        interface->getMac(),
        neighbor->getMac(),
        udpPorts.value());
  }
  return MirrorTunnel(
      srcIp ? srcIp.value() : iter->first,
      destinationIp,
      interface->getMac(),
      neighbor->getMac());
}

template class MirrorManagerImpl<folly::IPAddressV4>;
template class MirrorManagerImpl<folly::IPAddressV6>;

} // namespace facebook::fboss
