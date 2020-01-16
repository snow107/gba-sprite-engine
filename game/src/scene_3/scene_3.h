//
// Created by michi on 14/01/2020.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_3_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_3_H




#include "../GenericScene.h"
#include "../maps/mapScene3.h"



#define STAR3X 222
#define STAR3Y 136
#define RESET3X 0
#define RESET3Y 460


class scene_3 : public  GenericScene{
private:
    std::unique_ptr<Background> bg2;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    scene_3(std::shared_ptr<GBAEngine> engine) : GenericScene(engine, MAP_LEVEL3_WIDTH,
                                                              MAP_LEVEL3_HEIGHT, RESET3X, RESET3Y, STAR3X, STAR3Y, mapScene3) {}

    void load() override;
    void onTick(u16 keys) override;
};





#endif //GBA_SPRITE_ENGINE_PROJECT_SCENE_3_H
