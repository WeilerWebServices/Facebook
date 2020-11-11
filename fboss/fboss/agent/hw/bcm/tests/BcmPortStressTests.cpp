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
#include "fboss/agent/state/Port.h"
#include "fboss/agent/state/SwitchState.h"

#include "fboss/agent/hw/bcm/BcmPort.h"
#include "fboss/agent/hw/bcm/BcmPortTable.h"
#include "fboss/agent/hw/bcm/BcmSwitch.h"
#include "fboss/agent/hw/test/ConfigFactory.h"
#include "fboss/agent/hw/test/HwLinkStateDependentTest.h"

#include <string>

using std::make_shared;
using std::shared_ptr;
using std::string;

namespace facebook::fboss {

class BcmPortStressTest : public HwLinkStateDependentTest {
 protected:
  cfg::SwitchConfig initialConfig() const override {
    return utility::onePortPerVlanConfig(getHwSwitch(), masterLogicalPortIds());
  }
};

TEST_F(BcmPortStressTest, statEnableLoop) {
  auto setup = [=]() { applyNewConfig(initialConfig()); };

  auto verify = [=]() {
    auto portTable = static_cast<BcmSwitch*>(getHwSwitch())->getPortTable();
    for (auto i = 0; i < 500; ++i) {
      for (const auto& port : *getProgrammedState()->getPorts()) {
        if (port->isEnabled()) {
          portTable->getBcmPortIf(port->getID())->enableStatCollection(port);
        }
      }
    }
  };
  verifyAcrossWarmBoots(setup, verify);
}

} // namespace facebook::fboss
