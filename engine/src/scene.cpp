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

    int currentScreenBlock=screenblock;
    switch (grootte)
    {
        case 0:
            screenblock++;
        break;
        case 1:
            screenblock +=2;

        break;
        case 2:
            screenblock +=2;

        break;
        case 3:
            screenblock +=4;

        break;
    }
    return (new Background(bgIndex,data,size,map,mapSize,currentScreenBlock,charblock,grootte));
    

}
