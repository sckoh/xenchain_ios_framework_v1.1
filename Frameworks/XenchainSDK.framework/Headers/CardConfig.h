//
//  CardConfig.h
//  XenchainSDK
//
//  Created by Jovial  on 11/4/2019.
//  Copyright © 2019 Xenchain. All rights reserved.
//

#ifndef CardConfig_h
#define CardConfig_h

#import <UIKit/UIKit.h>

/**
 @brief Base Class for ID Document Configs.
 
 @discussion This class is designed to allowed developers with the freedom to determine which part of the ID Document that must be scan or not.
 
 @note Every ID Document configuration will have at least one and/or two (in case of front and back scanning) mandatory field scanning. Those mandatory field scanning will not be listed in the corresponding class.
 */
@interface CardConfig : NSObject

/**
 @brief Scan using Default Configuration
 
 @warning Parameter must be set to `false` for all other configuration options to be executed.
 
 @note This parameter is only applicable for certain Card Type, excluding Passports.
 */
@property (nonatomic, assign) bool ScanDefaultConfig;

/**
 @brief Scan Front and Back IC of the Card.
 
 @discussion This parameter can be used in conjuction with `ScanDefaultConfig`. Refer to each of the variables in the child class to determine which options is belong to Front or Back of the ID card.
 
 @warning This parameter will return `true` if the `CheckLandmark` is set to `true`.
 
 @note Only applicable for certain Card Type, excluding Passports.
 */
@property (nonatomic, assign) bool ScanFrontBack;

/**
 @brief Enable Landmark Checking Capabilities
 
 @warning If set to `true`, it will override `ScanFrontBack` parameter as it is necessary to check front and back for Landmark checking.
 
 @note This parameter is only applicable for certain Card Type, excluding Passports.
 */
@property (nonatomic, assign) bool CheckLandmark;


@property (nonatomic, assign) bool CheckFontSize;
@property (nonatomic, assign) bool CheckHologram;

/**
 @brief Defines the number of Frame Detections before the Scanner returns the OCR Results.
 
 @discussion Defines how many times the same document should be detected before the detector returns this document as result of the detection. Higher number means more reliable detection, but slower processing.
 */
@property (nonatomic, assign) int StableFrame;

- (int)ScanType;
    
@end

#endif /* CardConfig_h */
