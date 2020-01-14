//
// Created by michi on 14/01/2020.
//

#include "scene_4.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "../scene_1/Main_background.h"

#include "../scene_start/sonic_smaller16pixelsBreed.h"
#include "../sprites/shared_star_circle_sonic.h"
#include "../sprites/sonic_for_star_circle.h"
#include "../sprites/star.h"

#include "../Tileset/tilesSpel.c"


std::vector<Background *> scene_4::backgrounds() {
    return {bg1.get(),bg2.get(),bg0.get()};
}

std::vector<Sprite *> scene_4::sprites() {
    return {charcter.get(),ster.get()};
}

void scene_4::load() {
    engine.get()->disableText();

    foregroundPalette=std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette=std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(tilesSpelPal, sizeof(tilesSpelPal)));
    bg0=std::unique_ptr<Background>(CreateBackground(0, tilesSpelTiles, sizeof(tilesSpelTiles),mapScene4water , sizeof(mapScene4water), MAP64X64));
    bg1=std::unique_ptr<Background>(CreateBackground(1, tilesSpelTiles, sizeof(tilesSpelTiles),mapScene4 , sizeof(mapScene4), MAP64X64));
    bg2=std::unique_ptr<Background>(CreateBackground(2,tilesSpelTiles, sizeof(tilesSpelTiles),Main_background,sizeof(Main_background),MAP32X32));

    specialjumpActive=true;
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

void scene_4::onTick(u16 keys) {


    /*   if (keys & KEY_START) {
           engine->transitionIntoScene(new scene_1(engine), new FadeOutScene(2));
       }*/

}