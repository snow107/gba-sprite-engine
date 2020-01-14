//
// Created by michi on 14/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_4_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_4_H

#include "../GenericScene.h"
//#include "map/mapScene2.h"
//#include "../scene_3/map/maptest6464.h"
#include "map/mapScene4.h"
#include "map/mapScene4water.h"



#define star4X 0
#define star4Y 200


class scene_4 : public  GenericScene{
private:
    std::unique_ptr<Background> bg2,bg0;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    scene_4(std::shared_ptr<GBAEngine> engine) : GenericScene(engine, mapScene4_width,
                                                              mapScene4_height, 0, 0, star4X, star4Y, mapScene4) {}

    void load() override;
    void onTick(u16 keys) override;
};








#endif //GBA_SPRITE_ENGINE_PROJECT_SCENE_4_H
