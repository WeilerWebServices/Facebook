/*
 *  Copyright (c) 2004-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#include "fboss/agent/platforms/wedge/WedgePlatformInit.h"

#include <memory>

#include "fboss/agent/AgentConfig.h"
#include "fboss/agent/Platform.h"
#include "fboss/agent/platforms/common/PlatformProductInfo.h"
#include "fboss/agent/platforms/wedge/WedgePlatform.h"
#include "fboss/agent/platforms/wedge/galaxy/GalaxyFCPlatform.h"
#include "fboss/agent/platforms/wedge/galaxy/GalaxyLCPlatform.h"
#include "fboss/agent/platforms/wedge/wedge100/Wedge100Platform.h"
#include "fboss/agent/platforms/wedge/wedge40/FakeWedge40Platform.h"
#include "fboss/agent/platforms/wedge/wedge40/Wedge40Platform.h"

namespace facebook::fboss {

std::unique_ptr<WedgePlatform> createWedgePlatform() {
  auto productInfo =
      std::make_unique<PlatformProductInfo>(FLAGS_fruid_filepath);
  productInfo->initialize();

  auto mode = productInfo->getMode();
  if (mode == PlatformMode::WEDGE) {
    return std::make_unique<Wedge40Platform>(std::move(productInfo));
  } else if (mode == PlatformMode::WEDGE100) {
    return std::make_unique<Wedge100Platform>(std::move(productInfo));
  } else if (mode == PlatformMode::GALAXY_LC) {
    return std::make_unique<GalaxyLCPlatform>(std::move(productInfo));
  } else if (mode == PlatformMode::GALAXY_FC) {
    return std::make_unique<GalaxyFCPlatform>(std::move(productInfo));
  } else if (mode == PlatformMode::FAKE_WEDGE40) {
    return std::make_unique<FakeWedge40Platform>(std::move(productInfo));
  }

  // mode is neither of the offical platforms above, consider it as a Facebook
  // dev platform
  return createFBWedgePlatform(std::move(productInfo));
}

std::unique_ptr<Platform> initWedgePlatform(
    std::unique_ptr<AgentConfig> config,
    uint32_t hwFeaturesDesired) {
  auto platform = createWedgePlatform();
  platform->init(std::move(config), hwFeaturesDesired);
  return std::move(platform);
}

} // namespace facebook::fboss
