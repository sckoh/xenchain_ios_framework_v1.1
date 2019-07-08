//
//  XBarcodeViewController.h
//  XenchainSDK
//
//  Created by Jovial  on 14/6/2019.
//  Copyright © 2019 Xenchain. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

#import "XenchainProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Overlay ViewController that will be used as overlay for the Barcode Camera UI.
 
 @discussion This class is used to create an UI Overlay for the Camera.
 
 @warning This class needs to be extended as it is used as an overlay for the Camera UI. Failure to do so will results in Camera UI having pure Camera Screen with no User Interaction at all.
 */
@interface XBarcodeViewController : UIViewController<AVCaptureMetadataOutputObjectsDelegate>

/**
 @brief refers to the variable that will be used to call the `XenchainBarcodeCallback` protocol functions.
 */
@property (nonatomic, assign) id<XenchainBarcodeCallback> delegate;

@end

NS_ASSUME_NONNULL_END
