//
//  MyDLConfig.h
//  XenchainSDK
//
//  Created by Jovial  on 21/5/2019.
//  Copyright © 2019 Xenchain. All rights reserved.
//

#ifndef MyDLConfig_h
#define MyDLConfig_h

#import "CardConfig.h"

/**
 @brief Configuration for Malaysia Driving License Scanning.
 
 @discussion This class is designed to allowed developers with the freedom to determine which part of the card must be scan or not.
 
 @warning Every ID Card configuration will have at least one and/or two (in case of front and back scanning) mandatory field scanning. Those mandatory field scanning will not be listed in the corresponding class.
 
 @note For this class, the Default Scanning is mandatory. Front & Back Scanning is not applicable.
 */
@interface MyDLConfig: CardConfig

@end

#endif /* MyDLConfig_h */
