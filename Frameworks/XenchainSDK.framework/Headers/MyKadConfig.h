//
//  MyKadConfig.h
//  XenchainSDK
//
//  Created by Jovial  on 11/4/2019.
//  Copyright © 2019 Xenchain. All rights reserved.
//

#ifndef MyKadConfig_h
#define MyKadConfig_h

#import "CardConfig.h"

/**
 @brief Configuration for MyKad Scanning.
 
 @discussion This class is designed to allowed developers with the freedom to determine which part of the card must be scan or not.
 
 @warning Every ID Card configuration will have at least one and/or two (in case of front and back scanning) mandatory field scanning. Those mandatory field scanning will not be listed in the corresponding class.
 
 @note For this class, both Front and/or Back IC Number is considered mandatory.
 */
@interface MyKadConfig : CardConfig 

/**
 @brief Scan the name contained in MyKad
 @note This parameter refer to Front ID card.
 */
@property (nonatomic, assign) bool ScanName;

/**
 @brief Scan the addresss contained in MyKad
 @note This parameter refer to Front ID card.
 */
@property (nonatomic, assign) bool ScanAddress;

/**
 @brief Scan the Citizen contained in MyKad
 @note This parameter refer to Front ID card.
 */
@property (nonatomic, assign) bool ScanCitizen;

/**
 @brief Scan the Religion contained in MyKad
 @note This parameter refer to Front ID card.
 */
@property (nonatomic, assign) bool ScanReligion;

/**
 @brief Scan the Gender contained in MyKad
 @note This parameter refer to Front ID card.
 */
@property (nonatomic, assign) bool ScanGender;

/**
 @brief Scan the Chip Number contained in MyKad
 @note This parameter refer to Back ID card.
 */
@property (nonatomic, assign) bool ScanChipNumber;

@end

#endif /* MyKadConfig_h */
