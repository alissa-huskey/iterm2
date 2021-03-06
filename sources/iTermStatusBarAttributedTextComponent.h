//
//  iTermStatusBarAttributedTextComponent.h
//  iTerm2SharedARC
//
//  Created by George Nachman on 7/22/18.
//

#import "iTermStatusBarBaseComponent.h"

NS_ASSUME_NONNULL_BEGIN

// WARNING! This doesn't support most features of attributed strings. This uses
// a terrible hack to work around an NSTextField bug.
@interface iTermStatusBarAttributedTextComponent : iTermStatusBarBaseComponent

@property (nonatomic, readonly) NSArray<NSAttributedString *> *attributedStringVariants;

@property (nonatomic, readonly) NSTextField *textField;
@property (nonatomic, readonly) NSColor *textColor;
@property (nonatomic, readonly) NSFont *font;

- (CGFloat)widthForAttributedString:(NSAttributedString *)string;
- (void)updateTextFieldIfNeeded;

// Subclasses can override this to return YES if the longest variant can always be truncated to fit.
- (BOOL)truncatesTail;
- (NSTextField *)newTextField;

@end

NS_ASSUME_NONNULL_END
