//
// Created by jelle on 2020/01/04.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_2_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_2_H

#include "../GenericScene.h"
#include "../maps/mapScene2.h"




#define star2X 222
#define star2Y 40
#define reset2X 0
#define  reset2Y 0


class scene_2 : public  GenericScene{
    private:
    std::unique_ptr<Background> bg2;

    public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    scene_2(std::shared_ptr<GBAEngine> engine) : GenericScene(engine, mapScene2_width,
                                                              mapScene2_height, reset2X, reset2Y, star2X, star2Y, mapScene2) {}

    void load() override;
    void onTick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SCENE_2_H
