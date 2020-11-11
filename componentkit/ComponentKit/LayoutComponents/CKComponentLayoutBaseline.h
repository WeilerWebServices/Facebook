/*
 *  Copyright (c) 2014-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#import <Foundation/Foundation.h>

#import <ComponentKit/CKDefines.h>

#if CK_NOT_SWIFT

/**
 Set a key value pair using this in CKLayout.extra for a custom baseline. The component which uses this property should also override @{usesCustomBaseline} to return YES.
 e.g. @{kCKComponentLayoutExtraBaselineKey : 20}
 */

#ifdef __cplusplus
extern "C" {
#endif
extern NSString *const kCKComponentLayoutExtraBaselineKey;
#ifdef __cplusplus
}
#endif

#endif