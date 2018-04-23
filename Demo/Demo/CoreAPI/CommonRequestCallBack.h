//
//  CommonRequestCallBack.h
//  MyNetworkDemo
//
//  Created by 阮皓 on 2018/4/17.
//  Copyright © 2018年 阮皓. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Availability.h>

@class CommonBaseRequest;
@protocol AFMultipartFormData;

typedef void(^AFConstructingBodyBlock)(id<AFMultipartFormData> data);
typedef void(^AFURLSessionTaskProgressBlock)(NSProgress *progress);


/*!
 *   AFN 请求封装的Block回调
 */
typedef void(^CommonRequestSuccessBlock)(NSInteger errCode, id responseDict, id model);
typedef void(^CommonRequestFailureBlock)(NSError *error);

@protocol CommonBaseRequestDelegate <NSObject>

@optional
/**
 *   请求结束
 *   @param returnData 返回的数据
 */
- (void)requestDidFinishLoadingWithData:(id)returnData errCode:(NSInteger)errCode;

/**
 *   请求失败
 *   @param error 失败的 error
 */
- (void)requestDidFailWithError:(NSError *)error;

/**
 *   网络请求项即将被移除掉
 *   @param item 网络请求项
 */
- (void)requestWillDealloc:(CommonBaseRequest *)item;

@end

