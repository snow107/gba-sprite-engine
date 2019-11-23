//
// Created by jelle on 2019/11/17.
//

#include "start_scene.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "mainCharcters.h"

std::vector<Background *> start_scene::backgrounds() {
    return {};
}

std::vector<Sprite *> start_scene::sprites() {
    return {kurby.get(),sonic.get()};
}

void start_scene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    TextStream::instance().setText("PRESS START TO PLAY", 3, 8);

    SpriteBuilder<Sprite> builder;

    kurby = builder
            .withData(kurbyTiles, sizeof(kurbyTiles))
            .withSize(SIZE_32_32) //smaller kurby because memory issues? or me stupid
            .withAnimated(12,10)
            .withLocation(0, 0)
            .buildPtr();

    sonic = builder
            .withData(sonicTiles, sizeof(sonicTiles))
            .withSize(SIZE_32_32)
            .withAnimated(16,10)
            .withLocation(0, 40)
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
            TextStream::instance() << "entered: yay?";

            //engine->transitionIntoScene(new FlyingStuffScene(engine), new FadeOutScene(2));
        }
    } else if(keys & KEY_LEFT) {
        TextStream::instance() << "LEFT: yay?";
    } else if(keys & KEY_RIGHT) {
        TextStream::instance() << "RIGHT: yay?";
    } else if(keys & KEY_UP) {
        TextStream::instance() << "UP: yay?";
    } else if(keys & KEY_DOWN) {
        TextStream::instance() << "DOWN: yay?";
    } else if(keys & KEY_B) {
        TextStream::instance() << "B: yay?";
    } else if(keys & KEY_A) {
        TextStream::instance() << "A: yay?";
    }
}