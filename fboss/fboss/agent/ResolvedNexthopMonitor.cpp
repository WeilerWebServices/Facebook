// Copyright 2004-present Facebook. All Rights Reserved.

#include "fboss/agent/ResolvedNexthopMonitor.h"

#include "fboss/agent/ResolvedNexthopProbeScheduler.h"
#include "fboss/agent/if/gen-cpp2/ctrl_types.h"
#include "fboss/agent/state/DeltaFunctions.h"
#include "fboss/agent/state/Interface.h"
#include "fboss/agent/state/StateDelta.h"
#include "fboss/agent/state/SwitchState.h"

#include <gflags/gflags.h>
#include <thrift/lib/cpp/util/EnumUtils.h>

namespace {
using namespace facebook::fboss;

auto static constexpr kMonitorNexthopsForHelp =
    "comma separated list of ClientIDs. Default value is OPENR. "
    "Resolved next hops of routes programmed by these clients will be probed, "
    "if neighbor entry for these next hops is missing";

bool kValidateMonitorNextHopsFor(
    const char* /*flagname*/,
    const std::string& value) {
  std::vector<std::string> clientsStr;
  folly::split(",", value, clientsStr);
  using apache::thrift::util::tryParseEnum;

  std::set<ClientID> clients;
  for (const auto& clientStr : clientsStr) {
    ClientID client;
    if (!tryParseEnum(clientStr, &client)) {
      return false;
    }
    clients.insert(client);
  }
  ResolvedNexthopMonitor::updateMonitoredClients(std::move(clients));
  return true;
}

} // namespace

using facebook::fboss::DeltaFunctions::forEachAdded;
using facebook::fboss::DeltaFunctions::forEachChanged;
using facebook::fboss::DeltaFunctions::forEachRemoved;

/* monitoring only resolved next hops of select few clients, as opposed to
 * monitoring resolved next hops of all routes. this is to prevent flood of
 * probes in cases which has thousands of next hops which are l3 resolved but no
 * neighbor entries for such next hops exists e.g.  ILA static routes. */
DEFINE_string(monitor_nexthops_for, "OPENR", kMonitorNexthopsForHelp);
DEFINE_validator(monitor_nexthops_for, kValidateMonitorNextHopsFor);

namespace facebook::fboss {

folly::Synchronized<std::set<ClientID>>
    ResolvedNexthopMonitor::kMonitoredClients;

ResolvedNexthopMonitor::ResolvedNexthopMonitor(SwSwitch* sw)
    : AutoRegisterStateObserver(sw, "ResolvedNexthopMonitor"), sw_(sw) {}

void ResolvedNexthopMonitor::stateUpdated(const StateDelta& delta) {
  scheduleProbes_ = false;
  for (auto const& rtDelta : delta.getRouteTablesDelta()) {
    forEachChanged(
        rtDelta.getRoutesV4Delta(),
        &ResolvedNexthopMonitor::processChangedRouteNextHops<RouteV4>,
        &ResolvedNexthopMonitor::processAddedRouteNextHops<RouteV4>,
        &ResolvedNexthopMonitor::processRemovedRouteNextHops<RouteV4>,
        this);
    forEachChanged(
        rtDelta.getRoutesV6Delta(),
        &ResolvedNexthopMonitor::processChangedRouteNextHops<RouteV6>,
        &ResolvedNexthopMonitor::processAddedRouteNextHops<RouteV6>,
        &ResolvedNexthopMonitor::processRemovedRouteNextHops<RouteV6>,
        this);
  }

  for (const auto& fibDelta : delta.getFibsDelta()) {
    forEachChanged(
        fibDelta.getV4FibDelta(),
        &ResolvedNexthopMonitor::processChangedRouteNextHops<RouteV4>,
        &ResolvedNexthopMonitor::processAddedRouteNextHops<RouteV4>,
        &ResolvedNexthopMonitor::processRemovedRouteNextHops<RouteV4>,
        this);
    forEachChanged(
        fibDelta.getV6FibDelta(),
        &ResolvedNexthopMonitor::processChangedRouteNextHops<RouteV6>,
        &ResolvedNexthopMonitor::processAddedRouteNextHops<RouteV6>,
        &ResolvedNexthopMonitor::processRemovedRouteNextHops<RouteV6>,
        this);
  }

  forEachChanged(
      delta.getLabelForwardingInformationBaseDelta(),
      &ResolvedNexthopMonitor::processChangedLabelFibEntry,
      &ResolvedNexthopMonitor::processAddedLabelFibEntry,
      &ResolvedNexthopMonitor::processRemovedLabelFibEntry,
      this);

  for (const auto& vlanDelta : delta.getVlansDelta()) {
    auto arpDelta = vlanDelta.getArpDelta();
    auto ndpDelta = vlanDelta.getNdpDelta();
    if (arpDelta.getNew() || arpDelta.getOld() || ndpDelta.getNew() ||
        ndpDelta.getOld()) {
      scheduleProbes_ = true;
      break;
    }
  }

  if (!added_.empty() || !removed_.empty()) {
    scheduleProbes_ = true;
    sw_->getResolvedNexthopProbeScheduler()->processChangedResolvedNexthops(
        std::move(added_), std::move(removed_));
  }

  if (scheduleProbes_) {
    sw_->getResolvedNexthopProbeScheduler()->schedule();
  }
}

bool ResolvedNexthopMonitor::skipLabelFibEntry(
    const std::shared_ptr<LabelForwardingEntry>& entry) const {
  if (entry->getLabelNextHop().getAction() !=
      LabelNextHopEntry::Action::NEXTHOPS) {
    return true;
  }
  auto nexthopByClient = entry->getLabelNextHopsByClient();
  auto bestEntry = nexthopByClient.getBestEntry();
  return isClientMonitored(bestEntry.first);
}

void ResolvedNexthopMonitor::processChangedLabelFibEntry(
    const std::shared_ptr<LabelForwardingEntry>& oldEntry,
    const std::shared_ptr<LabelForwardingEntry>& newEntry) {
  processRemovedLabelFibEntry(oldEntry);
  processAddedLabelFibEntry(newEntry);
}

void ResolvedNexthopMonitor::processAddedLabelFibEntry(
    const std::shared_ptr<LabelForwardingEntry>& addedEntry) {
  if (skipLabelFibEntry(addedEntry)) {
    return;
  }
  const auto& fwd = addedEntry->getLabelNextHop();
  for (auto nhop : fwd.normalizedNextHops()) {
    added_.emplace_back(nhop.addr(), nhop.intf(), 0);
  }
}

void ResolvedNexthopMonitor::processRemovedLabelFibEntry(
    const std::shared_ptr<LabelForwardingEntry>& removedEntry) {
  if (skipLabelFibEntry(removedEntry)) {
    return;
  }
  const auto& fwd = removedEntry->getLabelNextHop();
  for (auto nhop : fwd.normalizedNextHops()) {
    removed_.emplace_back(nhop.addr(), nhop.intf(), 0);
  }
}

} // namespace facebook::fboss
