//
// Created by michi on 5/12/2019.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H

#endif //GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H
#include <libgba-sprite-engine/scene.h>

class SecondScene : public Scene
{
private :
    int scrollX=0,scrollY=0;
    std:: unique_ptr<Background> bg1,bg2;

public:

    std :: vector< Sprite *> sprites() override;
    std :: vector<Background *>backgrounds() override;

    SecondScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override ;

};