//
// Created by jelle on 2019/11/17.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_START_SCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_START_SCENE_H

#include <libgba-sprite-engine/scene.h>

class start_scene : public Scene {
private:
    std::unique_ptr<Sprite> kurby;
    std::unique_ptr<Sprite> sonic;
    std::unique_ptr<Sprite> star;
    std::unique_ptr<Sprite> cicle;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    start_scene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_START_SCENE_H
