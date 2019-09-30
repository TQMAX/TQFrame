//
//  InitProcess.m
//  yykj
//
//  Created by FRJ on 2019/9/16.
//  Copyright © 2019 yykj. All rights reserved.
//

#import "InitProcess.h"
#import "CYLMainRootViewController.h"

@implementation InitProcess
-(instancetype)init
{
    if (self = [super init]) {
        [self addObserver];
    }
    return self;
}

-(BOOL)startupProcessWithApplication:(UIApplication *)application andOptions:(NSDictionary *)launchOptions
{
    self.application = application;
    self.launchOptions = launchOptions;
    
    //如果程序窗口为nil，初始化为当前屏幕大小
    if (!application.delegate.window) {
        application.delegate.window = [[UIWindow alloc]initWithFrame:[UIScreen mainScreen].bounds];
    }
    
    //进入主框架界面
//    _mainFrame = [[MainFrame alloc]init];
//    application.delegate.window.rootViewController = _mainFrame;
    
//    if (!_mainTabBar) {
//        _mainTabBar = [[MainTabBarController alloc]init];
//    }
//    application.delegate.window.rootViewController = _mainTabBar.tabBarController;
    CYLMainRootViewController *rootViewController = [[CYLMainRootViewController alloc] init];
    [application.delegate.window setRootViewController:rootViewController];
    
    [application.delegate.window makeKeyAndVisible];
    
    return YES;
}

//启动前广播消息
-(void)addObserver
{
    //添加需要的消息
}

@end
