//
//  ECMacros.h
//  BBYaoTang
//
//  Created by Tsubasa on 12-12-16.
//  Copyright 2012年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

// Winsize
#define WINSIZE ([[CCDirector sharedDirector] winSize])

// generate a new sprite and add it to current sprite on spicefic position
#define CC_CREATE_SPRITE(sprite, resourcename, _position_ ,zindex) \
CCSprite *sprite = [CCSprite spriteWithFile:resourcename]; \
sprite.position = ccp(_position_.x, WINSIZE.height - _position_.y);; \
[self addChild:sprite z:zindex];

// generate a new sprite and add it to center of current sprite
#define CC_CREATE_SPRITE_CENTER(sprite, resourcename ,zindex) \
CCSprite *sprite = [CCSprite spriteWithFile:resourcename]; \
sprite.position = CGPointMake([[CCDirector sharedDirector] winSize].width/2, \
[[CCDirector sharedDirector] winSize].height/2); \
[self addChild:sprite z:zindex];

// shared methods of singleton classes
#define SINGLTON_METHODS(object) \
+ (id)alloc {   \
NSAssert(object == nil, @"Attempt to alloc a singlton class once again!"); \
return nil; \
}

// judge if the rect contains a point, different to CGRectContain...
bool __cc_rect_contains_point(CGRect rect, CGPoint point);

#define CC_RECT_CONTAINS_POINT(__rect__, __point__) \
__cc_rect_contains_point(__rect__, __point__)

// easy to search document path
#define CC_DOCUMENT_PATH  [NSSearchPathForDirectoriesInDomains( \
NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]


// *********************************
// ECMacros for simplify adding subviw
// *********************************

// Add subview to superview, use relative position to superview.
#define CC_ADD_SPRITE_WITH_LEFTTOP(__backgroundLayer__,__layer__, __position__) \
__layer__.anchorPoint = ccp(0,1);  \
__layer__.position = ccp(__position__.x, __backgroundLayer__.contentSize.height - __position__.y);   \
[__backgroundLayer__ addChild:__layer__];

// Add subview to a root view, which actual size always be 0.
#define CC_ADD_SPRITE_TO_SCREEN_WITH_LEFTTOP(__screenLayer__,__layer__, __position__) \
__screenLayer__.anchorPoint = ccp(0,1);  \
__screenLayer__.position = ccp(__position__.x, WINSIZE.height - __position__.y);   \
[__screenLayer__ addChild:__layer__];

// Set position of subview, use relative position to superview.
#define CC_SET_SPRITE_POSITION_WITH_LEFTTOP(__backgroundLayer__,__layer__, __position__) \
__layer__.anchorPoint = ccp(0,1);  \
__layer__.position = ccp(__position__.x, __backgroundLayer__.contentSize.height - __position__.y);

// Set position of subview on screen.
#define CC_SET_SPRITE_POSITION_AT_SCREEN_WITH_LEFTTOP(__screenLayer__, __position__) \
__screenLayer__.anchorPoint = ccp(0,1);  \
__screenLayer__.position = ccp(__position__.x, WINSIZE.height - __position__.y);

// *********************************


// get plist
NSDictionary * __getDataFile(NSString *filename);
#define CC_GET_PLIST(__filename__) __getDataFile(__filename__)







