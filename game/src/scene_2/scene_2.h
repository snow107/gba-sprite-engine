//
// Created by jelle on 2020/01/04.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_2_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_2_H

#include "../GenericScene.h"
#include "../maps/mapScene2.h"




#define STAR2X 222
#define STAR2Y 40
#define RESET2X 0
#define RESET2Y 0


class scene_2 : public  GenericScene{
    private:
    std::unique_ptr<Background> bg2;

    public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    scene_2(std::shared_ptr<GBAEngine> engine) : GenericScene(engine, MAP_LEVEL2_WIDTH,
                                                              MAP_LEVEL2_HEIGHT, RESET2X, RESET2Y, STAR2X, STAR2Y, mapScene2) {}

    void load() override;
    void onTick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SCENE_2_H
