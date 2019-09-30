//
//  InitProcess.h
//  yykj
//
//  Created by FRJ on 2019/9/16.
//  Copyright © 2019 yykj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MainTabBarController.h"

NS_ASSUME_NONNULL_BEGIN

@interface InitProcess : NSObject

@property (nonatomic,strong)UIApplication *application;
@property (nonatomic,strong)NSDictionary *launchOptions;

//主框架界面
@property (nonatomic,strong)MainTabBarController *mainTabBar;

//启动
-(BOOL)startupProcessWithApplication:(UIApplication*)application andOptions:(NSDictionary*)launchOptions;

@end

NS_ASSUME_NONNULL_END

