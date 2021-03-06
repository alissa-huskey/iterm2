//
//  ToolJobs.h
//  iTerm
//
//  Created by George Nachman on 9/6/11.
//  Copyright 2011 Georgetech. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import "FutureMethods.h"
#import "iTermToolWrapper.h"

@interface ToolJobs : NSView <
  ToolbeltTool,
  NSComboBoxDelegate,
  NSTableViewDelegate,
  NSTableViewDataSource>

- (void)updateJobs;

@end
