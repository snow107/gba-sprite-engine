//
// Created by jelle on 2019/11/29.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H

#include <libgba-sprite-engine/scene.h>

class genericScene : public Scene{
public:
    //std::unique_ptr<Sprite> kurby;
    //std::unique_ptr<Sprite> sonic;
    std::unique_ptr<Background> bg1;
    std::unique_ptr<Background> bg2;
    std::unique_ptr<Background> bg3;
    int bg1X,bg1Y,bg2X,bg2Y,bg3X,bg3Y;

//public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    genericScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
