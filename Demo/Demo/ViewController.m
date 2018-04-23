//
//  ViewController.m
//  Demo
//
//  Created by 阮皓 on 2018/4/23.
//  Copyright © 2018年 阮皓. All rights reserved.
//

#import "ViewController.h"
#import "GetPhoneDetailRequest.h"

@interface ViewController () <CommonBaseRequestDelegate>

@property (weak, nonatomic) IBOutlet UITextField *textField;

@property (weak, nonatomic) IBOutlet UIButton *getNetBtn;

@property (weak, nonatomic) IBOutlet UITextView *outPutTextView;

@property (nonatomic, strong) GetPhoneDetailRequest *request;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
  
    
}


#pragma mark - ********* EVENT *********

- (IBAction)getRequest:(UIButton *)sender {
    
    NSString *phoneNum = self.textField.text;
    self.request.phoneNum = phoneNum;
    [self.request startRequest];
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    
    [self.textField endEditing:YES];
}

#pragma mark - ********* Lazy Load *********

- (GetPhoneDetailRequest *)request {
    
    if (!_request) {
        
        _request = [[GetPhoneDetailRequest alloc] init];
        _request.delegate = self;
        _request.showHUD = YES;
    }
    return _request;
}

#pragma mark - ********* Networking *********

- (void)requestDidFinishLoadingWithData:(id)returnData errCode:(NSInteger)errCode {
    
    
}

- (void)requestDidFailWithError:(NSError *)error {
    
    
}

@end
