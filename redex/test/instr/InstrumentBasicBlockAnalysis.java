/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

package com.facebook.redextest;

import com.facebook.proguard.annotations.DoNotStrip;
import java.util.concurrent.atomic.AtomicInteger;

public class InstrumentBasicBlockAnalysis {

  // InstrumentPass will patch.
  @DoNotStrip private static final short[] sMethodStats = new short[0];
  @DoNotStrip private static AtomicInteger sMethodCounter = new AtomicInteger(0);
  @DoNotStrip private static boolean sIsEnabled = true;

  @DoNotStrip
  public static void onMethodExit(int offset) {
    if (sIsEnabled) {
      ++sMethodStats[offset];
      if (sMethodStats[offset + 1] == 0) {
        sMethodStats[offset + 1] = (short) sMethodCounter.incrementAndGet();
      }
    }
  }

  public static void onMethodExit(int offset, short bitvec) {
    if (sIsEnabled) {
      ++sMethodStats[offset];
      if (sMethodStats[offset + 1] == 0) {
        sMethodStats[offset + 1] = (short) sMethodCounter.incrementAndGet();
      }
      sMethodStats[offset + 2] |= bitvec;
    }
  }

  @DoNotStrip
  public static void onMethodExit(int offset, short bitvec1, short bitvec2) {
    if (sIsEnabled) {
      ++sMethodStats[offset];
      if (sMethodStats[offset + 1] == 0) {
        sMethodStats[offset + 1] = (short) sMethodCounter.incrementAndGet();
      }
      sMethodStats[offset + 2] |= bitvec1;
      sMethodStats[offset + 3] |= bitvec2;
    }
  }

  @DoNotStrip
  public static void onMethodExit(int offset, short bitvec1, short bitvec2, short bitvec3) {
    if (sIsEnabled) {
      ++sMethodStats[offset];
      if (sMethodStats[offset + 1] == 0) {
        sMethodStats[offset + 1] = (short) sMethodCounter.incrementAndGet();
      }
      sMethodStats[offset + 2] |= bitvec1;
      sMethodStats[offset + 3] |= bitvec2;
      sMethodStats[offset + 4] |= bitvec3;
    }
  }

  // Epilogues to support more than 3 bit vectors.
  @DoNotStrip
  public static void onMethodExit_Epilogue(int offset, short bitvec1) {
    if (sIsEnabled) {
      sMethodStats[offset + 0] |= bitvec1;
    }
  }

  @DoNotStrip
  public static void onMethodExit_Epilogue(int offset, short bitvec1, short bitvec2) {
    if (sIsEnabled) {
      sMethodStats[offset + 0] |= bitvec1;
      sMethodStats[offset + 1] |= bitvec2;
    }
  }

  @DoNotStrip
  public static void onMethodExit_Epilogue(
      int offset, short bitvec1, short bitvec2, short bitvec3) {
    if (sIsEnabled) {
      sMethodStats[offset + 0] |= bitvec1;
      sMethodStats[offset + 1] |= bitvec2;
      sMethodStats[offset + 2] |= bitvec3;
    }
  }
}
