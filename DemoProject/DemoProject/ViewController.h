//
//  ViewController.h
//  DemoProject
//
//  Created by Jovial  on 3/6/2019.
//  Copyright © 2019 Xendity. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <XenchainSDK/XenchainSDK.h>

@interface ViewController : UIViewController<XenchainSDKCallback, XenchainScannerCallback>

@property (weak, nonatomic) IBOutlet UITextView *resultsText;

@end

