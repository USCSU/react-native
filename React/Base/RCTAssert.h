/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

#import "RCTDefines.h"

/**
 * The default error domain to be used for React errors.
 */
extern NSString *const RCTErrorDomain;

/**
 * A block signature to be used for custom assertion handling.
 */
typedef void (^RCTAssertFunction)(
  BOOL condition,
  NSString *fileName,
  NSNumber *lineNumber,
  NSString *function,
  NSString *message
);

/**
 * Private logging function - ignore this.
 */
RCT_EXTERN void _RCTAssertFormat(
  BOOL, const char *, int, const char *, NSString *, ...) NS_FORMAT_FUNCTION(5,6);

/**
 * This is the main assert macro that you should use.
 */
#define RCTAssert(condition, ...) do { BOOL pass = ((condition) != 0); \
if (RCT_NSASSERT && !pass) { [[NSAssertionHandler currentHandler] handleFailureInFunction:@(__func__) \
file:@(__FILE__) lineNumber:__LINE__ description:__VA_ARGS__]; } \
_RCTAssertFormat(pass, __FILE__, __LINE__, __func__, __VA_ARGS__); \
} while (false)

/**
 * Convenience macro for asserting that we're running on main thread.
 */
#define RCTAssertMainThread() RCTAssert([NSThread isMainThread], \
@"This function must be called on the main thread");

/**
 * These methods get and set the current assert function called by the RCTAssert
 * macros. You can use these to replace the standard behavior with custom log
 * functionality.
 */
RCT_EXTERN void RCTSetAssertFunction(RCTAssertFunction assertFunction);
RCT_EXTERN RCTAssertFunction RCTGetAssertFunction(void);

/**
 * This appends additional code to the existing assert function, without
 * replacing the existing functionality. Useful if you just want to forward
 * assert info to an extra service without changing the default behavior.
 */
RCT_EXTERN void RCTAddAssertFunction(RCTAssertFunction assertFunction);
