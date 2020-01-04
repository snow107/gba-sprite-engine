//
// Created by jelle on 2019/11/28.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H

#include <libgba-sprite-engine/scene.h>
#include "../GenericScene.h"
#include "Main_level.h"

#define CHARTER_X_OFFSET 8 // pixels vanaf links getelt
#define CHARTER_Y_OFFSET 3 //pixels vanaf boven geteld

#define CHARTERHEIGTH 26 //pixels
#define CHARTERWIDTH 16 //pixels

#define SCENE_WIDTH 64 //tiles
#define SCENE_HEIGTH 32 //tiles


#define COLLISIONARRAYSIZE 6


class scene_1 : public  GenericScene{
    private:
        std::unique_ptr<Background> bg2;

    public:
        std::vector<Sprite *> sprites() override;
        std::vector<Background *> backgrounds() override;

        scene_1(std::shared_ptr<GBAEngine> engine) : GenericScene(engine, SCENE_WIDTH,
                                                                  SCENE_HEIGTH, CHARTERWIDTH,
                                                                  CHARTERHEIGTH, CHARTER_X_OFFSET, CHARTER_Y_OFFSET,
                                                                  Main_level) {}

        void load() override;
        void onTick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H
