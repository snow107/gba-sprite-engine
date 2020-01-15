//
// Created by jelle on 2020/01/04.
//

#include "scene_2.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "../scene_1/Main_background.h"
#include "../scene_1/scene_1.h"
#include "../scene_3/scene_3.h"
#include "../sprites/shared_star_circle_sonic.h"
#include "../sprites/sonic_for_star_circle.h"
#include "../sprites/star.h"
#include "../Tileset/tilesSpel.c"


std::vector<Background *> scene_2::backgrounds() {
    return {bg1.get(),bg2.get()};
}

std::vector<Sprite *> scene_2::sprites() {
    return {charcter.get(),ster.get()};
}

void scene_2::load() {
    engine.get()->disableText();

    foregroundPalette=std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette=std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(tilesSpelPal, sizeof(tilesSpelPal)));
    bg1=std::unique_ptr<Background>(CreateBackground(1, tilesSpelTiles, sizeof(tilesSpelTiles), mapScene2, sizeof(mapScene2), MAP64X64));
    bg2=std::unique_ptr<Background>(CreateBackground(2,tilesSpelTiles, sizeof(tilesSpelTiles),Main_background,sizeof(Main_background),MAP32X32));

  //  charcterX = 20;
 //   charcterY = 50;
  //  bg1X = 0;
 //   bg1Y = 5;
    v1Y =0;v1X=0;
   x=0,y=0;
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
            .withLocation(0,200)//222/40
            .buildPtr();
}

void scene_2::onTick(u16 keys) {
    if(charcter.get()->collidesWith(*ster.get())){
        if (!engine->isTransitioning()) {
            engine->transitionIntoScene(new scene_3(engine), new FadeOutScene(2));
        }
    }

    if (keys & KEY_START) {
        engine->transitionIntoScene(new scene_3(engine), new FadeOutScene(2));
    }

}