// Objective-C API for talking to ClashKit/clash Go package.
//   gobind -lang=objc ClashKit/clash
//
// File is generated by gobind. Do not edit.

#ifndef __Clash_H__
#define __Clash_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"


@class ClashCPUInfo;
@protocol ClashClient;
@class ClashClient;

@protocol ClashClient <NSObject>
- (void)log:(NSString* _Nullable)level message:(NSString* _Nullable)message;
- (void)traffic:(int64_t)up down:(int64_t)down;
@end

@interface ClashCPUInfo : NSObject <goSeqRefInterface> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull modelName;
@property (nonatomic) long cores;
@end

// skipped function GetCPUInfo with unsupported parameter or return types


FOUNDATION_EXPORT NSData* _Nullable ClashGetConfigGeneral(void);

FOUNDATION_EXPORT BOOL ClashPatchSelector(NSData* _Nullable data);

FOUNDATION_EXPORT void ClashSetup(NSString* _Nullable homeDir, NSString* _Nullable config, id<ClashClient> _Nullable c);

@class ClashClient;

@interface ClashClient : NSObject <goSeqRefInterface, ClashClient> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)log:(NSString* _Nullable)level message:(NSString* _Nullable)message;
- (void)traffic:(int64_t)up down:(int64_t)down;
@end

#endif
