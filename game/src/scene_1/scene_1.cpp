//
// Created by jelle on 2019/11/28.
//

#include "scene_1.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "../scene_start/mainCharcters.h"
#include "Main_background.h"
#include "Main_level.h"
#include "../Tileset/tileset.h"
#include "../scene_2/scene_2.h"
#include "../scene_start/sonic_smaller16pixelsBreed.h"



std::vector<Background *> scene_1::backgrounds() {
    return {bg1.get(),bg2.get()};
}

std::vector<Sprite *> scene_1::sprites() {
    return {charcter.get()};
}

void scene_1::load() {
    engine.get()->disableText();

    foregroundPalette=std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sonic_smaller16pixelsBreedPal, sizeof(sonic_smaller16pixelsBreedPal)));
    backgroundPalette=std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(Pal_transPal, sizeof(Pal_transPal)));
    bg1=std::unique_ptr<Background>(CreateBackground(1, Pal_transTiles, sizeof(Pal_transTiles), Main_level, sizeof(Main_level), MAP32X64));
    bg2=std::unique_ptr<Background>(CreateBackground(2,Pal_transTiles, sizeof(Pal_transTiles),Main_background,sizeof(Main_background),MAP32X32));

  //  charcterX = 20;
  //  charcterY = 32+23;
  //  bg1X = 0;
 //   bg1Y = 32*8-GBA_SCREEN_HEIGHT;
    dead=false;
    v1Y =0;v1X=0;
    x=20;y=170;

    bg1.get()->scroll(bg1X,bg1Y);

    SpriteBuilder<Sprite> builder;

    charcter = builder
            .withData(sonic_smaller16pixelsBreedTiles, sizeof(sonic_smaller16pixelsBreedTiles))
            .withSize(SIZE_16_32)
            .withAnimated(16,10)
            .withLocation(charcterX, charcterY)
            .buildPtr();
    charcter.get()->setStayWithinBounds(true);
}

void scene_1::onTick(u16 keys) {


    if (keys & KEY_START) {
        engine->transitionIntoScene(new scene_2(engine), new FadeOutScene(2));
    }
}




