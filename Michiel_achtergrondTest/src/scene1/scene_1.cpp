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
#include "PAL_SPEL2.h"
#include "try4.h"
#include "achtergrond20X18.h"
#include "try5.h"

#include "../../../game/src/scene_1/blok2.h"


std :: vector< Sprite *> SecondScene::sprites() {
    return{};
}
std :: vector<Background *> SecondScene::backgrounds()
{
    return {bg1.get()};
}

void SecondScene::load()
{
    backgroundPalette=std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(blok2Pal, sizeof(blok2Pal)));
    engine->getTimer()->start();
    bg1=std::unique_ptr<Background>(new Background(1,blok2Tiles,sizeof(blok2Tiles),try5,sizeof(try5)));
    bg1.get()->scroll(scrollX,scrollY);
}

void SecondScene::tick(u16 keys) {}