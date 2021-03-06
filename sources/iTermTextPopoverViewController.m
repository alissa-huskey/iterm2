//
//  iTermTextPopoverViewController.m
//  iTerm2
//
//  Created by George Nachman on 1/21/19.
//

#import "iTermTextPopoverViewController.h"

#import "SolidColorView.h"

const CGFloat iTermTextPopoverViewControllerHorizontalMarginWidth = 4;

@interface iTermTextPopoverViewController ()

@end

@implementation iTermTextPopoverViewController

- (void)appendString:(NSString *)string {
    if (!string.length) {
        return;
    }
    NSDictionary *attributes = @{ NSFontAttributeName: self.textView.font,
                                  NSForegroundColorAttributeName: self.textView.textColor ?: [NSColor textColor] };
    [_textView.textStorage appendAttributedString:[[NSAttributedString alloc] initWithString:string attributes:attributes]];
}

@end
