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

//#include "try4.h"
#include "achtergrond20X18.h"
//#include "try5.h"
#include "try6.h"
//#include "PAL_SPEL2.c"
//#include "try7.h"
#include "SPEL2PAL.h"
#include "../../../game/src/scene_1/blok2.h"


std :: vector< Sprite *> SecondScene::sprites() {
    return{};
}
std :: vector<Background *> SecondScene::backgrounds()
{
    if (!loadcomplete){
        return std :: vector<Background *>{};
    } else {
        return bgvector;
    }
}



void SecondScene::load()
{
    loadcomplete = false;
    bg2.get()->clearMap();
    bg1.get()->clearMap();
    bgvector.clear();

    bg2=std::unique_ptr<Background>(new Background(2,SPEL2PALTiles2,sizeof(SPEL2PALTiles2),achterGrond  ,sizeof(achterGrond)));
    bgvector.push_back(bg2.get());
    bg1=std::unique_ptr<Background>(new Background(1,SPEL2PALTiles,sizeof(SPEL2PALTiles),try6  ,sizeof(try6)));
    bgvector.push_back(bg1.get());

    engine.get()->disableText();
    backgroundPalette=std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(SPEL2PALPal, sizeof(SPEL2PALPal)));




   // bg1.get()->scroll(scrollX,scrollY);

    loadcomplete = true;
}

void SecondScene::tick(u16 keys) {
    if (!(ticknumber%200)){
        bg2.get()->clearMap();
        bg1.get()->updateMap(try6);
        bgvector.clear();
        if(!bgvector.empty())
        {
            while (1);
        }
        //bgvector.push_back(bg1.get());
        //bgvector.push_back(bg2.get());
    }
    if (!((ticknumber+100)%200)){
        bg1.get()->clearMap();
        bg2.get()->updateMap(achterGrond);
        bgvector.clear();
        //bgvector.push_back(bg1.get());
        //bgvector.push_back(bg2.get());
    }

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

    ticknumber++;
}