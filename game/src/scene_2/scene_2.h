//
// Created by jelle on 2020/01/04.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_2_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_2_H

#include "../GenericScene.h"
#include "map/mapScene2.h"

#define CHARTER_X_OFFSET 6 // pixels vanaf links getelt
#define CHARTER_Y_OFFSET 3 //pixels vanaf boven geteld

#define CHARTERHEIGTH 26 //pixels
#define CHARTERWIDTH 20 //pixels


class scene_2 : public  GenericScene{
    private:
    std::unique_ptr<Background> bg2;

    public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    scene_2(std::shared_ptr<GBAEngine> engine) : GenericScene(engine, 64,
            64, CHARTERWIDTH,
            CHARTERHEIGTH, CHARTER_X_OFFSET, CHARTER_Y_OFFSET,
            mapScene2) {}

    void load() override;
    void onTick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SCENE_2_H
