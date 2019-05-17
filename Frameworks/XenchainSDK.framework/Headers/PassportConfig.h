//
//  PassportConfig.h
//  XenchainSDK
//
//  Created by Jovial  on 14/4/2019.
//  Copyright © 2019 Xenchain. All rights reserved.
//

#ifndef PassportConfig_h
#define PassportConfig_h

#import "CardConfig.h"

/**
 @brief Configuration for Passport Scanning.
 
 @discussion This class is designed to allowed developers with the freedom to determine which part of the card must be scan or not.
 
 @warning Every ID Card configuration will have at least one and/or two (in case of front and back scanning) mandatory field scanning. Those mandatory field scanning will not be listed in the corresponding class.
 
 @note For this class, the MRZ OCR Scanning is mandatory. Front & Back Scanning is not applicable.
 */
@interface PassportConfig: CardConfig

@end


#endif /* PassportConfig_h */
