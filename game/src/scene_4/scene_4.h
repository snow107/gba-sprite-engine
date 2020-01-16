//
// Created by michi on 14/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_4_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_4_H

#include "../GenericScene.h"
#include "../maps/mapScene4.h"




#define star4X 0
#define star4Y 200
#define reset4X 88//420 test
#define reset4Y 0


class scene_4 : public  GenericScene{
private:
    std::unique_ptr<Background> bg2,bg0;
    std::unique_ptr<Sprite> kurby;
    int kurbyX=240-32,kurbyY=16;
    int bg0Y=64*8-160-160+9*8;//152/20
    int timerNieuw;
    int timerOld;
    int yHoogte;
public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    scene_4(std::shared_ptr<GBAEngine> engine) : GenericScene(engine, mapScene4_width,
                                                              mapScene4_height, reset4X, reset4Y, star4X, star4Y, mapScene4) {}

    void load() override;
    void onTick(u16 keys) override;
};








#endif //GBA_SPRITE_ENGINE_PROJECT_SCENE_4_H
