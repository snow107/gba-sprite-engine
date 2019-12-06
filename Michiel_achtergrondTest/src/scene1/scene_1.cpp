//
// Created by michi on 5/12/2019.
//
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>
#include "scene_1.h"

#include "try4.h"
#include "achtergrond20X18.h"
#include "try5.h"
#include "try6.h"
#include "PAL_SPEL2.c"
#include "try7.h"
#include "SPEL2PAL.c"
#include "../../../game/src/scene_1/blok2.h"


std :: vector< Sprite *> SecondScene::sprites() {
    return{};
}
std :: vector<Background *> SecondScene::backgrounds()
{
    return{bg2.get() , bg1.get()};
}


void SecondScene::load()
{
    backgroundPalette=std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(SPEL2PALPal, sizeof(SPEL2PALPal)));
    engine->getTimer()->start();

    bg1=std::unique_ptr<Background>(new Background(1,SPEL2PALTiles,sizeof(SPEL2PALTiles),achterGrond  ,sizeof(achterGrond)));
    bg2=std::unique_ptr<Background>(new Background(2,SPEL2PALTiles,sizeof(SPEL2PALTiles),try6  ,sizeof(try6)));
   // bg1.get()->scroll(scrollX,scrollY);
}

void SecondScene::tick(u16 keys) {
    if (keys & KEY_RIGHT )
    {

        if(scrollX <500-GBA_SCREEN_WIDTH)
        {
            scrollX++;
            //bg1.get()->scrollSpeed(1, 0);
            bg1.get()->scroll(scrollX,scrollY);
        }
    }

    else if(keys & KEY_LEFT)
    {
        if(scrollX >0)
        {
            scrollX--;
            //bg1.get()->scrollSpeed(1, 0);
            bg1.get()->scroll(scrollX,scrollY);
        }
    }
    else if(keys & KEY_DOWN)
    {
        if(scrollY <500-GBA_SCREEN_HEIGHT)
        {
            scrollY++;
            bg1.get()->scroll(scrollX,scrollY);
        }
    }
    else if (keys & KEY_UP)
    {
        if (scrollY > 0) {
            scrollY--;
            bg1.get()->scroll(scrollX, scrollY);
        }
    }
}