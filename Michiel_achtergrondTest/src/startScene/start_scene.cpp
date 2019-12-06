//
// Created by michi on 5/12/2019.
//
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "start_scene.h"
#include "blok2.h"
#include "Labview1.h"
#include  "probeerSpiegel.h"
#include "../scene1/scene_1.h"
#include "try1.h"
#include "try3.h"
#include "../scene1/try4.h"
#include "../scene1/PAL_SPEL2.h"


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
    scrollY=tilemapHeight-GBA_SCREEN_HEIGHT;
    bg1.get()->scroll(scrollX, scrollY);

}

void BeginScene ::tick(u16 keys) {

    if (keys & KEY_RIGHT )
    {

        if(scrollX <tilemapWith-GBA_SCREEN_WIDTH)
        {
            scrollX++;
            //bg1.get()->scrollSpeed(1, 0);
            bg1.get()->scroll(scrollX,scrollY);
        }
    }

    else if(keys & KEY_LEFT)
    {
        if(scrollX >0)
        {
            scrollX--;
            //bg1.get()->scrollSpeed(1, 0);
            bg1.get()->scroll(scrollX,scrollY);
        }
    }
    else if(keys & KEY_DOWN)
    {
        if(scrollY <tilemapHeight-GBA_SCREEN_HEIGHT)
        {
            scrollY++;
            bg1.get()->scroll(scrollX,scrollY);
        }
    }
    else if (keys & KEY_UP)
    {
        if (scrollY > 0) {
            scrollY--;
            bg1.get()->scroll(scrollX, scrollY);
        }
    }
    else if(keys & KEY_START) {
        if (!engine->isTransitioning()) {


            engine->transitionIntoScene(new SecondScene(engine), new FadeOutScene(2));
        }
    }


}