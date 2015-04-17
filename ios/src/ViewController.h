//
//  ViewController.h
//  TangramiOS
//
//  Created by Matt Blair on 8/25/14.
//  Copyright (c) 2014 Mapzen. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>

@interface ViewController : GLKViewController <UIGestureRecognizerDelegate>

@property bool continuous;
- (void)renderOnce;

@end
