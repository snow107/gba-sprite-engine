//
// Created by jelle on 2019/11/28.
//

#include "scene_1.h"
#include "blok2.h"
#include "tilemap.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "../genericScene.h"
#include "../scene_start/mainCharcters.h"

#define GROUND_DISTANCE 80

std::vector<Background *> scene_1::backgrounds() {
    return {bg1.get()};
}

std::vector<Sprite *> scene_1::sprites() {
    return {sonic.get()};
}

void scene_1::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(blok2Pal, sizeof(blok2Pal)));

    engine->getTimer()->start();

    tilemap[(208/8)*tilemap_width+tilemap_width/4] = 0x0001;
    tilemap[(192/8)*tilemap_width+tilemap_width/4] = 0x0001;
    tilemap[(200/8)*tilemap_width+tilemap_width/4] = 0x0001;

    bg1 = std::unique_ptr<Background>(new Background(1, blok2Tiles, sizeof(blok2Tiles), tilemap, sizeof(tilemap)));

    bg1X = 0;
    bg1Y = GROUND_DISTANCE;
    v1Y =0;v1X=0;
    bg1.get()->scroll(bg1X,bg1Y);

    SpriteBuilder<Sprite> builder;

    sonic = builder
            .withData(sonicTiles, sizeof(sonicTiles))
            .withSize(SIZE_32_32)
            .withAnimated(16,10)
            .withLocation(0, GROUND_DISTANCE-32)
            .buildPtr();
}

void scene_1::tick(u16 keys) {
    //TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);

    if (!(ticknumber % 20)) { //searching for better solution (ideas are welcome)
        if (keys & KEY_LEFT) {
            if (v1X > 0) {
                v1X -= 2;
            } else if (v1X > -5) {
                v1X -= 1;
            }
        } else if (keys & KEY_RIGHT) {
            if (v1X < 0) {
                v1X += 2;
            } else if (v1X < 5) {
                v1X += 1;
            }
        } else {
            if (v1X > 0) v1X--;
            if (v1X < 0) v1X++;
        }
    }

    if (keys & KEY_START) {

    } else if (keys & KEY_UP) {
        if (charcterOnGround()) {
            v1Y = 5;
            move(0, 5);
        }
    } else if (keys & KEY_DOWN) {

    } else if (keys & KEY_B) {

    } else if (keys & KEY_A) {

    }


    if (!charcterOnGround()) {
        if (!(ticknumber % 5))
        v1Y -= 1;
    } else {
        v1Y = 0;
    }

    if(charcteragainstwall(true))
    {
        v1X = 0;
    }

    move(v1X, v1Y);


    ticknumber++;
}

bool scene_1::charcterOnGround() {
    //return (distanceToGround()<1);
    int charctertile = bg1Y / 8;
    if(tilemap[((charctertile)+10)*tilemap_width] != 0) { // 10 = (RESUTION_HEIGTH/2)/BLOCK_SIZE8
        bg1Y = (charctertile*8)+2;
        return true;
    }
    return false;
}

int scene_1::distanceToGround(){
    return GROUND_DISTANCE-bg1Y;
}

bool scene_1::charcteragainstwall(bool right) { //otherwise left
    int character_bottem_left_corner_tile = ((((bg1Y+(GBA_SCREEN_HEIGHT/2))/8)+1)*tilemap_width);
    if(right)
    {
        return (tilemap[character_bottem_left_corner_tile+32/*charcter width*//8+1] == 0);
    }
    else //left
    {
        return (tilemap[character_bottem_left_corner_tile-1] == 0);
    }
}

void scene_1::move(int x,int y){
    bg1X += x;
    bg1Y -= y;
    bg1.get()->scroll(bg1X,bg1Y);
}