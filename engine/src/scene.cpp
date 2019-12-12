//
// Created by Wouter Groeneveld on 09/08/18.
//

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/background.h>


void Scene::addSprite(Sprite *sprite) {
    engine->dynamicallyAddSprite(sprite);
}

Background *Scene::CreateBackground(int bgIndex, const void *data, int size, const void *map, int mapSize, int grootte) {

    int currentScreenBlock=screenBlock;
    switch (grootte)
    {
        case 0:
            screenBlock++;
        break;
        case 1:
            screenBlock +=2;

        break;
        case 2:
            screenBlock +=2;

        break;
        case 3:
            screenBlock +=4;

        break;
    }
    if(screenBlock >= 16)
    {
        throw std::runtime_error("screenBlock index 16 is the same place in the memory as the charBlock index 2");
    }
    return (new Background(bgIndex, data, size, map, mapSize, currentScreenBlock, charBlock, grootte));


}
