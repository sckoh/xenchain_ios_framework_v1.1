//
//  ViewController.m
//  DemoProject
//
//  Created by Jovial  on 3/6/2019.
//  Copyright © 2019 Xendity. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

bool firstLoad = true;
bool canScan = false;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)viewDidAppear:(BOOL)animated {
    if (firstLoad) {
        firstLoad = false;
        [XenchainSDK InitSDK:@"API Key" apiURL:@"API URL" onPremSaveData:false completionHandler:self];
    }
}


- (IBAction)buttonAction:(UIButton *)sender {
    if (canScan) {
        MyKadConfig *config = [[MyKadConfig alloc] init];
        [config setScanDefaultConfig:true];
        [config setCheckHologram:false];
        [config setCheckLandmark:false];
        [config setCheckFontSize:false];
        [config setScanFrontBack:true];
        
        [XenchainSDK DeployScanner:config inputController:self extendedController:[self.storyboard instantiateViewControllerWithIdentifier:@"CameraViewController"] completionHandler:self];
    }
}

- (void)InitSDKStatus:(bool)status message:(NSString *)message {
    canScan = status;
}

- (void)ScanCompleteDeployment:(bool)status errorMessage:(NSString *)errorMessage {
    
}

- (void)ScanLandmarkInformation:(NSDictionary *)landmarkScores {
    
}

- (void)ScanMetaResults:(UIImage *)idFaceImage refFace:(NSString *)refFace idFrontImage:(UIImage *)idFrontImage refFrontID:(NSString *)refFrontID idBackImage:(UIImage *)idBackImage refBackID:(NSString *)refBackID errorMessage:(NSString *)errorMessage {
    
}

- (void)ScanResults:(XCardResult *)cardResult onBoardingID:(NSString *)onBoardingID errorMessage:(NSString *)errorMessage {
    if (errorMessage.length > 0)
        [self.resultsText setText:errorMessage];
    else
        [self.resultsText setText:[cardResult toString]];
    
}

- (void)ScanServiceReferenceID:(NSString *)serviceReferenceID errorMessage:(NSString *)errorMessage {
    
}

@end
