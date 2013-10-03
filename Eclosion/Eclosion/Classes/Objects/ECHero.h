//
//  ECHero.h
//  Eclosion
//
//  Created by Tsubasa on 13-10-3.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "cocos2d.h"

typedef enum {
    ECHeroActionDefault = 0,
    ECHeroActionSuccess,
    ECHeroActionFailure,
    ECHeroActionCount // MUST be last one
} ECHeroAction;

@interface ECHero : CCSprite {
    
}
@property(nonatomic, assign) int             speed;
@property(nonatomic, assign) bool            animating;
@property(nonatomic, assign) ECHeroAction    heroAction;

- (void)run;
@end
