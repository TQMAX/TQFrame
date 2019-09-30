//
//  CSLConfig.h
//  CitySpeedLoan
//
//  Created by lin on 16/4/7.
//  Copyright © 2016年 huaxinjinfu.com. All rights reserved.
//

#ifndef CSLConfig_h
#define CSLConfig_h



#pragma --mark network

#ifdef DEBUG
#define NetWorkAppLog(s, ... ) NSLog( @"[%@ in line %d] ===============>%@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] )
#else
#define NetWorkAppLog(s, ... )
#endif
// 自定义Log
#ifdef DEBUG

#define AppLog(...) NSLog(@"%s %d \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])

#else
#define AppLog(...)

#endif


#pragma --mark ui方面
/**
 *  设置某个View为圆角，且有边框、包括边框颜色
 *  @param View   要设置的View对象
 *  @param Radius 圆角大小
 *  @param Width  边框大小
 *  @param Color  颜色
 *  @return View
 */
#define ViewRadiusBorder(View, Radius, borderWidth, UIColor)\
[View.layer setCornerRadius:(Radius)];\
[View.layer setBorderWidth:(borderWidth)];\
[View.layer setBorderColor:[UIColor CGColor]];\
[View.layer setMasksToBounds:YES]

/**
 *  仅设置某个View为圆角
 *  @param View   要设置的View对象
 *  @param Radius 圆角度
 *  @return View
 */
#define ViewRadius(View, Radius)\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES]

// 颜色相关宏定义
#define RGB(x,y,z)      [UIColor colorWithRed:x/255.0f green:y/255.0f blue:z/255.0f alpha:1]
#define RGB_A(x)        [UIColor colorWithRed:x/255.0 green:x/255.0 blue:x/255.0 alpha:1.0]     //后缀ABC排序
#define RGB_B(x,y,z)    RGB(x,y,z)
#define RGB_C(x,y,z,a)  [UIColor colorWithRed:x/255.0 green:y/255.0 blue:z/255.0 alpha:a/1.0]   //出现顺序
#define RGB_D(x,a)      [UIColor colorWithRed:x/255.0 green:x/255.0 blue:x/255.0 alpha:a/1.0]

#define HexRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define HexRGBAlpha(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:(a)]

#define RandomColor RGB(arc4random_uniform(256), arc4random_uniform(256), arc4random_uniform(256))/**< 随机色  */
#define ClearColor      [UIColor clearColor]
#define OrangeColor     [UIColor orangeColor]
#define RedColor        [UIColor redColor]
#define WhiteColor      [UIColor whiteColor]
#define BlackColor      [UIColor blackColor]
#define GreenColor      [UIColor greenColor]
#define YellowColor     [UIColor yellowColor]
#define BlueColor       [UIColor blueColor]
#define GrayColor       [UIColor grayColor]
#define LightGrayColor  [UIColor lightGrayColor]
#define SeparatorLineOrBorderColor HexRGB(0xDDDDDD); //分割线的颜色，边框的颜色

#define SeparatorLineHeight (0.5)
#define APPdefaultBackgroundColor HexRGB(0x7ec059)//主题绿色
#define BackgroundDarkGrayColor RGB_A(228);  //较深的灰色视图背景色
#define BackgroundLightGrayColor RGB_A(241); //较浅的灰色视图背景色
#define DefaultTextCOLOR_GRAY HexRGB(0x4a4a4a) //字体 默认颜色本app黑色
#define DefaultTextCOLOR_LGRAY HexRGB(0x9b9b9b) //字体 默认浅灰颜色本app
// 字体相关宏定义
#define Font(x)  (IS_IOS_VERSION >= 9.0) ? [UIFont fontWithName:@"PingFangSC-Regular" size:x] : [UIFont systemFontOfSize:(x)]
#define FontSystem(x) [UIFont systemFontOfSize:(x)]
#define FontB(x)  [UIFont fontWithName:@"Helvetica-Light" size:x]
#define FontC(x)  [UIFont fontWithName:@"AppleGothic" size:x]
#define FontD(x)  [UIFont fontWithName:@"Arial Rounded MT Bold" size:x]
#define Semibold(x)  (IS_IOS_VERSION >= 9.0) ? [UIFont fontWithName:@"PingFangSC-Semibold" size:x] : [UIFont systemFontOfSize:(x)] 
#define FontE(x)  (IS_IOS_VERSION >= 9.0) ? [UIFont fontWithName:@"PingFangSC-Light" size:x] : [UIFont systemFontOfSize:(x)]
#define MediumFont(x) (IS_IOS_VERSION >= 9.0) ? [UIFont fontWithName:@"PingFangSC-Medium" size:x] : [UIFont systemFontOfSize:(x)]


/*
 3.5 inch == (320,480)    4s
 4   inch == (320,480 + 88) 5 5s
 4.7 inch == (320 + 55, 480 + 88 + 99) 6 7
 5.5 inch == (320 + 55 + 39,480 + 88 + 99 + 69); 6plus 7plus
 */
#define INCH35     ((SCREEN_HEIGHT == 480)? YES:NO)
#define INCH4      ((SCREEN_HEIGHT == 568)? YES:NO)
#define INCH47     ((SCREEN_HEIGHT == 667)? YES:NO)
#define INCH55     ((SCREEN_HEIGHT == 736)? YES:NO)
#define RWIDTH(X) (X)*1./375*SCREEN_WIDTH
#define RHEIGHT(Y) (Y)*1./667*SCREEN_HEIGHT
//Font size
#define SystemFontSize(size) \
INCH55 || INCH47 ? [UIFont systemFontOfSize:size] : INCH4 ? [UIFont systemFontOfSize:(size-1)] : [UIFont systemFontOfSize:(size-2)]


#define SystemBoldFontSize(size) \
INCH55 || INCH47 ? [UIFont boldSystemFontOfSize:size] : INCH4 ? [UIFont boldSystemFontOfSize:(size-1)] : [UIFont boldSystemFontOfSize:(size-2)]

#define PingFangSCFont(x)  (INCH55 || INCH47) ? Font(x) :Font(x-2) 


// 预设字体大小
#define TextSizeSmallest 10
#define TextSizeSmall 11
#define TextSizeBigSmall 12
#define TextSizeMedium 14
#define TextSizeLarge 16


// 预设尺寸
#define PaddingSmall 3
#define PaddingMedium 5
#define PaddingLarge 10
#define PaddingXLarge 15
#define PaddingXXLarge 20
#define ActionTitleBarHeight 46
#define ActionTitleButtonWidth 60

// Frame相关宏定义
#define Rect(a,b,c,d) CGRectMake(a, b, c, d)

#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height  //屏幕高
#define SCREEN_WIDTH  [UIScreen mainScreen].bounds.size.width   //屏幕宽

//获取状态栏的高度
#define getStatusHight  [[UIApplication sharedApplication] statusBarFrame].size.height
//获取导航栏+状态栏的高度
#define getRectNavHight  self.navigationController.navigationBar.frame.size.height
//获取导航栏+状态栏的高度
#define getRectNavAndStatusHight  self.navigationController.navigationBar.frame.size.height+[[UIApplication sharedApplication] statusBarFrame].size.height

/** 中英状态下键盘的高度 */
#define ENG_KEY_BOARD_H  (216.f)
#define CHN_KEY_BOARD_H  (252.f)

#pragma -mark weakSelf
#define WS(weakSelf)  __weak __typeof(&*self)weakSelf = self;

#pragma -mark 国际化
#define LocStr(key) NSLocalizedString(key,@"")

// 设备型号
#define IS_IPAD     [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad
#define IS_IPHONE   [[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone

#define SCREEN_IS4S [UIScreen mainScreen].bounds.size.height ==480
#define IS_IPHONE_4 (fabs((double)[SCREEN_HEIGHT - (double )480) < DBL_EPSILON )
#define IS_IPHONE_5 (fabs((double)[SCREEN_HEIGHT - (double )568) < DBL_EPSILON )
#define IS_IPHONE_6 (fabs((double)[SCREEN_HEIGHT - (double )667) < DBL_EPSILON )
#define IS_IPHONE_6_PLUS (fabs((double)[SCREEN_HEIGHT - (double )960) < DBL_EPSILON )
#define SCREEN_IS4S [UIScreen mainScreen].bounds.size.height ==480
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
///<----------判断是否为iphone6---------->
#define iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
///<!----------判断是否为iphone6 plus ---------->
#define iPhone6Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)

///<!----------判断是否为iphoneX ---------->
#define kDevice_Is_iPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)


///<!----------判断是否为iphoneXr ---------->
#define kDevice_Is_iPhoneXR ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) : NO)

///<!----------判断是否为iphoneXs MAX ---------->
#define kDevice_Is_iPhoneXS_MAX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) : NO)

#define IS_IPhoneX_All ([UIScreen mainScreen].bounds.size.height == 812 || [UIScreen mainScreen].bounds.size.height == 896)


// Tabbar safe bottom margin.
#define  SafeBottomMargin         (IS_IPhoneX_All ? 34.f : 0.f)

#define kStatusBarHeight [[UIApplication sharedApplication] statusBarFrame].size.height

// Status bar & navigation bar height.
#define  StatusBarAndNavigationBarHeight  (IS_IPhoneX_All ? 88.f : 64.f)


// 系统版本
#define IS_IOS_VERSION   floorf([[UIDevice currentDevice].systemVersion floatValue])
#define IS_IOS_5    floorf([[UIDevice currentDevice].systemVersion floatValue]) ==5.0 ? 1 : 0
#define IS_IOS_6    floorf([[UIDevice currentDevice].systemVersion floatValue]) ==6.0 ? 1 : 0
#define IS_IOS_7    floorf([[UIDevice currentDevice].systemVersion floatValue]) ==7.0 ? 1 : 0
#define IS_IOS_8    floorf([[UIDevice currentDevice].systemVersion floatValue]) ==8.0 ? 1 : 0
#define IS_IOS_9    floorf([[UIDevice currentDevice].systemVersion floatValue]) ==9.0 ? 1 : 0

#define IsEmpty(source) !(source&&source.length>0)
#define IsNull(source) [source isKindOfClass:[NSNull class]]
#define StringFromFloat(_x_)  [NSString stringWithFormat:@"%f",_x_]
#define ApplicationVersionKey @"ApplicationVersionKey"

#define APP_ID               @"1065759743"
#define APP_STORE_URL        @"https://itunes.apple.com/cn/app/id"APP_ID"?mt=8"
//#define APP_STORE_REVIEW_URL (IS_IOS_VERSION >= 11.0) ? @"itms-apps://itunes.apple.com/cn/app/id"APP_ID"?mt=8&action=write-review" : @"itms-apps://itunes.apple.com/WebObjects/MZStore.woa/wa/viewContentsUserReviews?id="APP_ID"&onlyLatestVersion=true&pageNumber=0&sortOrdering=1&type=Purple+Software"
#define APP_STORE_REVIEW_URL  @"itms-apps://itunes.apple.com/cn/app/"APP_ID"?mt=8&action=write-review"
#define APP_NAME    ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleName"])
#define APP_VERSION ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"])
#define APP_BUILD   ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"])
#define APP ((AppDelegate *)[UIApplication sharedApplication].delegate)
#define AppState ([[UIApplication sharedApplication] applicationState])
/**
 *  @brief Bugtags
 */
#define BUGTAGS_APP_KEY @"9aa344c187e52e47573d6798ad91d163"


#pragma --mark  通知传参

/**
 *  register & post notification 通知中心定义
 */
//add
#define ADD_OBSERVER_WITH_OBJECT(_selector, _name, _object) \
([[NSNotificationCenter defaultCenter] addObserver:self selector:_selector name:_name object:_object])
#define ADD_OBSERVER(_selector,_name) \
ADD_OBSERVER_WITH_OBJECT(_selector, _name, nil)
//post
#define POST_NOTIFICATION_WITH_OBJECT_AND_INFO(_name, _object, _info) \
([[NSNotificationCenter defaultCenter] postNotificationName:_name object:_object userInfo:(_info)])
#define POST_NOTIFICATION(_name) \
POST_NOTIFICATION_WITH_OBJECT_AND_INFO(_name, nil, nil)
#define POST_NOTIFICATION_WITH_OBJECT(_name, _object) \
POST_NOTIFICATION_WITH_OBJECT_AND_INFO(_name, _object, nil)
#define POST_NOTIFICATION_WITH_INFO(_name, _info) \
POST_NOTIFICATION_WITH_OBJECT_AND_INFO(_name, nil, _info)
//remove
#define REMOVE_OBSERVER(_name) \
([[NSNotificationCenter defaultCenter] removeObserver:self name:_name object:nil])
#define REMOVE_ALL_OBSERVERS(_self) \
([[NSNotificationCenter defaultCenter] removeObserver:_self])



#pragma --mark  存储本地
/**
 *  用来存储到本地
 *
 *  @return key
 */

//#define kUserAccount     @"kUserAccount"


/**
 *  the saving objects      存储对象
 *
 *  @param __VALUE__ V
 *  @param __KEY__   K
 *
 *  @return
 */
#define UserDefaultSetObjectForKey(__VALUE__,__KEY__) \
{\
[[NSUserDefaults standardUserDefaults] setObject:__VALUE__ forKey:__KEY__];\
[[NSUserDefaults standardUserDefaults] synchronize];\
}

/**
 *  get the saved objects       获得存储的对象
 */
#define UserDefaultObjectForKey(__KEY__)  [[NSUserDefaults standardUserDefaults] objectForKey:__KEY__]

/**
 *  delete objects      删除对象
 */
#define UserDefaultRemoveObjectForKey(__KEY__) \
{\
[[NSUserDefaults standardUserDefaults] removeObjectForKey:__KEY__];\
[[NSUserDefaults standardUserDefaults] synchronize];\
}

#define PLIST_TICKET_INFO_EDIT [NSHomeDirectory() stringByAppendingString:@"/Documents/data.plist"] //edit the plist

#define TableViewCellDequeueInit(__INDETIFIER__) [tableView dequeueReusableCellWithIdentifier:(__INDETIFIER__)];

#define TableViewCellDequeue(__CELL__,__CELLCLASS__,__INDETIFIER__) \
{\
if (__CELL__ == nil) {\
__CELL__ = [[__CELLCLASS__ alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:__INDETIFIER__];\
}\
}

#endif /* CSLConfig_h */
