/*
 *  Copyright (c) 2004-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#pragma once

#include <boost/container/flat_map.hpp>
#include <list>
#include <mutex>
#include <string>
#include "fboss/agent/ArpCache.h"
#include "fboss/agent/NdpCache.h"
#include "fboss/agent/StateObserver.h"
#include "fboss/agent/state/PortDescriptor.h"
#include "fboss/agent/types.h"

namespace facebook::fboss {

class SwitchState;
class StateDelta;
class Vlan;

enum ArpOpCode : uint16_t;
enum class ICMPv6Type : uint8_t;

/**
 * This class implements the core neighbor update logic. Its methods are only
 * called from `NeighborUpdater` which schedules calls to this class on the
 * neighbor thread.
 * Having all data structures accessed only from the neighbor thread avoids
 * concurrency issues and simplifies the threading model.
 */
class NeighborUpdaterImpl {
  struct NeighborCaches {
    // These are shared_ptrs for safety reasons as it lets callers safely use
    // the results of getArpCacheFor or getNdpCacheFor even if the vlan is
    // deleted in another thread.
    std::shared_ptr<ArpCache> arpCache;
    std::shared_ptr<NdpCache> ndpCache;

    NeighborCaches(
        SwSwitch* sw,
        const SwitchState* state,
        VlanID vlanID,
        std::string vlanName,
        InterfaceID intfID)
        : arpCache(
              std::make_shared<ArpCache>(sw, state, vlanID, vlanName, intfID)),
          ndpCache(
              std::make_shared<NdpCache>(sw, state, vlanID, vlanName, intfID)) {
    }
  };

 public:
  explicit NeighborUpdaterImpl();
  ~NeighborUpdaterImpl();

  // All methods other than constructor/destructor of this class are private
  // because only NeighborUpdater should be using this class and that is marked
  // as a friend class anyway.
  //
  // See comment in NeighborUpdater.def
 private:
#define ARG_LIST_ENTRY(TYPE, NAME) TYPE NAME
#define NEIGHBOR_UPDATER_METHOD(VISIBILITY, NAME, RETURN_TYPE, ...) \
  RETURN_TYPE NAME(ARG_LIST(ARG_LIST_ENTRY, ##__VA_ARGS__));
#include "fboss/agent/NeighborUpdater.def"
#undef NEIGHBOR_UPDATER_METHOD

  template <typename NeighborCacheT>
  std::shared_ptr<NeighborCacheT> getNeighborCacheFor(VlanID vlan);

  void portChanged(
      const std::shared_ptr<Port>& oldPort,
      const std::shared_ptr<Port>& newPort);
  void aggregatePortChanged(
      const std::shared_ptr<AggregatePort>& oldAggPort,
      const std::shared_ptr<AggregatePort>& newAggPort);

  std::shared_ptr<ArpCache> getArpCacheFor(VlanID vlan);
  std::shared_ptr<ArpCache> getArpCacheInternal(VlanID vlan);
  std::shared_ptr<NdpCache> getNdpCacheFor(VlanID vlan);
  std::shared_ptr<NdpCache> getNdpCacheInternal(VlanID vlan);

  bool flushEntryImpl(VlanID vlan, folly::IPAddress ip);

  // Forbidden copy constructor and assignment operator
  NeighborUpdaterImpl(NeighborUpdaterImpl const&) = delete;
  NeighborUpdaterImpl& operator=(NeighborUpdaterImpl const&) = delete;

  boost::container::flat_map<VlanID, std::shared_ptr<NeighborCaches>> caches_;

  friend class NeighborUpdater;
};

template <>
inline std::shared_ptr<ArpCache> NeighborUpdaterImpl::getNeighborCacheFor(
    VlanID vlan) {
  return getArpCacheFor(vlan);
}

template <>
inline std::shared_ptr<NdpCache> NeighborUpdaterImpl::getNeighborCacheFor(
    VlanID vlan) {
  return getNdpCacheFor(vlan);
}

} // namespace facebook::fboss
