//
//  URLAction.h
//  iTerm
//
//  Created by George Nachman on 12/14/13.
//
//

#import <Foundation/Foundation.h>
#import "VT100GridTypes.h"

@protocol iTermImageInfoReading;
@class iTermSemanticHistoryController;
@class iTermTextExtractor;
@class SCPPath;
@protocol VT100RemoteHostReading;

typedef NS_ENUM(NSInteger, URLActionType) {
    kURLActionOpenURL,
    kURLActionSmartSelectionAction,
    kURLActionOpenExistingFile,
    kURLActionOpenImage,
    kURLActionSecureCopyFile,
};

@interface URLAction : NSObject

// Always set.
@property(nonatomic, assign) URLActionType actionType;

// Always set. Generally, the text that was used to select the action (e.g., the selection).
// For images, this is the filename. See |identifier| for the ImageInfo.
@property(nonatomic, readonly) NSString *string;

// Extra info. For kURLActionOpenImage, this holds an image. For kURLActionSecureCopyFile, this
// holds an SCPPath.
@property(nonatomic, readonly) id identifier;

// Always set. The range of |string| on screen.
@property(nonatomic, assign) VT100GridWindowedRange range;

// For kURLActionOpenExistingFile, the full path the the file.
@property(nonatomic, copy) NSString *fullPath;
@property(nonatomic, copy) NSString *rawFilename;  // Before removing nearby punctuation. Might start with a/ or b/ so we keep it around.
@property(nonatomic, copy) NSString *lineNumber;
@property(nonatomic, copy) NSString *columnNumber;

// For kURLActionOpenExistingFile, the working directory of the file.
@property(nonatomic, copy) NSString *workingDirectory;

// For kURLActionSmartSelectionAction, the rule used.
@property(nonatomic, readonly) NSDictionary *rule;

// For kURLActionSmartSelectionAction. Generally, a string parameter to a smart
// selection action.
@property(nonatomic, strong) id representedObject;

// For kURLActionSmartSelectionAction, the selector to invoke. This URLAction
// will be passed as the argument.
@property(nonatomic, assign) SEL selector;

@property(nonatomic) BOOL hover;

+ (instancetype)urlActionToSecureCopyFile:(SCPPath *)scpPath;
+ (instancetype)urlActionToOpenURL:(NSString *)filename;
+ (instancetype)urlActionToPerformSmartSelectionRule:(NSDictionary *)rule
                                            onString:(NSString *)content;
+ (instancetype)urlActionToOpenExistingFile:(NSString *)filename;
+ (instancetype)urlActionToOpenImage:(id<iTermImageInfoReading>)imageInfo;

@end
