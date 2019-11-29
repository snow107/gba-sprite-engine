//
// Created by jelle on 2019/11/28.
//

#include "scene_1.h"
#include "blok2.h"
#include "tilemap.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "../genericScene.h"

std::vector<Background *> scene_1::backgrounds() {
    return {bg1.get()};
}

std::vector<Sprite *> scene_1::sprites() {
    return {};
}

void scene_1::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager());
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(blok2Pal, sizeof(blok2Pal)));

    engine->getTimer()->start();

    bg1 = std::unique_ptr<Background>(new Background(1, blok2Tiles, sizeof(blok2Tiles), tilemap, sizeof(tilemap)));
    bg1.get()->useMapScreenBlock(16);
    bg1.get()->getScreenBlock();

    bg1X = 0;
    bg1Y = 60;
}

void scene_1::tick(u16 keys) {
    //TextStream::instance().setText(engine->getTimer()->to_string(), 18, 1);

    if(((keys & KEY_A) || (keys & KEY_B))) {
        engine->getTimer()->toggle();
    }

    if(keys & KEY_START) {
        if(!engine->isTransitioning()) {
            //engine->transitionIntoScene(new FlyingStuffScene(engine), new FadeOutScene(2));
        }
    } else if(keys & KEY_LEFT) {
        bg1X-=2;
        bg1.get()->scroll(bg1X,bg1Y);
    } else if(keys & KEY_RIGHT) {
        bg1X+=2;
        bg1.get()->scroll(bg1X,bg1Y);
    } else if(keys & KEY_UP) {

    } else if(keys & KEY_DOWN) {

    } else if(keys & KEY_B) {

    } else if(keys & KEY_A) {

    }
}