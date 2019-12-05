//
// Created by michi on 5/12/2019.
//
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>
#include "start_scene.h"
#include "blok2.h"
#include "Labview1.h"

std::vector<Background *> BeginScene::backgrounds() {
    return {bg1.get()};
}
std::vector<Sprite *> BeginScene::sprites() {
    return {};
}

void BeginScene::load() {

    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(blok2Pal, sizeof(blok2Pal)));
    engine->getTimer()->start();
    bg1 = std::unique_ptr<Background>(new Background(1, blok2Tiles, sizeof(blok2Tiles), bigMap, sizeof(bigMap)));

}

void BeginScene ::tick(u16 keys) {


}