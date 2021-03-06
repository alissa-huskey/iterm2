#import <Cocoa/Cocoa.h>
#import "CPKSliderView.h"

@class CPKColor;

/**
 * A view that shows a range of alpha values and allows the user to select one.
 */
@interface CPKAlphaSliderView : CPKSliderView

/** The selected color. Does not move the slider's value, only affects the gradient's color. */
@property(nonatomic) CPKColor *color;

/**
 * Initializes an alpha slider.
 *
 * @param frame The initial frame.
 * @param alpha The initial alpha value.
 * @param block The block to invoke when the user drags the alpha indicator.
 *
 * @return An initialized instance.
 */
- (instancetype)initWithFrame:(NSRect)frame
                        alpha:(CGFloat)alpha
                        color:(CPKColor *)color
                   colorSpace:(NSColorSpace *)colorSpace
                        block:(void (^)(CGFloat))block;

@end
