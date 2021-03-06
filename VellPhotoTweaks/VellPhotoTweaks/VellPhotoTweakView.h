//
//  PhotoView.h
//  PhotoTweaks
//
//  Created by Tu You on 14/12/2.
//  Copyright (c) 2014年 Tu You. All rights reserved.
//

#import <UIKit/UIKit.h>

extern const CGFloat kMaxRotationAngle;

@class CropView;

//NS_ENUMで指定したいがswiftから呼べない
extern const NSInteger VPTAspectRatioTypeOneByOne;
extern const NSInteger VPTAspectRatioTypeFourByThree;

@interface PhotoContentView : UIView

@property (strong, nonatomic) UIImageView *imageView;
@property (strong, nonatomic) UIImage *image;

@end

@protocol CropViewDelegate <NSObject>

- (void)cropEnded:(CropView *)cropView;
- (void)cropMoved:(CropView *)cropView;

@end

@interface CropView : UIView
@end

@protocol VellPhotoTweakViewDelegate;
@interface VellPhotoTweakView : UIView

@property (nonatomic, weak) id<VellPhotoTweakViewDelegate> delegate;
@property (nonatomic, assign, readonly) CGFloat angle;
@property (nonatomic, assign, readonly) CGPoint photoContentOffset;

@property (nonatomic, strong, readonly) CropView *cropView;
@property (nonatomic, strong, readonly) PhotoContentView *photoContentView;
@property (nonatomic, strong) UISlider *slider;
@property (nonatomic, strong) UIButton *resetBtn;
@property (nonatomic, strong) UIButton *aspectBtn;
@property (nonatomic, strong) UIButton *rotationBtn;

- (instancetype)initWithFrame:(CGRect)frame
                        image:(UIImage *)image
             maxRotationAngle:(CGFloat)maxRotationAngle
          isFixCropViewAspect:(BOOL)isFixCropAspect;

- (instancetype)initWithFrame:(CGRect)frame
                        image:(UIImage *)image
             maxRotationAngle:(CGFloat)maxRotationAngle;

- (instancetype)initWithFrame:(CGRect)frame
                        image:(UIImage *)image;

- (CGPoint)photoTranslation;

- (void)resetSlider:(UISlider *)slider;
- (void)resetRotationBtn:(UIButton *)button;
- (void)resetAspectBtn:(UIButton *)button;
- (void)resetResetBtn:(UIButton *)button;

- (void)setAspectRatio:(NSInteger)aspectRatioType;
@end

/**
 The photo tweaks controller delegate
 */
@protocol VellPhotoTweakViewDelegate <NSObject>

- (void)vellPhotoTweakAspectTapped:(VellPhotoTweakView *)photoTweaksView;

@end
