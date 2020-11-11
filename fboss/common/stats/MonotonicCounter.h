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

#include <fb303/ExportedHistogramMap.h>
#include <fb303/ExportedHistogramMapImpl.h>
#include <fb303/ExportedStatMapImpl.h>
#include <folly/Range.h>

namespace facebook { namespace stats {

class MonotonicCounter {
 public:
  MonotonicCounter(folly::StringPiece, fb303::ExportType, fb303::ExportType) {}
  void updateValue(std::chrono::seconds, int64_t) {}
  void swap(MonotonicCounter& counter) {}
  int64_t get() const {
    return 0;
  }
  const std::string& getName() const {
    static const std::string kName;
    return kName;
  }
};
}}
