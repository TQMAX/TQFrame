

#import "HTTPTool.h"

#define kDCUserDefaultsCookie @"kDCUserDefaultsCookie"/**< 存到本地的cookie 因为服务器需要*/


@implementation HTTPTool

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
{
    
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.responseSerializer.acceptableContentTypes = [NSSet setWithObjects:@"application/json",@"text/json", @"text/plain", @"text/html", nil];
    [manager.requestSerializer setValue:[self getSystemVersion] forHTTPHeaderField:@"Client-Version"];
    [manager.requestSerializer setValue:appTag forHTTPHeaderField:@"User-Agent"];
    
    if (![url containsString:BaseURL]) {
        url =[NSString stringWithFormat:@"%@%@",BaseURL,url];
    }
    
    if (isPost) {
        [manager POST:url parameters:params progress:^(NSProgress * _Nonnull uploadProgress) {
            //数据请求的进度
        } success:^(NSURLSessionDataTask * _Nonnull task, id _Nullable responseObject) {
            if ([[NSString stringWithFormat:@"%@", [responseObject valueForKey:@"code"]] isEqualToString: @"200"]) {
                success(responseObject);
            }else{
                failure(responseObject,[responseObject valueForKey:@"msg"]);
            }
        } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
            failure(error,@"");
        }];
    }else{
        [manager GET:url parameters:params progress:nil success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
            NSLog(@"success--%@--%@",[responseObject class],responseObject);
            if ([[NSString stringWithFormat:@"%@", [responseObject valueForKey:@"code"]] isEqualToString: @"200"]) {
                success(responseObject);
            }else{
                failure(responseObject,[responseObject valueForKey:@"msg"]);
            }
        } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
            failure(error,@"");
        }];
    }
    
}


/**
 *  @brief 保存登录Cookie
 */
+ (void)saveLoginCookie
{
    AppLog(@"===============>保存Cookie到本地<===============");
    // 获取Cookie
    NSArray *allCookies = [NSHTTPCookieStorage sharedHTTPCookieStorage].cookies;
    
    for (NSHTTPCookie *cookie in allCookies) {//打印Cookie
        AppLog(@"%@", cookie);
        if ([cookie.name isEqualToString:@"PHPSESSID"]) {
            NSString  *valueString = cookie.value;
            NSUserDefaults *saveDef = [NSUserDefaults standardUserDefaults];
            [saveDef setValue:valueString forKey:@"PHPSESSID"];
            [saveDef synchronize];
        }
    }
    
    /*
     * 把cookie进行归档并转换为NSData类型
     * 注意：cookie不能直接转换为NSData类型，否则会引起崩溃。
     * 所以先进行归档处理，再转换为Data
     */
    NSData *cookiesData = [NSKeyedArchiver archivedDataWithRootObject:allCookies requiringSecureCoding:YES error:nil];
    
    // 存储归档后的Cookies
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    [defaults setObject:cookiesData forKey:kDCUserDefaultsCookie];
    [defaults synchronize];
}

/**
 *  @brief 设置Cookie(通过从本地存储的数据设置Cookie)
 */
+ (void)setCookie
{
    AppLog(@"===============>通过从本地存储的数据设置Cookie<===============");
    
    // 取出本地Cookies
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSArray *cookies = [NSKeyedUnarchiver unarchivedObjectOfClass:self fromData:[defaults objectForKey:kDCUserDefaultsCookie] error:nil];
    
    if (cookies) {
        AppLog(@"本地存有Cookie");
        
        // 设置Cookie
        NSHTTPCookieStorage *cookieStorage = [NSHTTPCookieStorage sharedHTTPCookieStorage];
        for (NSHTTPCookie *cookie in cookies) {
            [cookieStorage setCookie:cookie];
        }
    } else {
        AppLog(@"本地没存有Cookie");
    }
    
    // 打印Cookie, 检测是否成功设置了Cookie
    NSArray *tempCookies = [NSHTTPCookieStorage sharedHTTPCookieStorage].cookies;
    for (NSHTTPCookie *cookie in tempCookies) {
        AppLog(@"cookie：%@", cookie);
    }
}

/**
 *  @brief 删除Cookie(注销、切换帐号时调用）
 */
+ (void)deleteCookie
{
    AppLog(@"===============>删除Cookie<===============");
    
    // 读取Cookie
    NSHTTPCookieStorage *cookieStorage = [NSHTTPCookieStorage sharedHTTPCookieStorage];
    NSArray *cookies = cookieStorage.cookies;
    
    // 删除Cookie
    for (NSHTTPCookie *cookie in cookies) {
        [cookieStorage deleteCookie:cookie];
    }
    
    // 删除本地存储的Cookie
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    [defaults removeObjectForKey:kDCUserDefaultsCookie];
    [defaults removeObjectForKey:@"PHPSESSID"];
    [defaults synchronize];
    
    // 打印Cookie, 检测是否已经删除
    NSArray *tempCookies = [NSHTTPCookieStorage sharedHTTPCookieStorage].cookies;
    for (NSHTTPCookie *cookie in tempCookies) {
        AppLog(@"cookie：\n%@", cookie);
    }
}


//获取当前设备中应用的版本号
+ (NSString *)getSystemVersion {
    NSDictionary *infoDic = [[NSBundle mainBundle] infoDictionary];
    NSString *currentVersion = [infoDic objectForKey:@"CFBundleShortVersionString"];
    return currentVersion;
}
@end
