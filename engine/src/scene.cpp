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

    switch (grootte)
    {
        case 0:
            screenblock++;
            return (new Background(bgIndex,data,size,map,mapSize,screenblock-1,charblock,grootte));
        case 1:
            screenblock +=2;
            return (new Background(bgIndex,data,size,map,mapSize,screenblock-2,charblock,grootte));

        case 2:
            screenblock +=3;
            return (new Background(bgIndex,data,size,map,mapSize,screenblock-2,charblock,grootte));
        case 3:
            screenblock +=4;
            return (new Background(bgIndex,data,size,map,mapSize,screenblock-4,charblock,grootte));
    }

}
