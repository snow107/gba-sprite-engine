//
// Created by jelle on 2019/11/28.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H


#include "../GenericScene.h"
#include "../maps/mapScene1.h"


#define STAR1X 222
#define STAR1Y 80
#define RESET1X 0
#define RESET1Y 170

class scene_1 : public  GenericScene{
    private:
        std::unique_ptr<Background> bg2;


    public:
        std::vector<Sprite *> sprites() override;
        std::vector<Background *> backgrounds() override;

        scene_1(std::shared_ptr<GBAEngine> engine) : GenericScene(engine, MAP_LEVEL1_WIDTH,
                                                                  MAP_LEVEL1_HEIGHT, RESET1X, RESET1Y, STAR1X, STAR1Y, Main_level) {}

        void load() override;
        void onTick(u16 keys) override;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H
