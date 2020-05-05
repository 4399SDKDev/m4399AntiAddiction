//
//  AASManager.h
//  m4399AntiAddiction
//
//  Created by zhengxu on 2020/4/13.
//

#import <Foundation/Foundation.h>

@interface AASUserInfo : NSObject

@property (nonatomic,strong)NSString *uid;
@property (nonatomic,strong)NSString *accessToken;

/// 是否第一次在本设备登录
@property (nonatomic,strong)NSString *isFirstLogin;

@end

NS_ASSUME_NONNULL_BEGIN
@interface AASManagerOption : NSObject

/// 控制是否调试模式（控制是否输出日志等功能）
@property (nonatomic,assign)BOOL debugMode;

/// 默认配置
+(AASManagerOption *)defaultOption;

@end

@interface AASManager : NSObject

/// 配置选项
@property (nonatomic,strong,readonly)AASManagerOption *option;


/// 防沉迷Manager单例
+ (AASManager *)shared;





/// 配置对象
/// @param option 配置对象，默认为[AASManagerOption defaultOption]
- (void)configWithOption:(AASManagerOption *)option;


- (void)loginWithUid:(NSString *)uid accessToken:(NSString *)accessToken;




@end


@interface TimerManager : NSObject

- (void)start:(NSString *)token;

- (void)stop;

- (void)reStart:(NSString *)newToken;

@end

@implementation TimerManager



@end



NS_ASSUME_NONNULL_END
