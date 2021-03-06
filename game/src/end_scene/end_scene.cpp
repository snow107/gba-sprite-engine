//
// Created by michi on 14/01/2020.
//

#include "end_scene.h"
//
// Created by jelle on 2019/11/17.
//


#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "../sprites/sprites.h"
#include "../scene_1/scene_1.h"
#include "../maps/backgroundCity.h"
#include "../Tileset/tilesSpel.h"
#include <libgba-sprite-engine/gba/tonc_core.h>

std::vector<Background *> end_scene::backgrounds() {
    return {bg1.get()};
}

std::vector<Sprite *> end_scene::sprites() {
    return {kurby.get(),sonic.get(),cicle.get(),star.get()};
}

void end_scene::load() {
    engine->cleanBgRegisters();
    engine->enableText();
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette=std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(tilesSpelPal,sizeof(tilesSpelPal)));
    bg1=std::unique_ptr<Background>(CreateBackground(1,tilesSpelTiles,sizeof(tilesSpelTiles),Main_background,sizeof(Main_background),MAP32X32));

    TextStream::instance().setText("THE END", 3, 12);
    TextStream::instance().setText("BY MICHIEL AND JELLE", 6, 7);

    SpriteBuilder<Sprite> builder;

    kurby = builder
            .withData(kurbyTiles, sizeof(kurbyTiles))
            .withSize(SIZE_32_32) //smaller kurby because memory issues? or me stupid
            .withAnimated(12,10)
            .withLocation(GBA_SCREEN_WIDTH-32, 0)
            .buildPtr();

    sonic = builder
            .withData(sonicTiles, sizeof(sonicTiles))
            .withSize(SIZE_16_32)
            .withAnimated(16,10)
            .withLocation(0, 0)
            .buildPtr();

    star = builder
            .withData(starTiles, sizeof(starTiles))
            .withSize(SIZE_16_16)
            .withAnimated(1,100)
            .withLocation(GBA_SCREEN_WIDTH/3, 70)
            .buildPtr();

    cicle = builder
            .withData(cirkelTiles, sizeof(cirkelTiles))
            .withSize(SIZE_16_16)
            .withAnimated(1,100)
            .withLocation((GBA_SCREEN_WIDTH*2)/3, 70)
            .buildPtr();

    engine->getTimer()->start();
}

void end_scene::tick(u16 keys) {



    if(((keys & KEY_A) || (keys & KEY_B))) {
        engine->getTimer()->toggle();
    }

    if(keys & KEY_START) {
        if(!engine->isTransitioning()) {
            engine->transitionIntoScene(new scene_1(engine), new FadeOutScene(2));
        }
    }
}