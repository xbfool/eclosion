//
//  ECGameScene.m
//  Blocks_Cocos
//
//  Created by ; on 13-9-1.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#import "ECGameScene.h"
#import "ECPauseScene.h"
#import "ECLevelScene.h"
#import "ECMenuScene.h"
#import "ECTileMap.h"
#import "ECLevelManager.h"

@interface ECGameScene()<ECPauseSceneDelegate>

@end

@implementation ECGameScene
+(CCScene *) scene
{
	CCScene *scene = [CCScene node];
	ECGameScene *layer = [ECGameScene node];
	[scene addChild: layer];
	return scene;
}

-(void) onEnter
{
	[super onEnter];
    
    // Set background
    if ( SCREEN_3_5 ) {
        CC_CREATE_SPRITE_CENTER(background, @"bg_game.png", 0);
    } else if ( SCREEN_4_0 ) {
        CC_CREATE_SPRITE_CENTER(background, @"bg_game_4inch.png", 0);
    } else {
        CC_CREATE_SPRITE_CENTER(background, @"bg_game.png", 0);
    }
    
    // Play button
    CC_CREATE_MENUITEM(pauseBtn, @"roundbuttonoff.png", @"roundbuttonon.png", pause);
    pauseBtn.position = ccp(WINSIZE.width - 35, WINSIZE.height - 35);
    CC_MENUITEM_ADD_ICON(pauseBtn, @"pause.png");
    
    // Menu
    CCMenu * m = [CCMenu menuWithItems:pauseBtn, nil];
    m.position = CGPointZero;
    [self addChild:m];
    
    // Level
    CCLabelTTF *label = [CCLabelTTF labelWithString:
                         [NSString stringWithFormat:@"%d", [ECLevelManager manager].currentLevel + 1]
                                           fontName:@"MarkerFelt-Thin" fontSize:28];
    label.anchorPoint = ccp(0.5,0.5);
    label.position = ccp(28, WINSIZE.height - 38);
    [self addChild:label];
    
    
    // Load game
    _map = [ECTileMap mapBuildWithFile:
            [NSString stringWithFormat:@"level%d",[ECLevelManager manager].currentLevel]];
    _map.position = ccp(22,5);
    [self addChild:_map];
    
    // Update
    [self schedule:@selector(fpsUpdate:)];
    [self schedule:@selector(fixUpdate:) interval:1.f/ECFixFPS];
}

-(void) onExit {
    [_map removeAllChildrenWithCleanup:YES];
    [super onExit];
}

-(void) pause {
    [self pauseSchedulerAndActions];
    if ( !_pauseScene ) {
        _pauseScene = [[ECPauseScene alloc] init];
        _pauseScene.delegate = self;
    }
    
	[self addChild: _pauseScene];
}

- (void)fpsUpdate:(ccTime)interval {
    [_map fpsUpdate:interval];
}

- (void)fixUpdate:(ccTime)interval {
    [_map fixUpdate:interval];
}

#pragma PauseScene Delegate
-(void) resumeGame {
    [self resumeSchedulerAndActions];
    [_pauseScene removeFromParentAndCleanup:YES];
    _pauseScene = nil;
}

-(void) restartGame {
    CC_TRANSLATE_SCENE([ECGameScene scene]);
}

-(void) gotoLevelScene {
    CC_TRANSLATE_SCENE([ECLevelScene scene]);
}

-(void) gotoMenuScene {
    CC_TRANSLATE_SCENE([ECMenuScene scene]);
}

@end
