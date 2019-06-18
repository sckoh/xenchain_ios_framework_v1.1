//
//  XenchainProtocol.h
//  XenchainCustomSDK
//
//  Created by Jovial  on 8/3/2019.
//  Copyright © 2019 Xenchain. All rights reserved.
//

#ifndef XenchainProtocol_h
#define XenchainProtocol_h

#import <UIKit/UIKit.h>
#import "XCardResult.h"

/**
 @brief Scan Delegate for SDK Initialization.
 */
@protocol XenchainSDKCallback

/**
 @brief Delegate function to be called for SDK Initialization.
 
 @param status Represents whether the SDK is successfully initialize or not.
 @param message If the SDK was not able to initialize successfully, this variable will provide the general description of the issue.
 */


-(void) InitSDKStatus:(bool)status message:(NSString *)message;

@end

/**
 @brief Scan Delegate for ID Document Scanning.
 */
@protocol XenchainScannerCallback

/**
 @brief Delegate function to be called when the Scanner has process the ID Document.
 
 @param cardResult Any important attributes of the ID Document that is found during the scanning process will be returned in this parameter.
 @param onBoardingID The Overal Transaction ID for the whole Onboarding Process. The value contained in this variable will be used to track User's onboarding journeys.
 @param errorMessage If no important attributes of the ID Document was found or there is issue during the processing of ID Document attributes, this variable will provide the general description of the issue.
 
 @warning Call the `CompleteScanDeployment` function if the `deployScanner` function once the User confirm that this function returns the correct information to the App or User. Otherwise for every scanning that is being done, the SDK will charged the scan.
 
 @note It is recommended that the App stores `onBoardingID` value in the event that the App will access the `deployFaceMatch` function on later date.
 */
-(void) ScanResults:(XCardResult *)cardResult onBoardingID:(NSString *)onBoardingID errorMessage:(NSString *)errorMessage;

/**
 @brief Delegate function to be called when the Scanner has process the ID Document.
 
 @param idFaceImage If the Scanner was able to grab the Face of the ID Document, this variable will returned the Face Image. Otherwise, it will returned nil.
 @param refFace The reference ID of the Face Image which must be passed to `deployFaceMatch` function for Face Comparison.
 @param idFrontImage If the Scanner was able to grab the whole image of ID Document, this variable will returned the ID Image. Otherwise, it will returned nil.
 @param refFrontID The reference ID of the ID Document Image.
 @param idBackImage Refers to the MyKad Logo of the Back ID Image. This is for Landmark check purpose and only available to MyKad Scanning.
 @param refBackID The reference ID of the Back ID Document Image.
 @param errorMessage If the Scanner was not able to grab even the ID Document Image, this variable will provide the general description of the issue.
 
 @note It is recommended that the App stores `refFace` value in the event that the App will access the `deployFaceMatch` function on later date.
 */
-(void) ScanMetaResults:(UIImage *)idFaceImage refFace:(NSString *)refFace idFrontImage:(UIImage *)idFrontImage refFrontID:(NSString *)refFrontID idBackImage:(UIImage *)idBackImage refBackID:(NSString *)refBackID errorMessage:(NSString *)errorMessage;

/**
 @brief Delegate function to be called when the Scanner has process the Landmark of ID Document.
 
 @param landmarkScores Shows the percentage score for each landmark check.
 
 @warning Kindly note that this delegate function will only be called if `CheckLandmark` options is set to `true`. `CheckLandmark` can be setup in `CardConfig` class and it's respective child class.
 */
-(void) ScanLandmarkInformation:(NSDictionary *)landmarkScores;

/**
 @brief Delegate function to be called when the Scanner has process the ID Document.
 
 @param serviceReferenceID Billing reference is returned if all the important attributes of the ID Document are returned successfully during the scanning process.
 */
-(void) ScanServiceReferenceID:(NSString *)serviceReferenceID errorMessage:(NSString *)errorMessage;

/**
 @brief Delegate function to be called when the App called `CompleteScanDeployment`.
 
 @param status Represents whether the `CompleteScanDeployment` is successfully called or not.
 @param errorMessage If the SDK was not able to process the `CompleteScanDeployment`, this variable will provide the general description of the issue.
 */
-(void) ScanCompleteDeployment:(bool)status errorMessage:(NSString *)errorMessage;

@end

@protocol XenchainDetectionCallback

-(void) FaceDetectionResult:(UIImage *)outputImage outputRef:(NSString *)outputRef error:(NSString *)error;

@end

/**
 @brief Scan Delegate for Face Matching.
 */
@protocol XenchainFaceCallback

/**
 @brief Delegate function to be called when the Scanner has processed the Selfie Image and matched it with ID Card.
 
 @param isMatched True for Matched Face, otherwise False.
 @param percentMatched Show the percentage of how matched is the ID Card face and the Uploaded Image Face.
 @param serviceReferenceID Refers to the Service Reference/Transaction ID for this process.
 @param error Any error during the Face Match result will be passed in this variable.
 */
-(void) FaceMatchResult:(bool)isMatched percentMatched:(double)percentMatched serviceReferenceID:(NSString *)serviceReferenceID error:(NSString *)error;

/**
 @brief Delegate function to be called when the Scanner has successfully processed the Selfie Image.
 
 @param outputImage Show the image captured for Selfie.
 @param outputRef The reference ID of the image captured for Selfie.
 */
-(void) FaceMatchMetaResult:(UIImage *)outputImage outputRef:(NSString *)outputRef;

@end

/**
 @brief Scan Delegate for Barcode Scanning.
 */
@protocol XenchainBarcodeCallback

-(void) BarcodeResult:(NSString *)barcodeValue barcodeImage:(UIImage *)barcodeImage barcodeImageRef:(NSString *)barcodeImageRef error:(NSString *)error;

@end

/**
 @brief Delegate for Signature Capture.
 */

@protocol XenchainSignatureCallback

-(void) SignatureResult:(UIImage *)signatureImage signatureImageRef:(NSString *)signatureImageRef error:(NSString *)error;

@end

#endif /* XenchainProtocol_h */
