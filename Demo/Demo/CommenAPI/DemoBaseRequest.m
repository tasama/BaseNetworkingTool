//
//  DemoBaseRequest.m
//  Demo
//
//  Created by 阮皓 on 2018/4/23.
//  Copyright © 2018年 阮皓. All rights reserved.
//

#import "DemoBaseRequest.h"

@implementation DemoBaseRequest

//http://tcc.taobao.com/cc/json/mobile_tel_segment.htm?tel=手机号
- (NSString *)commonNetworkDomain {
    
    return @"https://api.douban.com/";
}

- (MTResponseSerializerType)responseSerializerType {
    
    return MTResponseSerializerTypeJSON;
}

@end
