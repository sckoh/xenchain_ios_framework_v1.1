//
//  CameraViewController.m
//  DemoProject
//
//  Created by Jovial  on 3/6/2019.
//  Copyright © 2019 Xendity. All rights reserved.
//

#import "CameraViewController.h"

@interface CameraViewController ()

@end

@implementation CameraViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (IBAction)buttonAction:(UIButton *)sender {
    [self dismissViewControllerAnimated:true completion:nil];
}

- (void)startScanHologram {
    NSLog(@"Start Scan Hologram");
}

- (void)hasScanHologram {
    NSLog(@"Has Scan Hologram");
}

- (void)setHologramProgress:(double)progress {
    NSLog(@"Hologram Progress %.0f", progress * 100);
}

- (void)startScanFontSize {
    NSLog(@"Start Scan Font Size");
}

- (void)hasScanFontSize {
    NSLog(@"Has Scan Font Size");
}

- (void)startScanFront {
    NSLog(@"Start Scan Front ID");
}

- (void)hasScanFront:(UIImage *)frontImage {
    NSLog(@"Has Scan Front ID");
}

- (void)startScanBack {
    NSLog(@"Start Scan Back ID");
}

- (void)hasScanBack:(UIImage *)backImage {
    NSLog(@"Has Scan Back ID");
}

@end
