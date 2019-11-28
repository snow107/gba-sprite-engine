//
// Created by jelle on 2019/11/28.
//

#include "scene_1.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>



std::vector<Background *> scene_1::backgrounds() {
    return {};
}

std::vector<Sprite *> scene_1::sprites() {
    return {kurby.get(),sonic.get()};
}

void scene_1::load() {
    //foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    //backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    engine->getTimer()->start();
}

void scene_1::tick(u16 keys) {
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