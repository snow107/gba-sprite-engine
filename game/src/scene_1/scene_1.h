//
// Created by jelle on 2019/11/28.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H

#include <libgba-sprite-engine/scene.h>
#include "../GenericScene.h"
#include "Main_level.h"
#include "map/testmap.h"
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#define COLLISIONARRAYSIZE 6


class scene_1 : public  GenericScene{
    private:
        std::unique_ptr<Background> bg2;
        std::unique_ptr<Sprite> ster;

    public:
        std::vector<Sprite *> sprites() override;
        std::vector<Background *> backgrounds() override;

        scene_1(std::shared_ptr<GBAEngine> engine) : GenericScene(engine, Main_level_Map_Whith,
                                                                  Main_level_Map_Height,20,150, Main_level) {}

        void load() override;
        void onTick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H
