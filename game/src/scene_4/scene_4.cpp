//
// Created by michi on 14/01/2020.
//

#include "scene_4.h"
#include "../end_scene/end_scene.h"
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "../scene_1/Main_background.h"
#include "../sprites/shared_star_circle_sonic.h"
#include "../sprites/sonic_for_star_circle.h"
#include "../Tileset/tilesSpel.c"


std::vector<Background *> scene_4::backgrounds() {
    return {bg1.get(),bg2.get(),bg0.get()};
}

std::vector<Sprite *> scene_4::sprites() {
    return {charcter.get()};
}

void scene_4::load() {
    engine.get()->disableText();

    foregroundPalette=std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    backgroundPalette=std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(tilesSpelPal, sizeof(tilesSpelPal)));
    bg0=std::unique_ptr<Background>(CreateBackground(0, tilesSpelTiles, sizeof(tilesSpelTiles),mapScene4water , sizeof(mapScene4water), MAP64X64));
    bg1=std::unique_ptr<Background>(CreateBackground(1, tilesSpelTiles, sizeof(tilesSpelTiles),mapScene4 , sizeof(mapScene4), MAP64X64));
    bg2=std::unique_ptr<Background>(CreateBackground(2,tilesSpelTiles, sizeof(tilesSpelTiles),Main_background,sizeof(Main_background),MAP32X32));
    x=resetX;y=resetY;
    v1Y =0;v1X=0;
    yHoogte=0;
    engine.get()->getTimer()->reset();
    engine.get()->getTimer()->start();
    bg0.get()->scroll(0,mapScene4water_height*8-GBA_SCREEN_HEIGHT*2+4);//196



    starActive=false;

    SpriteBuilder<Sprite> builder;

    charcter = builder
            .withData(sonicTiles, sizeof(sonicTiles))
            .withSize(SIZE_16_32)
            .withAnimated(16,10)
            .withLocation(charcterX, charcterY)
            .buildPtr();
    charcter.get()->setStayWithinBounds(true);


}

void scene_4::onTick(u16 keys) {
   timerOld=timerNieuw;
    timerNieuw =(int)engine.get()->getTimer()->getSecs()+(int)engine->getTimer()->getMinutes()*60;
    if((timerNieuw != timerOld) && (timerNieuw>5)) {
        yHoogte += 8;
    }
       if(yHoogte>mapScene4_height*8){yHoogte=mapScene4_height*8;}//512 is afstand afleggen 160+bg1Y in dit geval 352 = 64*8-160
       bg0Y=mapScene4water_height*8-GBA_SCREEN_HEIGHT*2+4+yHoogte-(mapScene4_height*8-GBA_SCREEN_HEIGHT-bg1Y);//352 afstand bg1y get locked
       if(bg0Y<0){bg0Y=0;}
        bg0.get()->scroll(0,bg0Y);
       if(yHoogte>=64*8-(y+32))
       {
           if (!engine->isTransitioning()) {
               engine->transitionIntoScene(new scene_4(engine), new FadeOutScene(2));
           }
       }
       if (keys & KEY_START) {
           engine->transitionIntoScene(new end_scene(engine), new FadeOutScene(2));
       }

}