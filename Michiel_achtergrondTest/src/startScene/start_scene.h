//
// Created by michi on 5/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_START_SCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_START_SCENE_H


#include <libgba-sprite-engine/scene.h>


class BeginScene : public Scene {
private:

    std::unique_ptr<Background> bg1;
    std::unique_ptr<Background> bg2;
    std::unique_ptr<Background> bg3;
    int scrollX=0,scrollY=0;



public:

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    BeginScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;

};
#endif //GBA_SPRITE_ENGINE_PROJECT_START_SCENE_H
