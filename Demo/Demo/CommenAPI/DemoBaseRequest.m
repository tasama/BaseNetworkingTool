//
//  DemoBaseRequest.m
//  Demo
//
//  Created by 阮皓 on 2018/4/23.
//  Copyright © 2018年 阮皓. All rights reserved.
//

#import "DemoBaseRequest.h"

@implementation DemoBaseRequest

- (instancetype)init {
    
    if (self = [super init]) {
        
        self.showHUD = YES;
    }
    return self;
}

- (NSString *)commonNetworkDomain {
    
    return @"https://api.douban.com/";
}

- (MTResponseSerializerType)responseSerializerType {
    
    return MTResponseSerializerTypeJSON;
}

@end
