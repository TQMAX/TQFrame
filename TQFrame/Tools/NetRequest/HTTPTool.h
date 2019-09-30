
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^_completionBlock)(id result);
typedef void(^_failureBlock)(NSError *error,NSString *msg);

/**
 *  当前app系统
 */
#define appTag @"ios"


@interface HTTPTool : NSObject
/**
 综合有无参缓存接口
 
 @param url    url
 @param params    参数字典params
 @param isPost    默认get
 @param flag    用于缓存标记flag
 @param success success description
 @param failure failure description
 
 */
+ (void)networkWithTarget:(UIViewController*)target andURL:(NSString *)url params:(NSMutableDictionary *)params isPost:(BOOL )isPost flag:(NSString *)flag cache:(BOOL )cache Success:(_completionBlock)success failure:(_failureBlock)failure;

/**
 *  @brief 保存登录Cookie
 */
+ (void)saveLoginCookie;

/**
 *  @brief 设置Cookie(通过从本地存储的数据设置Cookie)
 */
+ (void)setCookie;

/**
 *  @brief 删除Cookie(注销、切换帐号时调用）
 */
+ (void)deleteCookie;

/**
 获取本地版本号
 
 @return 返回本地版本号str
 */
+ (NSString *)getSystemVersion;

@end

NS_ASSUME_NONNULL_END
