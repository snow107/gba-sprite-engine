//
// Created by jelle on 2019/11/28.
//

#include "scene_1.h"
#include "blok2.h"
#include "tilemap.h"
#include "newBigMap.h"
#include "klein_probeer.h"
#include "domMap.h"
#include "Labview1.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "../genericScene.h"
#include "../scene_start/mainCharcters.h"
#define CHARTERHEIGTH 32
#define CHARTERWIDTH 32
#define SCENE_WIDTH 32

std::vector<Background *> scene_1::backgrounds() {
    return {bg1.get()};
}

std::vector<Sprite *> scene_1::sprites() {
    return {charcter.get()};
}

void scene_1::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(blok2Pal, sizeof(blok2Pal)));

    engine->getTimer()->start();

    bg1 = std::unique_ptr<Background>(new Background(1, blok2Tiles, sizeof(blok2Tiles), bigMap, sizeof(bigMap)));

    charcterX = 20;
    charcterY = 50;
    bg1X = 0;
    bg1Y = 20;
    v1Y =0;v1X=0;
    bg1.get()->scroll(bg1X,bg1Y);

    SpriteBuilder<Sprite> builder;

    charcter = builder
            .withData(sonicTiles, sizeof(sonicTiles))
            .withSize(SIZE_32_32)
            .withAnimated(16,10)
            .withLocation(charcterX, charcterY)
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
            movebg1(0, 5);
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

    if(charcteragainstwall(true ) && v1X > 0 )
    {
        v1X = 0;
    }

    movebg1(v1X, v1Y);

    ticknumber++;
}

bool scene_1::charcterOnGround() {

    //this code works half
    int charctertileY = (bg1Y + charcterY + CHARTERHEIGTH) / 8;
    int charctertileX = (bg1X + CHARTERHEIGTH/2 + charcterX)/8; //half width of charcter
    if(bigMap[((charctertileY+1)*SCENE_WIDTH)+charctertileX] != 0) {
        bg1Y = ((bg1Y/8)*8)+2; //yes I change the heigth, just so it looks nice
        return true;
    }


    //this code "works"
//    int charctertile = bg1Y / 8;
//    if(tilemap[((charctertile)+10)*tilemap_width] != 0) { // 10 = (RESUTION_HEIGTH/2)/BLOCK_SIZE8
//        bg1Y = (charctertile*8)+2;
//        return true;
//    }


    return false;
}

bool scene_1::charcteragainstwall(bool right) { //otherwise left
    int character_bottem_left_corner_tile = (((bg1Y+CHARTERHEIGTH)/8)*tilemap_width);

    if(right)
    {
        return (tilemap[character_bottem_left_corner_tile+CHARTERWIDTH/*charcter width*//8+1] == 0);
    }
    else //left
    {
        return (tilemap[character_bottem_left_corner_tile-1] == 0);
    }
}

void scene_1::movebg1(int x, int y){
    bg1X += x;
    bg1Y -= y;
    bg1.get()->scroll(bg1X,bg1Y);
}

void scene_1::movecharcter(int x, int y) {
    charcterX += x;
    charcterY -= y;
    charcter.get()->moveTo(charcterX,charcterY);
}