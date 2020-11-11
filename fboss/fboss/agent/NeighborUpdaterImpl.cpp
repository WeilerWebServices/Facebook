/*
 *  Copyright (c) 2004-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#include "fboss/agent/NeighborUpdaterImpl.h"
#include "fboss/agent/ArpCache.h"
#include "fboss/agent/ArpHandler.h"
#include "fboss/agent/FbossError.h"
#include "fboss/agent/IPv6Handler.h"
#include "fboss/agent/NdpCache.h"
#include "fboss/agent/SwSwitch.h"
#include "fboss/agent/state/AggregatePort.h"
#include "fboss/agent/state/ArpTable.h"
#include "fboss/agent/state/DeltaFunctions.h"
#include "fboss/agent/state/NdpTable.h"
#include "fboss/agent/state/Port.h"
#include "fboss/agent/state/StateDelta.h"
#include "fboss/agent/state/SwitchState.h"
#include "fboss/agent/state/Vlan.h"
#include "fboss/agent/state/VlanMap.h"

#include <boost/container/flat_map.hpp>
#include <folly/logging/xlog.h>
#include <list>
#include <mutex>
#include <string>
#include <vector>

using boost::container::flat_map;
using folly::IPAddress;
using folly::IPAddressV4;
using folly::IPAddressV6;
using folly::MacAddress;
using std::shared_ptr;

namespace facebook::fboss {

using facebook::fboss::DeltaFunctions::forEachChanged;

NeighborUpdaterImpl::NeighborUpdaterImpl() {}

NeighborUpdaterImpl::~NeighborUpdaterImpl() {}

shared_ptr<ArpCache> NeighborUpdaterImpl::getArpCacheFor(VlanID vlan) {
  return getArpCacheInternal(vlan);
}

shared_ptr<NdpCache> NeighborUpdaterImpl::getNdpCacheFor(VlanID vlan) {
  return getNdpCacheInternal(vlan);
}

std::list<ArpEntryThrift> NeighborUpdaterImpl::getArpCacheData() {
  std::list<ArpEntryThrift> entries;
  for (auto it = caches_.begin(); it != caches_.end(); ++it) {
    entries.splice(entries.end(), it->second->arpCache->getArpCacheData());
  }
  return entries;
}

std::list<NdpEntryThrift> NeighborUpdaterImpl::getNdpCacheData() {
  std::list<NdpEntryThrift> entries;
  for (auto it = caches_.begin(); it != caches_.end(); ++it) {
    entries.splice(entries.end(), it->second->ndpCache->getNdpCacheData());
  }
  return entries;
}

shared_ptr<ArpCache> NeighborUpdaterImpl::getArpCacheInternal(VlanID vlan) {
  auto res = caches_.find(vlan);
  if (res == caches_.end()) {
    throw FbossError("Tried to get Arp cache non-existent vlan ", vlan);
  }
  return res->second->arpCache;
}
shared_ptr<NdpCache> NeighborUpdaterImpl::getNdpCacheInternal(VlanID vlan) {
  auto res = caches_.find(vlan);
  if (res == caches_.end()) {
    throw FbossError("Tried to get Ndp cache non-existent vlan ", vlan);
  }
  return res->second->ndpCache;
}

void NeighborUpdaterImpl::sentNeighborSolicitation(
    VlanID vlan,
    IPAddressV6 ip) {
  auto cache = getNdpCacheFor(vlan);
  cache->sentNeighborSolicitation(ip);
}

void NeighborUpdaterImpl::receivedNdpMine(
    VlanID vlan,
    IPAddressV6 ip,
    MacAddress mac,
    PortDescriptor port,
    ICMPv6Type type,
    uint32_t flags) {
  auto cache = getNdpCacheFor(vlan);
  cache->receivedNdpMine(ip, mac, port, type, flags);
}

void NeighborUpdaterImpl::receivedNdpNotMine(
    VlanID vlan,
    IPAddressV6 ip,
    MacAddress mac,
    PortDescriptor port,
    ICMPv6Type type,
    uint32_t flags) {
  auto cache = getNdpCacheFor(vlan);
  cache->receivedNdpNotMine(ip, mac, port, type, flags);
}

void NeighborUpdaterImpl::sentArpRequest(VlanID vlan, IPAddressV4 ip) {
  auto cache = getArpCacheFor(vlan);
  cache->sentArpRequest(ip);
}

void NeighborUpdaterImpl::receivedArpMine(
    VlanID vlan,
    IPAddressV4 ip,
    MacAddress mac,
    PortDescriptor port,
    ArpOpCode op) {
  auto cache = getArpCacheFor(vlan);
  cache->receivedArpMine(ip, mac, port, op);
}

void NeighborUpdaterImpl::receivedArpNotMine(
    VlanID vlan,
    IPAddressV4 ip,
    MacAddress mac,
    PortDescriptor port,
    ArpOpCode op) {
  auto cache = getArpCacheFor(vlan);
  cache->receivedArpNotMine(ip, mac, port, op);
}

void NeighborUpdaterImpl::portDown(PortDescriptor port) {
  for (auto vlanCaches : caches_) {
    auto arpCache = vlanCaches.second->arpCache;
    arpCache->portDown(port);

    auto ndpCache = vlanCaches.second->ndpCache;
    ndpCache->portDown(port);
  }
}

bool NeighborUpdaterImpl::flushEntryImpl(VlanID vlan, IPAddress ip) {
  if (ip.isV4()) {
    auto cache = getArpCacheInternal(vlan);
    return cache->flushEntryBlocking(ip.asV4());
  }
  auto cache = getNdpCacheInternal(vlan);
  return cache->flushEntryBlocking(ip.asV6());
}

uint32_t NeighborUpdaterImpl::flushEntry(VlanID vlan, IPAddress ip) {
  uint32_t count{0};
  if (vlan == VlanID(0)) {
    for (auto it = caches_.begin(); it != caches_.end(); ++it) {
      if (flushEntryImpl(it->first, ip)) {
        ++count;
      }
    }
  } else {
    if (flushEntryImpl(vlan, ip)) {
      ++count;
    }
  }
  return count;
}

void NeighborUpdaterImpl::vlanAdded(
    VlanID vlanID,
    std::shared_ptr<NeighborCaches> caches) {
  caches_.emplace(vlanID, std::move(caches));
}

void NeighborUpdaterImpl::vlanDeleted(VlanID vlanID) {
  auto iter = caches_.find(vlanID);
  if (iter != caches_.end()) {
    caches_.erase(iter);
  } else {
    // TODO(aeckert): May want to fatal here when a cache doesn't exist for a
    // specific vlan. Need to make sure that caches are correctly created for
    // the initial SwitchState to avoid false positives
    XLOG(DBG0) << "Deleted Vlan with no corresponding NeighborCaches";
  }
}

void NeighborUpdaterImpl::vlanChanged(
    VlanID vlanID,
    InterfaceID intfID,
    std::string vlanName) {
  auto iter = caches_.find(vlanID);
  if (iter != caches_.end()) {
    iter->second->arpCache->setIntfID(intfID);
    iter->second->ndpCache->setIntfID(intfID);
    iter->second->arpCache->setVlanName(vlanName);
    iter->second->ndpCache->setVlanName(vlanName);
  } else {
    // TODO(aeckert): May want to fatal here when a cache doesn't exist for a
    // specific vlan. Need to make sure that caches are correctly created for
    // the initial SwitchState to avoid false positives
    XLOG(DBG0) << "Changed Vlan with no corresponding NeighborCaches";
  }
}

void NeighborUpdaterImpl::timeoutsChanged(
    std::chrono::seconds arpTimeout,
    std::chrono::seconds ndpTimeout,
    std::chrono::seconds staleEntryInterval,
    uint32_t maxNeighborProbes) {
  for (auto& vlanAndCaches : caches_) {
    auto& arpCache = vlanAndCaches.second->arpCache;
    auto& ndpCache = vlanAndCaches.second->ndpCache;
    arpCache->setTimeout(arpTimeout);
    arpCache->setMaxNeighborProbes(maxNeighborProbes);
    arpCache->setStaleEntryInterval(staleEntryInterval);
    ndpCache->setTimeout(ndpTimeout);
    ndpCache->setMaxNeighborProbes(maxNeighborProbes);
    ndpCache->setStaleEntryInterval(staleEntryInterval);
  }
}

void NeighborUpdaterImpl::updateArpEntryClassID(
    VlanID vlan,
    folly::IPAddressV4 ip,
    std::optional<cfg::AclLookupClass> classID = std::nullopt) {
  auto cache = getArpCacheFor(vlan);
  cache->updateEntryClassID(ip, classID);
}

void NeighborUpdaterImpl::updateNdpEntryClassID(
    VlanID vlan,
    folly::IPAddressV6 ip,
    std::optional<cfg::AclLookupClass> classID = std::nullopt) {
  auto cache = getNdpCacheFor(vlan);
  cache->updateEntryClassID(ip, classID);
}

} // namespace facebook::fboss
