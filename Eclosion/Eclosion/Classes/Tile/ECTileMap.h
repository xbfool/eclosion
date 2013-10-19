//
//  TileMap.h
//  Eclosion
//
//  Created by Tsubasa on 13-10-2.
//  Copyright 2013年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "cocos2d.h"

#define MAP_ROW 10
#define MAP_COL 7
#define TILE_SIZE 40

@class ECHero;
@interface ECTileMap : CCSprite {
    NSMutableArray *_tileMatrix;
    NSMutableArray *_myItems;
    ECHero*         _hero;
    int             _pixelMap[MAP_COL * TILE_SIZE][MAP_ROW* TILE_SIZE];
}

+ (ECTileMap *)mapBuildWithFile:(NSString *)filename;
- (void)run;
- (void)step:(ccTime)interval;
@end

