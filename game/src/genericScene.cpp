//
// Created by jelle on 2019/11/29.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "genericScene.h"

std::unique_ptr<Background> genericScene::createBackground(std::unique_ptr<Background> background, int welke, const unsigned short *blockTiles,
                                    const unsigned short *tilemap) {
    background = std::unique_ptr<Background>(new Background(1, blockTiles, sizeof(blockTiles), tilemap, sizeof(tilemap)));
    background.get()->useMapScreenBlock(16);
    background.get()->getScreenBlock();
    return background;
}