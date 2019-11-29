//
// Created by jelle on 2019/11/29.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H

#include <libgba-sprite-engine/scene.h>

class genericScene {
public:
    static std::unique_ptr<Background> createBackground(std::unique_ptr<Background> Background, int welke,const unsigned short* blockTiles, const unsigned short* tilemap);
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
