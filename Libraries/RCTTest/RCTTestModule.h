/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <UIKit/UIKit.h>

#import "RCTBridgeModule.h"
#import "RCTDefines.h"

@class FBSnapshotTestController;

@interface RCTTestModule : NSObject <RCTBridgeModule>

/**
 * The snapshot test controller for this module.
 */
@property (nonatomic, weak) FBSnapshotTestController *controller;

/**
 * This is the view to be snapshotted.
 */
@property (nonatomic, weak) UIView *view;

/**
 * This is used to give meaningful names to snapshot image files.
 */
@property (nonatomic, assign) SEL testSelector;

/**
 * This is typically polled while running the runloop until true.
 */
@property (nonatomic, readonly, getter=isDone) BOOL done;

@end
