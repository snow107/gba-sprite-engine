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
    int static screenblock=0,charblock=2;
    switch (grootte)
    {
        case 0:
            screenblock++;
            return (new Background(bgIndex,data,size,map,mapSize,screenblock,charblock,grootte));

        case 1:
            screenblock +=2;
            return (new Background(bgIndex,data,size,map,mapSize,screenblock,charblock,grootte));

        case 2:
            screenblock +=2;
            return (new Background(bgIndex,data,size,map,mapSize,screenblock,charblock,grootte));
        case 3:
            screenblock +=4;
            return (new Background(bgIndex,data,size,map,mapSize,screenblock,charblock,grootte));
    }
}
