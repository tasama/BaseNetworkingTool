//
//  CommonBaseRequest.h
//  MyNetworkDemo
//
//  Created by 阮皓 on 2018/4/17.
//  Copyright © 2018年 阮皓. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CommonRequestCallBack.h"

///< HTTP Request method.
typedef NS_ENUM(NSInteger, MTRequestMethod) {
    MTRequestMethodGET = 0,
    MTRequestMethodPOST
};

///< Request serializer type.
typedef NS_ENUM(NSInteger, MTRequestSerializerType) {
    MTRequestSerializerTypeHTTP = 0,
    MTRequestSerializerTypeJSON
};

///< Response serializer type, which determines response serialization process and
///  the type of `responseObject`.
typedef NS_ENUM(NSInteger, MTResponseSerializerType) {
    MTResponseSerializerTypeHTTP = 0, ///< NSData
    MTResponseSerializerTypeJSON, ///< JSON
    MTResponseSerializerTypeXMLParser ///< NSXMLParser
};

@interface CommonBaseRequest : NSObject

@property (nonatomic, assign) BOOL showHUD;

@property (nonatomic, weak) id<CommonBaseRequestDelegate> delegate;

@property (nonatomic, copy) AFConstructingBodyBlock constructingBodyBlock;
@property (nonatomic, copy) AFURLSessionTaskProgressBlock resumableDownloadProgressBlock;
@property (nonatomic, copy) AFURLSessionTaskProgressBlock uploadProgress;

@property (nonatomic, copy) CommonRequestSuccessBlock successBlock;
@property (nonatomic, copy) CommonRequestFailureBlock failureBlock;

- (instancetype)initWithSuccessBlock:(CommonRequestSuccessBlock)successBlock
                        failureBlock:(CommonRequestFailureBlock)failureBlock;
+ (instancetype)requestWithSuccessBlock:(CommonRequestSuccessBlock)successBlock
                           failureBlock:(CommonRequestFailureBlock)failureBlock;
- (void)startCompletionBlockWithSuccess:(CommonRequestSuccessBlock)success
                                failure:(CommonRequestFailureBlock)failure;


/**
 带进度的图片上传
 
 @param success 成功回调
 @param failure 失败回调
 @param uploadProgress 进度回调
 */
- (void)startUploadTaskWithSuccess:(CommonRequestSuccessBlock)success
                           failure:(CommonRequestFailureBlock)failure
                    uploadProgress:(AFURLSessionTaskProgressBlock)uploadProgress;

/**
 * @brief 公共方法，开始请求，不管是使用 block 回调还是 delegate 回调，都要调用此方法
 */
- (void)startRequest;


/**
 服务器域名，只需要自定义的基类重写该方法

 @return 服务器域名
 */
- (NSString *)commonNetworkDomain;

/**
 * @brief 请求参数，即URL入参
 *
 * @warning 必须重写
 */
- (NSDictionary *)requestArguments;

/**
 * @brief 请求URL路径
 *
 * @warning 必须重写
 */
- (NSString *)requestURLPath;

/**
 * @brief 请求方式 GET or POST
 *
 * @warning 按需重写
 */
- (MTRequestMethod)requestMethod; ///< 默认 GET 请求

/**
 * @brief 请求序列类型
 *
 * @warning 按需重写
 */
- (MTRequestSerializerType)requestSerializerType;

/**
 * @brief 响应序列类型
 *
 * @warning 按需重写
 */
- (MTResponseSerializerType)responseSerializerType;

/**
 * @brief 设置请求头
 *
 * @warning 按需重写
 */
- (NSDictionary<NSString *, NSString *> *)requestHeaderFieldValueDictionary; ///< Additional HTTP request header field. HTTP 请求头配置，按需重写

/**
 处理请求返回的数据

 @param data 需要的数据
 @param resCode 后台返回的错误码（代表各种情况）
 @return 处理完成后的数据
 */
- (id)handleData:(id)data errCode:(NSInteger)resCode;

@end
