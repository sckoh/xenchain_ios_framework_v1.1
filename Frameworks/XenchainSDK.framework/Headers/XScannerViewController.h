//
//  XScannerViewController.h
//  XenchainSDK
//
//  Created by Jovial  on 12/4/2019.
//  Copyright © 2019 Xenchain. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Microblink/Microblink.h>

#import "XenchainProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Overlay ViewController that will be used as overlay for the Camera UI.
 
 @discussion This class is used to create an UI Overlay for the Camera. In addition, this class also includes callback methods which will be called by the SDK during the ID Scanning process.
 
 @warning This class needs to be extended as it is used as an overlay for the Camera UI. Failure to do so will results in Camera UI having pure Camera Screen with no User Interaction at all.
 */
@interface XScannerViewController : MBCustomOverlayViewController

/**
 @brief Function used to bypass the Hologram Scanning.
 
 @discussion This function is used to bypass the Hologram Scanning phase. The function might be used in the case where the ID Document has been scanned for too long or not able to pass the Hologram Screening.
 
 @warning This function is useable if the `CheckHologram` variable is set to `true`. `CheckHologram` can be setup in `CardConfig` class and it's respective child class.
 */
-(void) bypassHologramScan;

/**
 @brief Delegate function for Start Hologram Scanning.
 
 @discussion This function is called when the ID Scanner is about to Start Scan Hologram.
 
 @warning This function is called if the `CheckHologram` variable is set to `true`. `CheckHologram` can be setup in `CardConfig` class and it's respective child class.
 */
-(void) startScanHologram;

/**
 @brief Delegate function for Hologram Scanning Process
 
 @discussion This function is used to check the progress of Hologram Scanning.
 
 @param progress Refers to the progress of Hologram Scanning. It's value is from 0 to 1 in Double Data Type.
 
 @warning This function is called if the `CheckHologram` variable is set to `true`. `CheckHologram` can be setup in `CardConfig` class and it's respective child class.
 */
-(void) setHologramProgress:(double)progress;

/**
 @brief Delegate function for Hologram Scanning Complete Process
 
 @discussion This function is called to represents that the Hologram Scanning has been completed or bypassed.
 
 @warning This function is called if the `CheckHologram` variable is set to `true`. `CheckHologram` can be setup in `CardConfig` class and it's respective child class.
 */
-(void) hasScanHologram;

/**
 @brief Delegate function for Start Font Size Checking
 
 @discussion This function is called when the ID Scanner is about to Check Font Size.
 
 @warning This function is called if the `CheckFontSize` variable is set to `true`. `CheckFontSize` can be setup in `CardConfig` class and it's respective child class.
 */
-(void) startScanFontSize;

/**
 @brief Delegate function for Font Size Checking Complete Process
 
 @discussion This function is called represents that the Font Size Checking has been completed.
 
 @warning This function is called if the `CheckFontSize` variable is set to `true`. `CheckFontSize` can be setup in `CardConfig` class and it's respective child class.
 */
-(void) hasScanFontSize;

/**
 @brief Delegate function for Start Front ID Document Scanning
 
 @discussion This function is called when the ID Scanner is about to Scan the Front Side of the ID Document.
 */
-(void) startScanFront;

/**
 @brief Delegate function for Front ID Document Scanning Complete Process
 
 @discussion This function is called represents that the Front ID Document has been scanned.
 
 @param frontImage Refers to front image of the ID Document.
 */
-(void) hasScanFront:(UIImage *)frontImage;

/**
 @brief Delegate function for Start Back ID Document Scanning
 
 @discussion This function is called when the ID Scanner is about to Scan the Back Side of the ID Document.
 
 @warning This function is called if the `ScanFrontBack` variable is set to `true`. `ScanFrontBack` can be setup in `CardConfig` class and it's respective child class.
 */
-(void) startScanBack;

/**
 @brief Delegate function for Back ID Document Scanning Complete Process
 
 @discussion This function is called represents that the Back ID Document has been scanned.
 
 @param backImage Refers to back image of the ID Document.
 
 @warning This function is called if the `ScanFrontBack` variable is set to `true`. `ScanFrontBack` can be setup in `CardConfig` class and it's respective child class.
 */
-(void) hasScanBack:(UIImage *)backImage;

@end

NS_ASSUME_NONNULL_END
