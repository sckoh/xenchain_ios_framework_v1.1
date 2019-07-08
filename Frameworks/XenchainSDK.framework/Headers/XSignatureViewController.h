//
//  XSignatureViewController.h
//  XenchainSDK
//
//  Created by Jovial  on 24/6/2019.
//  Copyright © 2019 Xenchain. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "XenchainProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Overlay ViewController that will be used as overlay for the Signature ViewController.
 
 @discussion This class is used to create an UI Overlay for the Signature ViewController.
 
 @warning This class needs to be extended as it is used as an overlay for the ViewController UI. Failure to do so will results in ViewController UI having pure White Screen with no User Interaction at all.
 */
@interface XSignatureViewController : UIViewController

/**
 @brief refers to the variable that will be used to call the `XenchainSignatureCallback` protocol functions.
 */
@property (nonatomic, assign) id<XenchainSignatureCallback> delegate;

/**
 @brief refers to the variable that will be used to determine the width of the signature stroke. Value must be in Float Datatype format.
 */
@property (nonatomic, assign) NSNumber *signatureStrokeWidth;

/**
 @brief Initiate the Signature View.
 
 @discussion This function is used to initiate the Signature Capture feature.
 
 @param inputView The `UIView` that will be used as a container to housed the Signature Capture view.
 
 @warning This function is required to be called in `viewDidAppear` in order to provide Signature Capture Functionality.
 */
-(void) initSignatureView:(UIView *)inputView;

/**
 @brief Clear Signature View's Content Function.
 
 @discussion Call this function to clear the Content of the Signature View.
 
 @pre Requires `initSignatureView` to be executed.
 */
-(void) clearSignature;

/**
 @brief Process the Signature Function.
 
 @discussion Call this function to submit the Signature for Processing.
 
 @warning The app is required to be responsible for providing the Terms & Conditions before proceeding to execute this function.
 
 @pre Requires `initSignatureView` to be executed.
 */
-(void) submitSignature;

@end

NS_ASSUME_NONNULL_END
