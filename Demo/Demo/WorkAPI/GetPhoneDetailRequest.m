//
//  GetPhoneDetailRequest.m
//  Demo
//
//  Created by 阮皓 on 2018/4/23.
//  Copyright © 2018年 阮皓. All rights reserved.
//

#import "GetPhoneDetailRequest.h"

@implementation GetPhoneDetailRequest

- (NSString *)requestURLPath {
    
    return @"v2/book/1220562";
}

- (NSDictionary *)requestArguments {
    
    return nil;
}

- (id)handleData:(id)data errCode:(NSInteger)resCode {
    
    return data;
}

@end
