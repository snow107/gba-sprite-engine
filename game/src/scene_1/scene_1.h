//
// Created by jelle on 2019/11/28.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H

#include <libgba-sprite-engine/scene.h>


class scene_1 : public Scene {
    private:
        std::unique_ptr<Sprite> sonic;
        std::unique_ptr<Background> bg1;
        int bg1X,bg1Y;
        int v1X,v1Y;

    public:
        std::vector<Sprite *> sprites() override;
        std::vector<Background *> backgrounds() override;

        scene_1(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

        void load() override;
        void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H
