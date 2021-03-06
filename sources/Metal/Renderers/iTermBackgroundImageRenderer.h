#import <Cocoa/Cocoa.h>

#import "ITAddressBookMgr.h"
#import "iTermMetalRenderer.h"

NS_ASSUME_NONNULL_BEGIN

@class iTermImageWrapper;

@interface iTermBackgroundImageRendererTransientState : iTermMetalRendererTransientState
@property (nonatomic) NSEdgeInsets edgeInsets;
@property (nonatomic) CGFloat computedAlpha;  // See iTermAlphaBlendingHelper.h
@end

@interface iTermBackgroundImageRenderer : NSObject<iTermMetalRenderer>

@property (nonatomic, readonly) iTermImageWrapper *image;

- (nullable instancetype)initWithDevice:(id<MTLDevice>)device NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;

// Call this before creating transient state.
// Frame takes values in [0,1] giving relative location of the viewport within the tab.
- (void)setImage:(iTermImageWrapper *)image
            mode:(iTermBackgroundImageMode)mode
           frame:(CGRect)frame
   containerRect:(CGRect)containerRect
           color:(vector_float4)defaultBackgroundColor
      colorSpace:(NSColorSpace *)colorSpace
         context:(nullable iTermMetalBufferPoolContext *)context;

@end

NS_ASSUME_NONNULL_END
