//
// Created by jelle on 2020/01/04.
//

#include "scene_2.h"

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "../scene_start/mainCharcters.h"
#include "../scene_1/Main_background.h"
#include "map/mapScene2.h"
#include "../Tileset/tileset.h"
#include "../scene_1/scene_1.h"
#include "../scene_start/sonic_smaller16pixelsBreed.h"



std::vector<Background *> scene_2::backgrounds() {
    return {bg1.get(),bg2.get()};
}

std::vector<Sprite *> scene_2::sprites() {
    return {charcter.get()};
}

void scene_2::load() {
    engine.get()->disableText();

    foregroundPalette=std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sonic_smaller16pixelsBreedPal, sizeof(sonic_smaller16pixelsBreedPal)));
    backgroundPalette=std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(Pal_transPal, sizeof(Pal_transPal)));
    bg1=std::unique_ptr<Background>(CreateBackground(1, Pal_transTiles, sizeof(Pal_transTiles), mapScene2, sizeof(mapScene2), MAP64X64));
    bg2=std::unique_ptr<Background>(CreateBackground(2,Pal_transTiles, sizeof(Pal_transTiles),Main_background,sizeof(Main_background),MAP32X32));

  //  charcterX = 20;
 //   charcterY = 50;
  //  bg1X = 0;
 //   bg1Y = 5;
    v1Y =0;v1X=0;
   x=0,y=0;
    bg1.get()->scroll(bg1X,bg1Y);

    SpriteBuilder<Sprite> builder;

    charcter = builder
            .withData(sonic_smaller16pixelsBreedTiles, sizeof(sonic_smaller16pixelsBreedTiles))
            .withSize(SIZE_16_32)
            .withAnimated(16,10)
            .withLocation(charcterX, charcterY)
            .buildPtr();
    charcter.get()->setStayWithinBounds(true);
}

void scene_2::onTick(u16 keys) {
    int collisionArray[] = {0x07, 0x08,0x18,0x02,0x09,0x0A};
   if (!(ticknumber % 5)) {
        for (int i = 0; i < COLLISIONARRAYSIZE; ++i) {
            if (charcterOnTile(collisionArray[i]) || charterAgainstTile(true, collisionArray[i]) ||
               charterAgainstTile(false, collisionArray[i])) {
               engine->transitionIntoScene(new scene_1(engine), new FadeOutScene(2));
               //you died
            }
       }
   }

}