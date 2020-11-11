/*
 *  Copyright (c) 2004-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#include "fboss/agent/hw/test/HwTest.h"

#include "fboss/agent/hw/test/HwSwitchEnsemble.h"
#include "fboss/agent/hw/test/HwSwitchEnsembleFactory.h"
#include "fboss/agent/hw/test/HwTestPortUtils.h"

#include <folly/Singleton.h>
#include <folly/logging/xlog.h>

#include "fboss/agent/ApplyThriftConfig.h"
#include "fboss/agent/Constants.h"
#include "fboss/agent/HwSwitch.h"
#include "fboss/agent/Platform.h"
#include "fboss/agent/state/StateDelta.h"
#include "fboss/agent/state/SwitchState.h"

#ifndef IS_OSS
#if __has_feature(address_sanitizer)
#include <sanitizer/lsan_interface.h>
#endif
#endif

DEFINE_bool(
    setup_for_warmboot,
    false,
    "Set up test for SDK warmboot. Useful for testing individual "
    "tests doing a full process warmboot and verifying expectations");

DEFINE_bool(
    setup_thrift_on_failure,
    false,
    "Set up thrift on demand upon encountering test failure");

namespace {

auto kStageLogPrefix = "RUNNING STAGE: ";

}

namespace facebook::fboss {

HwSwitch* HwTest::getHwSwitch() {
  return hwSwitchEnsemble_->getHwSwitch();
}

Platform* HwTest::getPlatform() {
  return hwSwitchEnsemble_->getPlatform();
}

const HwAsic* HwTest::getAsic() const {
  return getPlatform()->getAsic();
}

bool HwTest::isSupported(HwAsic::Feature feature) const {
  return getAsic()->isSupported(feature);
}

std::shared_ptr<SwitchState> HwTest::getProgrammedState() const {
  return hwSwitchEnsemble_->getProgrammedState();
}

std::vector<PortID> HwTest::logicalPortIds() const {
  return hwSwitchEnsemble_->logicalPortIds();
}

std::vector<PortID> HwTest::masterLogicalPortIds() const {
  return hwSwitchEnsemble_->masterLogicalPortIds();
}

std::vector<PortID> HwTest::getAllPortsInGroup(PortID portID) const {
  return hwSwitchEnsemble_->getAllPortsInGroup(portID);
}

void HwTest::SetUp() {
  // Reset any global state being tracked in singletons
  // Each test then sets up its own state as needed.
  folly::SingletonVault::singleton()->destroyInstances();
  folly::SingletonVault::singleton()->reenableInstances();
  hwSwitchEnsemble_ = createHwEnsemble(featuresDesired());
  if (auto map = port2transceiverInfoMap()) {
    hwSwitchEnsemble_->getPlatform()->setPort2OverrideTransceiverInfo(
        map.value());
  }
  hwSwitchEnsemble_->addHwEventObserver(this);
  if (getHwSwitch()->getBootType() == BootType::WARM_BOOT) {
    // For warm boots, in wedge_agent at this point we would
    // apply the config. Which if nothing changed would be a noop
    // In HwTests we don't save and apply the config on warmboot
    // and since the warm boot expectation is that switch came
    // back in a identical state. Mark the switch state is as
    // CONFIGURED
    hwSwitchEnsemble_->switchRunStateChanged(SwitchRunState::CONFIGURED);
  }
}

void HwTest::TearDown() {
  tearDownSwitchEnsemble();
}

void HwTest::logStage(folly::StringPiece msg) {
  XLOG(INFO);
  XLOG(INFO) << kStageLogPrefix << msg;
  XLOG(INFO);
}

void HwTest::tearDownSwitchEnsemble(bool doWarmboot) {
  if (!hwSwitchEnsemble_) {
    // hwSwitchEnsemble already torn down, nothing to do
    return;
  }
  if (::testing::Test::HasFailure()) {
    collectTestFailureInfo();
    if (FLAGS_setup_thrift_on_failure) {
      hwSwitchEnsemble_->ensureThrift();
    }
  }
  hwSwitchEnsemble_->removeHwEventObserver(this);
  if (doWarmboot) {
    hwSwitchEnsemble_->gracefulExit();
    // Leak HwSwitchEnsemble for warmboot, so that
    // we don't run destructors and unprogram h/w. We are
    // going to exit the process anyways.
    // TODO - use SdkBlackholer once we have these
    // SDK exit calls covered.
    __attribute__((unused)) auto leakedHwEnsemble = hwSwitchEnsemble_.release();
#ifndef IS_OSS
#if __has_feature(address_sanitizer)
    __lsan_ignore_object(leakedHwEnsemble);
#endif
#endif
  }
  hwSwitchEnsemble_.reset();
}

std::shared_ptr<SwitchState> HwTest::applyNewConfig(
    const cfg::SwitchConfig& config) {
  auto newState =
      applyThriftConfig(getProgrammedState(), &config, getPlatform());
  return newState ? applyNewState(newState) : getProgrammedState();
}

std::shared_ptr<SwitchState> HwTest::applyNewState(
    std::shared_ptr<SwitchState> newState) {
  if (!newState) {
    return hwSwitchEnsemble_->getProgrammedState();
  }
  auto programmedState = hwSwitchEnsemble_->applyNewState(newState);
  return programmedState;
}

HwPortStats HwTest::getLatestPortStats(PortID port) {
  return getLatestPortStats(std::vector<PortID>{port})[port];
}
std::map<PortID, HwPortStats> HwTest::getLatestPortStats(
    const std::vector<PortID>& ports) {
  return hwSwitchEnsemble_->getLatestPortStats(ports);
}

std::optional<std::map<PortID, TransceiverInfo>>
HwTest::port2transceiverInfoMap() const {
  std::map<PortID, TransceiverInfo> result{};
  for (auto port : masterLogicalPortIds()) {
    result.emplace(port, utility::getTransceiverInfo(port));
  }
  return result;
}

} // namespace facebook::fboss
