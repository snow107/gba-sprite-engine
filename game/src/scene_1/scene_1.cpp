//
// Created by jelle on 2019/11/28.
//

#include "scene_1.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "Main_background.h"
//#include "Main_level.h"
//#include "Main_level2.h"
//#include "../Tileset/tileset.h"
#include "../Tileset/tilesSpel.c"
#include "../scene_2/scene_2.h"
#include "../sprites/shared_star_circle_sonic.h"
#include "../sprites/sonic_for_star_circle.h"
#include "../sprites/star.h"



std::vector<Background *> scene_1::backgrounds() {
    return {bg1.get(),bg2.get()};
}

std::vector<Sprite *> scene_1::sprites() {
    return {charcter.get(),ster.get()};
}

void scene_1::load() {
    engine.get()->disableText();

    foregroundPalette=std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette=std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(tilesSpelPal, sizeof(tilesSpelPal)));
    bg1=std::unique_ptr<Background>(CreateBackground(1, tilesSpelTiles, sizeof(tilesSpelTiles), Main_level2, sizeof(Main_level2), MAP32X64));
    bg2=std::unique_ptr<Background>(CreateBackground(2,tilesSpelTiles, sizeof(tilesSpelTiles),Main_background,sizeof(Main_background),MAP32X32));


    dead=false;
    v1Y =0;v1X=0;
    x=resetX;y=resetY;

    bg1.get()->scroll(bg1X,bg1Y);

    SpriteBuilder<Sprite> builder;


    charcter = builder
            .withData(sonicTiles, sizeof(sonicTiles))
            .withSize(SIZE_16_32)
            .withAnimated(16,10)
            .withLocation(charcterX, charcterY)
            .buildPtr();
    charcter.get()->setStayWithinBounds(true);

    ster = builder
            .withData(starTiles,sizeof(starTiles))
            .withSize(SIZE_16_16)
            .withAnimated(1,1)
            .withLocation(0,200)//222/80
            .buildPtr();


}

void scene_1::onTick(u16 keys) {


   if(charcter.get()->collidesWith(*ster.get())){
       if (!engine->isTransitioning()) {
           engine->transitionIntoScene(new scene_2(engine), new FadeOutScene(2));
       }
   }
  /* if(dead)
   {
       if (!engine->isTransitioning()) {
           engine->transitionIntoScene(new scene_1(engine), new FadeOutScene(2));
       }
   }*/

    if (keys & KEY_START) {
        engine->transitionIntoScene(new scene_2(engine), new FadeOutScene(2));
    }
}




