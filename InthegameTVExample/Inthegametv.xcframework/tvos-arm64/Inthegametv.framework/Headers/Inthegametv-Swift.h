// Generated by Apple Swift version 5.5.2 (swiftlang-1300.0.47.5 clang-1300.0.29.30)
#ifndef INTHEGAMETV_SWIFT_H
#define INTHEGAMETV_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreGraphics;
@import Foundation;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="Inthegametv",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif

@class UIColor;
@class NSNumber;
@class NSCoder;
@class UIFocusUpdateContext;
@class UIFocusAnimationCoordinator;
@class UIPress;
@class UIPressesEvent;

SWIFT_CLASS("_TtC11Inthegametv13FocusTvButton")
@interface FocusTvButton : UIButton
@property (nonatomic, strong) IBInspectable UIColor * _Nonnull selectedBackgroundColor;
@property (nonatomic, strong) IBInspectable UIColor * _Nullable selectedBackgroundEndColor;
@property (nonatomic, strong) IBInspectable UIColor * _Nonnull focusedBackgroundColor;
@property (nonatomic, strong) IBInspectable UIColor * _Nullable focusedBackgroundEndColor;
@property (nonatomic, strong) IBInspectable UIColor * _Nonnull normalBackgroundColor;
@property (nonatomic, strong) IBInspectable UIColor * _Nullable normalBackgroundEndColor;
@property (nonatomic) IBInspectable CGFloat cornerRadius;
@property (nonatomic) IBInspectable CGFloat focusedScaleFactor;
@property (nonatomic) IBInspectable CGFloat focusedShadowRadius;
@property (nonatomic) IBInspectable float focusedShadowOpacity;
@property (nonatomic) IBInspectable CGColorRef _Nonnull shadowColor;
@property (nonatomic) IBInspectable CGSize shadowOffSetFocused;
@property (nonatomic) IBInspectable NSTimeInterval animationDuration;
@property (nonatomic, strong) IBInspectable UIColor * _Nonnull focusedTitleColor;
@property (nonatomic, strong) IBInspectable UIColor * _Nonnull normalTitleColor;
@property (nonatomic) IBInspectable CGPoint gradientStartPoint;
@property (nonatomic) IBInspectable CGPoint gradientEndPoint;
@property (nonatomic, getter=isSelected) BOOL selected;
@property (nonatomic, readonly) UIButtonType buttonType;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)awakeFromNib;
- (void)didUpdateFocusInContext:(UIFocusUpdateContext * _Nonnull)context withAnimationCoordinator:(UIFocusAnimationCoordinator * _Nonnull)coordinator;
- (void)pressesBegan:(NSSet<UIPress *> * _Nonnull)presses withEvent:(UIPressesEvent * _Nullable)event;
- (void)pressesCancelled:(NSSet<UIPress *> * _Nonnull)presses withEvent:(UIPressesEvent * _Nullable)event;
- (void)pressesEnded:(NSSet<UIPress *> * _Nonnull)presses withEvent:(UIPressesEvent * _Nullable)event;
@end

@class UILabel;

SWIFT_CLASS("_TtC11Inthegametv11ITGInfoView")
@interface ITGInfoView : UIView
@property (nonatomic, weak) IBOutlet UIView * _Null_unspecified timerView;
@property (nonatomic, weak) IBOutlet UILabel * _Null_unspecified timerLabel1;
@property (nonatomic, weak) IBOutlet UILabel * _Null_unspecified timerLabel2;
@property (nonatomic, weak) IBOutlet UIView * _Null_unspecified pointsView;
@property (nonatomic, weak) IBOutlet UILabel * _Null_unspecified pointsLabel;
@property (nonatomic, weak) IBOutlet UILabel * _Null_unspecified pointsHeaderLabel;
@property (nonatomic, weak) IBOutlet UILabel * _Null_unspecified levelLabel;
@property (nonatomic, weak) IBOutlet UILabel * _Null_unspecified levelHeaderLabel;
@property (nonatomic, weak) IBOutlet FocusTvButton * _Null_unspecified accountButton;
@property (nonatomic, weak) IBOutlet FocusTvButton * _Null_unspecified closeButton;
@property (nonatomic, weak) IBOutlet UIView * _Null_unspecified separator;
- (void)awakeFromNib;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end

@class UIImageView;
@class UIStackView;
@class UIActivityIndicatorView;
@class UIScrollView;
@class NSLayoutConstraint;
@protocol UIFocusEnvironment;

SWIFT_CLASS("_TtC11Inthegametv18ITGInteractionView")
@interface ITGInteractionView : UIView
@property (nonatomic, weak) IBOutlet UIImageView * _Null_unspecified mainIcon;
@property (nonatomic, weak) IBOutlet UILabel * _Nullable titleLabel;
@property (nonatomic, weak) IBOutlet UILabel * _Nullable errorLabel;
@property (nonatomic, weak) IBOutlet UIStackView * _Nullable answerStack;
@property (nonatomic, weak) IBOutlet UIActivityIndicatorView * _Nullable indicator;
@property (nonatomic, weak) IBOutlet UIImageView * _Null_unspecified backgroundView;
@property (nonatomic, weak) IBOutlet UIView * _Null_unspecified mainContainer;
@property (nonatomic, weak) IBOutlet UIView * _Null_unspecified infoContainer;
@property (nonatomic, weak) IBOutlet UIView * _Nullable promotionContainer;
@property (nonatomic, weak) IBOutlet UIView * _Nullable promotionFlipContainer;
@property (nonatomic, weak) IBOutlet UIScrollView * _Nullable scrollView;
@property (nonatomic, weak) IBOutlet NSLayoutConstraint * _Nullable fixedWConstraint;
@property (nonatomic, weak) IBOutlet NSLayoutConstraint * _Nullable expandedWConstraint;
- (void)awakeFromNib;
@property (nonatomic, readonly, copy) NSArray<id <UIFocusEnvironment>> * _Nonnull preferredFocusEnvironments;
- (void)didUpdateFocusInContext:(UIFocusUpdateContext * _Nonnull)context withAnimationCoordinator:(UIFocusAnimationCoordinator * _Nonnull)coordinator;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11Inthegametv9ITGNotice")
@interface ITGNotice : UIView
- (void)awakeFromNib;
- (IBAction)actionClose:(id _Nonnull)sender;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11Inthegametv14ITGOverlayView")
@interface ITGOverlayView : UIView
- (void)didMoveToWindow;
@property (nonatomic, readonly, copy) NSArray<id <UIFocusEnvironment>> * _Nonnull preferredFocusEnvironments;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end







SWIFT_CLASS("_TtC11Inthegametv17ITGPollAnswerView")
@interface ITGPollAnswerView : UIView
@property (nonatomic, weak) IBOutlet FocusTvButton * _Null_unspecified button;
@property (nonatomic, weak) IBOutlet UILabel * _Null_unspecified statsLabel;
- (void)awakeFromNib;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11Inthegametv11ITGPollView")
@interface ITGPollView : ITGInteractionView
@property (nonatomic, readonly, copy) NSArray<id <UIFocusEnvironment>> * _Nonnull preferredFocusEnvironments;
- (void)didUpdateFocusInContext:(UIFocusUpdateContext * _Nonnull)context withAnimationCoordinator:(UIFocusAnimationCoordinator * _Nonnull)coordinator;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11Inthegametv14ITGProductView")
@interface ITGProductView : ITGInteractionView
@property (nonatomic, readonly, copy) NSArray<id <UIFocusEnvironment>> * _Nonnull preferredFocusEnvironments;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end

@class UITextField;

@interface ITGProductView (SWIFT_EXTENSION(Inthegametv)) <UITextFieldDelegate>
- (void)textFieldDidBeginEditing:(UITextField * _Nonnull)textField;
- (void)textFieldDidEndEditing:(UITextField * _Nonnull)textField;
@end


SWIFT_CLASS("_TtC11Inthegametv19ITGRatingAnswerView")
@interface ITGRatingAnswerView : UIView
@property (nonatomic, weak) IBOutlet FocusTvButton * _Null_unspecified button;
- (void)awakeFromNib;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11Inthegametv13ITGRatingView")
@interface ITGRatingView : ITGInteractionView
@property (nonatomic, weak) IBOutlet UIView * _Null_unspecified resultContainer;
@property (nonatomic, weak) IBOutlet UIImageView * _Null_unspecified starIcon;
@property (nonatomic, weak) IBOutlet UILabel * _Null_unspecified averageLabel;
@property (nonatomic, weak) IBOutlet UILabel * _Null_unspecified outOfLabel;
@property (nonatomic, weak) IBOutlet UILabel * _Null_unspecified maxLabel;
@property (nonatomic, readonly, copy) NSArray<id <UIFocusEnvironment>> * _Nonnull preferredFocusEnvironments;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11Inthegametv19ITGTriviaAnswerView")
@interface ITGTriviaAnswerView : UIView
@property (nonatomic, weak) IBOutlet FocusTvButton * _Null_unspecified button;
@property (nonatomic, weak) IBOutlet UILabel * _Nullable titleLabel;
@property (nonatomic, weak) IBOutlet UIImageView * _Nullable checkMarkView;
@property (nonatomic, weak) IBOutlet UIImageView * _Nullable imageView;
@property (nonatomic, weak) IBOutlet NSLayoutConstraint * _Nullable imageConstraint;
- (void)awakeFromNib;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11Inthegametv13ITGTriviaView")
@interface ITGTriviaView : ITGInteractionView
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC11Inthegametv15ITGUserAreaView")
@interface ITGUserAreaView : UIView
- (void)awakeFromNib;
@property (nonatomic, readonly, copy) NSArray<id <UIFocusEnvironment>> * _Nonnull preferredFocusEnvironments;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end

@class UITableView;
@class NSIndexPath;
@class UITableViewCell;

@interface ITGUserAreaView (SWIFT_EXTENSION(Inthegametv)) <UITableViewDataSource>
- (NSInteger)tableView:(UITableView * _Nonnull)tableView numberOfRowsInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (UITableViewCell * _Nonnull)tableView:(UITableView * _Nonnull)tableView cellForRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
@end


@interface ITGUserAreaView (SWIFT_EXTENSION(Inthegametv)) <UITableViewDelegate>
- (void)tableView:(UITableView * _Nonnull)tableView didSelectRowAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (void)didUpdateFocusInContext:(UIFocusUpdateContext * _Nonnull)context withAnimationCoordinator:(UIFocusAnimationCoordinator * _Nonnull)coordinator;
@end


SWIFT_CLASS("_TtC11Inthegametv11ITGWikiView")
@interface ITGWikiView : ITGInteractionView
@property (nonatomic, readonly, copy) NSArray<id <UIFocusEnvironment>> * _Nonnull preferredFocusEnvironments;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end





#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif
