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
#include "../Tileset/Pal_trans.c"


std :: vector< Sprite *> SecondScene::sprites() {
    return{};
}
std :: vector<Background *> SecondScene::backgrounds()
{
   return{bg1.get(),bg2.get()};
}



void SecondScene::load()
{

    backgroundPalette=std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(Pal_transPal, sizeof(Pal_transPal)));

  //  bg1=std::unique_ptr<Background>(new Background(1,Pal_transTiles,sizeof(Pal_transTiles),try6  ,sizeof(try6)));
  //  bg2=std::unique_ptr<Background>(new Background(2,Pal_transTiles,sizeof(Pal_transTiles),achterGrond  ,sizeof(achterGrond)));

    bg1=std::unique_ptr<Background>(CreateBackground(1,Pal_transTiles, sizeof(Pal_transTiles),try6,sizeof(try6),MAP32X32));
    bg2=std::unique_ptr<Background>(CreateBackground(2,Pal_transTiles,sizeof(Pal_transTiles),achterGrond, sizeof(achterGrond),MAP32X32));

    engine.get()->disableText();





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
            bg2.get()->scroll(scrollX,scrollY);
        }
    }

    else if(keys & KEY_LEFT)
    {
        if(scrollX >0)
        {
            scrollX--;
            //bg1.get()->scrollSpeed(1, 0);
            bg1.get()->scroll(scrollX,scrollY);
            bg2.get()->scroll(scrollX,scrollY);
        }
    }
    else if(keys & KEY_DOWN)
    {
        if(scrollY <500-GBA_SCREEN_HEIGHT)
        {
            scrollY++;
            bg1.get()->scroll(scrollX,scrollY);
            bg2.get()->scroll(scrollX,scrollY);
        }
    }
    else if (keys & KEY_UP)
    {
        if (scrollY > 0) {
            scrollY--;
            bg1.get()->scroll(scrollX, scrollY);
            bg2.get()->scroll(scrollX,scrollY);
        }
    }


}