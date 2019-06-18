//
//  NSObject+XenchainSDK.h
//  XenchainCustomSDK
//
//  Created by Jovial  on 10/2/2019.
//  Copyright © 2019 Xenchain. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CardConfig.h"
#import "XenchainProtocol.h"
#import "XScannerViewController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Main Class of the XenchainSDK.
 
 @discussion Responsible for providing client project access to Xenchain Features.
 
 @note For Debug Information during the execution of the SDK, please refer to the printed log on XCode Debug Window. The Debug Information will usually opened with *Xenchain Log:* text followed with the description of the Debug.
 */
@interface XenchainSDK: NSObject

/**
 @brief Refers to the Scanning Sound for ID Scanner.
 
 @discussion Gets the Scanning Sound that will be used for ID scanning.
 
 @note Default value will be used if no Scanning Sound is being set.
 */
+(NSString *) scanningSound;
/**
 @brief Refers to the Scanning Sound for ID Scanner.
 
 @discussion Sets the Scanning Sound that will be used for ID scanning.
 
 @note Default value will be used if no Scanning Sound is being set.
 */
+(void) setScanningSound:(NSString *)value;

/**
 @brief Refers to the Loading logo of the Loading Screen during the Scanner/Face Match Processing.
 
 @discussion Gets the loading Logo image for the Loading screen during the scanning and face match process.
 
 @note Default value will be used if no Loading Image is being set.
 */
+(UIImage *) loadingLogo;
/**
 @brief Refers to the Loading logo of the Loading Screen during the Scanner/Face Match Processing.
 
 @discussion Sets the Loading Logo image for the Loading screen during the scanning and face match process.
 
 @note Default value will be used if no Loading Image is being set.
 */
+(void) setLoadingLogo:(UIImage *)value;

/**
 @brief Refers to the  Loading Screen during the Scanner/Face Match Processing.
 
 @discussion Gets the view for the Loading screen during the scanning and face match process.
 
 @note Default value will be used if no Loading View is being set.
 */
+(UIView *) loadingView;
/**
 @brief Refers to the  Loading Screen during the Scanner/Face Match Processing.
 
 @discussion Sets the view for the Loading screen during the scanning and face match process.
 
 @note Default value will be used if no Loading View is being set.
 */
+(void) setLoadingView:(UIView *)value;

/**
 @brief Initialise the XenchainSDK. This include checking the validity of API Key and what features can be accessed by the API Key.
 
 @param apiKey Variable used for Initialize the XenchainSDK. Depending on the Access Granted, other features will be initialized as well.
 @param apiURL The API URL that will be used to access the XenchainSDK features. Depending on the requirement, this could be Xenchain cloud server or on-premise hosted server. Default value is `false`.
 @param completionHandler Completion Block or Completion Handler used for returning the results of Initialization. Refer to `XenchainSDKCallback` Protocol for further information.
 
 @discussion Please ensure that this function is executed and the response from completion handler is returned before proceeding to other features of the SDK.
 */
+(void) InitSDK:(NSString * _Nonnull)apiKey apiURL:(NSString *)apiURL onPremSaveData:(bool)onPremSaveData completionHandler:(id<XenchainSDKCallback> _Nonnull)completionHandler;

/**
 @brief Setup and provide View Controller of the ID Card Scanner.

 @param scanConfig This variable carries the configuration of the Card/Passport that will be scanned. Refer to the `ScanConfig` class type for more information.
 @param inputController The UIViewController that is used to present the extended class of the `XScannerViewController`.
 @param extendedController The extended class of `XScannerViewController` that is used as UI Overlay for the Camera.
 @param completionHandler Completion Block or Completion Handler used for returning the results of ID Scanning. Refer to `XenchainScannerCallback` Protocol for further information.
 
 @pre Requires `InitSDK` function to be executed with callbacks return with success value.
 
 @post Requires `CompleteScanDeployment` to be executed. Otherwise, the SDK will charged for every scanning.
 
 @warning Developers are required to call the `CompleteScanDeployment` function. Otherwise for every scanning that is being done, the SDK will charged the scan.
 */
+(void) DeployScanner:(CardConfig * _Nonnull)scanConfig inputController:(UIViewController * _Nonnull)inputController extendedController:(XScannerViewController * _Nonnull)extendedController completionHandler:(id<XenchainScannerCallback> _Nonnull)completionHandler;

/**
 @brief Delegate function that must be called when scanning is completed.
 
 @param onBoardingID Refers to the onBoardingID passed from the `XenchainScannerCallback` protocol. The `onBoardingID` is to ensure that the SDK consider this particular transaction as fully consume for ID Scanning.
 @param cardFrontReferenceID Refers to the `refFrontID` passed from the `XenchainScannerCallback` protocol.
 @param faceReferenceID Refers to the `refFace` passed from the `XenchainScannerCallback` protocol.
 @param cardBackReferenceID Refers to the `refBackID` passed from the `XenchainScannerCallback` protocol.
 @param cardResult Refers to the `cardResult` passed from the `XenchainScannerCallback` protocol.
 @param completionHandler Completion Block or Completion Handler. Refer to `XenchainScannerCallback` Protocol for further information.
 
 @pre Requires `DeployScanner` to be executed with callbacks return.
 
 @warning Developers are required to call the `CompleteScanDeployment` function. Otherwise for every scanning that is being done, the SDK will charged the scan.
 */
+(void) CompleteScanDeployment:(NSString * _Nonnull)onBoardingID cardFrontReferenceID:(NSString * _Nonnull)cardFrontReferenceID faceReferenceID:(NSString * _Nonnull)faceReferenceID cardBackReferenceID:(NSString * _Nonnull)cardBackReferenceID cardResult:(XCardResult * _Nonnull)cardResult completionHandler:(id<XenchainScannerCallback> _Nonnull)completionHandler;

//+(void) DetectFaceImageFrom:(UIImage * _Nonnull)inputImage completionHandler:(id<XenchainDetectionCallback> _Nonnull)completionHandler;

/**
 @brief Setup and provide Users with Face Match Features.
 
 @param viewController the UIViewController that is used to present the Camera View Controller.
 @param onBoardingID Refers to the onBoardingID passed from the `XenchainScannerCallback` protocol. The `onBoardingID` is to ensure that the Face Match refers to this particular **Onboarding Transaction ID**.
 @param imageRef Refers to the `refFace` param value taken from `XenchainScannerCallback` protocol. This variable will be used for Face Matching purpose with the Face Image captured during the `DeployFaceMatch` process.
 @param completionHandler Completion Block or Completion Handler. Refer to `XenchainFaceCallback` Protocol for further information.
 
 @discussion This function includes Face Motion Checking, in which, the user will be asked to perform 2 motion, Blink Eyes & Smilling. For each motion, the camera will capture the Face. In this case, each captured Face will be compared against the `imageRef`.
 
 @pre Requires `DeployScanner` to be executed with callbacks return.
 
 @warning Please ensure that the `viewController` param is passed using current presented View Controller. Otherwise, the Camera View Controller will not shown.
 */
+(void) DeployFaceMatch:(UIViewController * _Nonnull)viewController onBoardingID:(NSString * _Nonnull)onBoardingID imageRef:(NSString * _Nonnull)imageRef completionHandler:(id<XenchainFaceCallback> _Nonnull)completionHandler;

/**
 @brief Setup and provide Users with Face Match Features.
 
 @param onBoardingID Refers to the onBoardingID passed from the `XenchainScannerCallback` protocol. The `onBoardingID` is to ensure that the Face Match refers to this particular **Onboarding Transaction ID**.
 @param cropImageRef Refers to the `refFace` param value taken from `XenchainScannerCallback` protocol. This variable will be used for Face Matching purpose with the `faceImage` variable.
 @param faceImage The image that will be used for comparison against `cropImageRef`.
 @param completionHandler Completion Block or Completion Handler. Refer to `XenchainFaceCallback` Protocol for further information.
 
 @discussion This function is used in situation where Face Motion is not required. It will compare the `faceImage` against the `cropImageRef`.
 
 @pre Requires `DeployScanner` to be executed with callbacks return.
 */
+(void) ProcessFaceMatch:(NSString * _Nonnull)onBoardingID cropImageRef:(NSString * _Nonnull)cropImageRef faceImage:(UIImage * _Nonnull)faceImage completionHandler:(id<XenchainFaceCallback> _Nonnull)completionHandler;

+(void) DeployBarcodeScanner:(NSString * _Nonnull)onBoardingID completionHandler:(id<XenchainBarcodeCallback> _Nonnull)completionHandler;

+(void) DeployHologramChecking:(UIViewController * _Nonnull)viewController;

@end

NS_ASSUME_NONNULL_END
