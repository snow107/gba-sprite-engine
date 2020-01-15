//
// Created by jelle on 2019/11/17.
//

#include "start_scene.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "startSceneSprites.h"
#include "../scene_1/scene_1.h"

std::vector<Background *> start_scene::backgrounds() {
    return {};
}

std::vector<Sprite *> start_scene::sprites() {
    return {kurby.get(),sonic.get(),cicle.get(),star.get()};
}

void start_scene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));

    TextStream::instance().setText("PRESS START TO PLAY", 3, 5);

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
            .withLocation(GBA_SCREEN_WIDTH/3, 50)
            .buildPtr();

    cicle = builder
            .withData(cirkelTiles, sizeof(cirkelTiles))
            .withSize(SIZE_16_16)
            .withAnimated(1,100)
            .withLocation((GBA_SCREEN_WIDTH*2)/3, 50)
            .buildPtr();

    engine->getTimer()->start();
}

void start_scene::tick(u16 keys) {
    TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);

    if(((keys & KEY_A) || (keys & KEY_B))) {
        engine->getTimer()->toggle();
    }

    if(keys & KEY_START) {
        if(!engine->isTransitioning()) {
            engine->transitionIntoScene(new scene_1(engine), new FadeOutScene(2));
        }
    }
}