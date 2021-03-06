//
//  BenthosTableViewController.h
//  SeafloorExplore
//
//  Modified from Brad Larson's Molecules Project in 2011-2012 for use in The SeafloorExplore Project
//
//  Copyright (C) 2012 Matthew Johnson-Roberson
//
//  See COPYING for license details
//  
//  Molecules
//
//  The source code for Molecules is available under a BSD license.  See COPYING for details.
//
//  Created by Brad Larson on 6/30/2008.
//
//  This controller manages the root table of models that are stored on the device

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

#import "BenthosRootViewController.h"
#import "BenthosFolderViewController.h"
#import "BenthosDownloadController.h"
#import "BenthosDetailViewController.h"


@interface BenthosTableViewController : UITableViewController <UITableViewDataSource, UITableViewDelegate>
{
	NSMutableArray *models;
	BenthosRootViewController *delegate;
	NSInteger selectedIndex;
	UIColor *tableTextColor;
    NSMutableArray *decompressingfiles;

	sqlite3 *database;
}

@property(readwrite,assign) BenthosRootViewController *delegate;
@property(readwrite,assign) sqlite3 *database;
@property(readwrite,retain) NSMutableArray *models;
@property(readwrite,retain) NSMutableArray *decompressingfiles;

@property(readwrite) NSInteger selectedIndex;

// Initialization and teardown
- (id)initWithStyle:(UITableViewStyle)style initialSelectedModelIndex:(NSInteger)initialSelectedModelIndex;

// Table customization
+ (CAGradientLayer *)glowGradientForSize:(CGSize)gradientSize;
+ (CAGradientLayer *)shadowGradientForSize:(CGSize)gradientSize;
- (IBAction)displayModelDownloadView;
- (IBAction)switchBackToGLView;
- (void)modelDidFinishDownloading:(NSNotification *)note;
-(void)addMolAndShow:(BenthosModel *)newModel;
-(void)updateUntarProgress:(NSNotification *)note;
-(void)addNewBGTask:(NSNotification *)note;
@end
