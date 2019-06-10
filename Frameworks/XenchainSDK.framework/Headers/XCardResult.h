//
//  XCardResult.h
//  XenchainSDK
//
//  Created by Jovial  on 11/4/2019.
//  Copyright © 2019 Xenchain. All rights reserved.
//

#ifndef XCardResult_h
#define XCardResult_h

#import <Foundation/Foundation.h>

/**
 @brief Class used for storing the results of ID Card Scanning.
 @note Depending on the type of ID card and/or MRZ, some attributes of this class might be empty due to lack of information contained in it.
 */
@interface XCardResult : NSObject

@property (nonatomic, strong) NSString* mDocumentType;
@property (nonatomic, strong) NSString* mDocumentNumber;
@property (nonatomic, strong) NSString* mCardNumber;
@property (nonatomic, strong) NSString* mArmyNumber;
@property (nonatomic, strong) NSString* mBackDocumentNumber;

@property (nonatomic, strong) NSString* mFrontName;
@property (nonatomic, strong) NSString* mBackName;

@property (nonatomic, strong) NSString* mBloodType;

@property (nonatomic, strong) NSString* mAddress;
@property (nonatomic, strong) NSString* mVillage;
@property (nonatomic, strong) NSString* mRTRW;
@property (nonatomic, strong) NSString* mDistrict;
@property (nonatomic, strong) NSString* mCity;
@property (nonatomic, strong) NSString* mProvince;

@property (nonatomic, strong) NSString* mReligion;
@property (nonatomic, strong) NSString* mStatus;
@property (nonatomic, strong) NSString* mJob;
@property (nonatomic, strong) NSString* mGender;

@property (nonatomic, strong) NSString* mCitizenship;
@property (nonatomic, strong) NSString* mNationality;
@property (nonatomic, strong) NSString* mRace;
@property (nonatomic, strong) NSString* mDrivingLicenseClass;

@property (nonatomic, strong) NSString* mPlaceOfBirth;
@property (nonatomic, strong) NSString* mDateOfBirth;
@property (nonatomic, strong) NSString* mCountryOfBirth;
@property (nonatomic, strong) NSString* mFrontDateIssued;
@property (nonatomic, strong) NSString* mBackDateIssued;
@property (nonatomic, strong) NSString* mDateUpdated;
@property (nonatomic, strong) NSString* mFrontExpiry;
@property (nonatomic, strong) NSString* mBackExpiry;

@property (nonatomic, strong) NSString* mChipNumber;
@property (nonatomic, strong) NSString* mSerialNumber;

@property (nonatomic, strong) NSString* mEmployerInfo;
@property (nonatomic, strong) NSString* mSector;
@property (nonatomic, strong) NSString* mEmploymentOccupation;
@property (nonatomic, strong) NSString* mDateOfApplication;
@property (nonatomic, strong) NSString* mForeignIdentificationNo;

@property (nonatomic, strong) NSString* mFacultyInfo;
@property (nonatomic, strong) NSString* mFacultyCityZipcodeState;
@property (nonatomic, strong) NSString* mFacultyAddress;

-(NSString *) toString;

@end

#endif /* XCardResult_h */
