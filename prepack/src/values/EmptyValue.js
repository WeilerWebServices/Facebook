/**
 * Copyright (c) 2017-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

/* @flow strict-local */

import { UndefinedValue, Value } from "./index.js";

export default class EmptyValue extends UndefinedValue {
  getHash(): number {
    return 4523845144584502;
  }

  equals(x: Value): boolean {
    return x instanceof EmptyValue;
  }
}