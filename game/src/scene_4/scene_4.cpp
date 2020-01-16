//
// Created by michi on 14/01/2020.
//

#include "scene_4.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "../maps/backgroundCity.h"
#include "../maps/mapScene4water.h"

#include "../sprites/sprites.h"
#include "../end_scene/end_scene.h"
#include "../Tileset/tilesSpel.h"


std::vector<Background *> scene_4::backgrounds() {
    return {bg1.get(),bg2.get(),bg0.get()};
}

std::vector<Sprite *> scene_4::sprites() {
    return {charcter.get(),kurby.get()};
}

void scene_4::load() {
    engine.get()->disableText();

    foregroundPalette=std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette=std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(tilesSpelPal, sizeof(tilesSpelPal)));
    bg0=std::unique_ptr<Background>(CreateBackground(0, tilesSpelTiles, sizeof(tilesSpelTiles),mapScene4water , sizeof(mapScene4water), MAP64X64));
    bg1=std::unique_ptr<Background>(CreateBackground(1, tilesSpelTiles, sizeof(tilesSpelTiles),mapScene4 , sizeof(mapScene4), MAP64X64));
    bg2=std::unique_ptr<Background>(CreateBackground(2,tilesSpelTiles, sizeof(tilesSpelTiles),Main_background,sizeof(Main_background),MAP32X32));
    x=RESET4X;y=RESET4Y;
    v1Y =0;v1X=0;
    yHoogte=0;
    engine.get()->getTimer()->reset();
    engine.get()->getTimer()->start();
    bg0.get()->scroll(0, MAP_LEVEL4_WATER_HEIGHT * 8 - GBA_SCREEN_HEIGHT * 2 + 4);//196
    starActive=false;

    SpriteBuilder<Sprite> builder;

    charcter = builder
            .withData(sonicTiles, sizeof(sonicTiles))
            .withSize(SIZE_16_32)
            .withAnimated(16,10)
            .withLocation(charcterX, charcterY)
            .buildPtr();
    charcter.get()->setStayWithinBounds(true);
    kurby = builder
            .withData(kurbyTiles, sizeof(kurbyTiles))
            .withSize(SIZE_32_32)
            .withAnimated(12,10)
            .withLocation(kurbyX, kurbyY)
            .buildPtr();
}

void scene_4::onTick(u16 keys) {
   timerOld=timerNieuw;
    timerNieuw =(int)engine.get()->getTimer()->getSecs()+(int)engine->getTimer()->getMinutes()*60;
    if((timerNieuw != timerOld) && (timerNieuw>7)) {
        yHoogte += 8;
    }
   if(yHoogte > MAP_LEVEL4_HEIGHT * 8){ yHoogte= MAP_LEVEL4_HEIGHT * 8;}//512 is afstand afleggen 160+bg1Y in dit geval 352 = 64*8-160
   bg0Y= MAP_LEVEL4_WATER_HEIGHT * 8 - GBA_SCREEN_HEIGHT * 2 + 4 + yHoogte - (MAP_LEVEL4_HEIGHT * 8 - GBA_SCREEN_HEIGHT - bg1Y);//352 afstand bg1y get locked
   if(bg0Y<0){bg0Y=0;}
    bg0.get()->scroll(0,bg0Y);
   if(yHoogte>=64*8-(y+32))
   {
       if (!engine->isTransitioning()) {
           bg0Y = 0;
           engine->transitionIntoScene(new scene_4(engine), new FadeOutScene(2));
       }
   }
    if(bg1X>=64*8-GBA_SCREEN_WIDTH-32 && bg1Y<=GBA_SCREEN_HEIGHT/2-56)
    {
        kurby.get()->moveTo(64*8-GBA_SCREEN_WIDTH-bg1X+kurbyX+1,64*8-GBA_SCREEN_HEIGHT-89-bg1Y+kurbyY);
    }
    else kurby.get()->moveTo(0,200);

    if(charcter.get()->collidesWith(*kurby.get())){
        if (!engine->isTransitioning()) {
            engine->transitionIntoScene(new end_scene(engine), new FadeOutScene(2));
        }
    }
    if(x>64*8-50 && y<17){ //bovenstaand werkt niet voor een onbekende reden
        if (!engine->isTransitioning()) {
            engine->transitionIntoScene(new end_scene(engine), new FadeOutScene(2));
        }
    }


    if (keys & KEY_START) {
        engine->transitionIntoScene(new end_scene(engine), new FadeOutScene(2));

    }
}