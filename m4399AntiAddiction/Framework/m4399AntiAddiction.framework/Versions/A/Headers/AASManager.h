//
//  AASManager.h
//  m4399AntiAddiction
//
//  Created by zhengxu on 2020/4/13.
//

#import <Foundation/Foundation.h>



NS_ASSUME_NONNULL_BEGIN
@interface AASManagerOption : NSObject




/// 控制是否调试模式（控制是否输出日志等功能，上线时切勿打开）
@property (nonatomic,assign)BOOL debugMode;

/// 测试环境开关 （请在4399防沉迷SDK开发者指导下使用，上线时切勿打开）
@property (nonatomic,assign)BOOL testEnv;


/// 测试环境心跳时间间隔[秒]（上线时请勿修改该参数，默认<0时，执行服务器配置时间间隔。）
@property (nonatomic,assign)double debugHeartbeatInterval;

/// 默认配置
+(AASManagerOption *)defaultOption;

@end


/// 防沉迷SDK管理组件
@interface AASManager : NSObject

/// SDK版本
@property (nonatomic,readonly)NSString *version;
/// 配置选项
@property (nonatomic,strong,readonly)AASManagerOption *option;


/// 防沉迷Manager单例
+ (AASManager *)shared;





/// 配置对象
/// @param option 配置对象，默认为[AASManagerOption defaultOption]
/// @param gameKey 游戏Key
/// @param deviceIdentifing 设备ID，游戏方自行标识设备的唯一ID。
/// @param switchAccountHandler 切换账号回调，该回调执行时，游戏强制切换回登录界面（guestMode=YES时，重新以游客身份登录）
- (void)configWithOption:(AASManagerOption *)option GameKey:(NSString *)gameKey DeviceId:(NSString *)deviceIdentifing switchAccount:(void (^)(BOOL guestMode))switchAccountHandler;


/// 登录验证
/// @param uid 4399UID
/// @param accessToken 4399用户中心AccessToken
/// @param success 成功回调，可继续游戏
/// @param fail 异常回调，需重新登录
- (void)loginWithUid:(NSString *)uid accessToken:(NSString *)accessToken success:(void (^)(int userType))success fail:(void (^)(int code,NSString *message))fail;


/// 注销登录
- (void)logout;



/// 请求充值许可
/// @param money 充值金额（元）
/// @param mark 游戏方自定义订单号（最长32位字符串）
/// @param success 允许充值回调
/// @param fail 拒绝充值回调
-(void)prepayWithMoney:(int)money mark:(NSString *)mark success:(void (^)(NSString *orderId,int money, NSString *uid, NSString *mark))success fail:(void (^)(int code,NSString *message))fail;

@end






NS_ASSUME_NONNULL_END
