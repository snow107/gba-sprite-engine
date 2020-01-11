//
// Created by jelle on 2019/11/29.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "GenericScene.h"

void GenericScene::tick(u16 keys) {
    if (!(ticknumber % 5)) { //searching for better solution (ideas are welcome)
        if (keys & KEY_LEFT) {
            if (v1X > 0) {
                v1X -= 2;
            } else if (v1X > -5) {
                v1X -= 1;
            }
        } else if (keys & KEY_RIGHT) {
            if (v1X < 0) {
                v1X += 2;
            } else if (v1X < 5) {
                v1X += 1;
            }
        } else {
            if (v1X > 0) {
                v1X--;
            }
            if (v1X < 0) {
                v1X++;
            }
        }
        if (keys & KEY_START) {}
        if (!charcterOnGround()) {
            v1Y -= 1;
        }
        else{
            v1Y = 0;
            if (keys & KEY_UP) {
                v1Y += 4;
            }
        }
    }





    if (keys & KEY_DOWN) {

    } else if (keys & KEY_B) {
        movebg1(32,0); //test function
    } else if (keys & KEY_A) {
        backgroundPalette.get()->increaseBrightness(1);
    }

    if (v1X > 0) {
        charcter.get()->flipHorizontally(false);
    }
    if (v1X < 0) {
        charcter.get()->flipHorizontally(true);
    }
    if(v1X==0){
        charcter.get()->stopAnimating();
    } else{
        charcter.get()->animate();
    }


      if(charcteragainstwall(true ) && v1X > 0 )
    {
        v1X = 0;
    }

    if(charcteragainstwall(false ) && v1X < 0 )
    {
        v1X = 0;
    }

    move(v1X,v1Y);

    ticknumber++;

    onTick(keys);

}

bool GenericScene::charcterOnGround() {
    return charcterNotOnTile(0);
}

bool GenericScene::charcteragainstwall(bool right) { //otherwise left

    std::vector<unsigned short> tiles = tilesAgainstCharcter(right);
    for (int i = 0; i < tiles.size(); ++i) {
        if(tiles.data()[i] != 0){
            return true;
        }
    }
    return  false;

}

void GenericScene::movebg1(int x, int y){
    bg1X += x;
    bg1Y -= y;
    bg1.get()->scroll(bg1X,bg1Y);
}

void GenericScene::movecharcter(int x, int y) {
    charcterX += x;
    charcterY -= y;
    charcter.get()->moveTo(charcterX,charcterY);
}

int GenericScene::getBottemLeftCharcterTile() {
    int charctertileY = ((bg1Y + charcterY + Charcter_heigth) / 8)*Scene_width;
    int charctertileX = (bg1X + charcterX + Charcter_x_offset)/8;
    return charctertileX + charctertileY;
}

void GenericScene::move(int x, int y) {
//    if(((charcterY+Charcter_heigth+128) - bg1Y < GBA_SCREEN_HEIGHT)|| ((Scene_heigth*8)-bg1Y <= GBA_SCREEN_HEIGHT) )
//    {
//        movecharcter(0,y);
//    }
//    else
//    {
//        movebg1(0,y);
//    }
//    if(Scene_width + bg1X >= GBA_SCREEN_WIDTH && x > 0)
//    {
//        movecharcter(x,0);
//    }
//    else
//    {
//        movebg1(x,0);
//    }

 /*  if(x > 0) {
        if ((Scene_width * 8 >= bg1X + (GBA_SCREEN_WIDTH / 2)) || (charcterX < (GBA_SCREEN_WIDTH / 2))) {
            movecharcter(x, 0);
        } else {
            movebg1(x, 0);
        }
    }*/
 /*   if(x>0)
    {
       if((charcterX <=(GBA_SCREEN_WIDTH/2) ) || ((bg1X+ (GBA_SCREEN_WIDTH))  >=Scene_width*8))
        {
            movecharcter(x,0);
        }
        else
        {
           movebg1(x,0);
        }


    }

    if(x < 0)
    {
        if((charcterX <=(GBA_SCREEN_WIDTH/2) ) || ((bg1X+ (GBA_SCREEN_WIDTH))  >=Scene_width*8))
        {
            movecharcter(x, 0);
        } else {
            movebg1(x, 0);
        }
    }

    if(y<0)
    {
        if ((Scene_heigth * 8 <= bg1Y + GBA_SCREEN_HEIGHT) || charcterY < GBA_SCREEN_HEIGHT / 2) {
            movecharcter(0, y);
        } else {
            movebg1(0, y);
        }
    }

    if(y > 0)
    {
        if(bg1Y <= 0 || charcterY > GBA_SCREEN_HEIGHT / 2)
        {
            movecharcter(0, y);
        }
        else {
            movebg1(0, y);
        }
    }*/

        if((charcterX+15) < (GBA_SCREEN_WIDTH/2) && (bg1X==0)) {
            charcterX += x;
            if (charcterX +16>= (GBA_SCREEN_WIDTH / 2)) {
                charcterX = (GBA_SCREEN_WIDTH / 2)-16;
            }
        }
        if((charcterX+16 )== (GBA_SCREEN_WIDTH/2) && (bg1X<Scene_width*8-GBA_SCREEN_WIDTH)) {
            bg1X += x;
            if((bg1X+GBA_SCREEN_WIDTH>=Scene_width*8)){
                bg1X=Scene_width*8-GBA_SCREEN_WIDTH;
            }
            if(bg1X<0)bg1X=0;
        }
        if((charcterX+16)>=(GBA_SCREEN_WIDTH/2) && (bg1X==Scene_width*8-GBA_SCREEN_WIDTH))
        {
            charcterX+=x;
            if(charcterX+16<=GBA_SCREEN_WIDTH/2)
            {
                charcterX = (GBA_SCREEN_WIDTH / 2)-16;
                bg1X-=1;
            }
            if(charcterX+32 >= GBA_SCREEN_WIDTH) charcterX=GBA_SCREEN_WIDTH-32;
        }
     //   if(bg1X)

    charcter.get()->moveTo(charcterX,charcterY);
    bg1.get()->scroll(bg1X,bg1Y);
}

int GenericScene::getTilenumber(int tilex, int tiley) {
    int tile = tilex + tiley*32;
    if (tilex >= 32){
        tile += 0x03E0;;
    }
    if(tiley >= 32 && Scene_heigth == 64 && Scene_width == 64)
    {
        tile += 0x0400;
    }
    return tile;
    //code used from: https://www.coranac.com/tonc/text/regbg.htm
}

std::vector<unsigned short> GenericScene::tilesBelowCharcter() {
    std::vector< unsigned short> tiles;
    for (int i = 0; i < Charcter_width/8; ++i) {
        tiles.push_back(Level_Tiles[getTilenumber(getCharcterXTile() + i, getCharcterYTile() + (Charcter_heigth + Charcter_y_offset) / 8)]);
    }
    return tiles;
}

std::vector<unsigned short> GenericScene::tilesAgainstCharcter(bool right) {

    std::vector< unsigned short> tiles;
    if (right) {
        for (int i = 0; i < Charcter_heigth / 8; i++) {
            tiles.push_back(Level_Tiles[getTilenumber(getCharcterXTile() + (Charcter_width) / 8 + 1, getCharcterYTile() + i)]);
        }
    }
    else {
        for (int i = 0; i < Charcter_heigth / 8; ++i) {
            tiles.push_back(Level_Tiles[getTilenumber(getCharcterXTile() - 1, getCharcterYTile() + i)]);
        }
    }

    return tiles;
}

bool GenericScene::charcterOnTile(unsigned short tilenumber){ //returns true if charcters stands on this tile
    std::vector<unsigned short> tiles = tilesBelowCharcter();
    for (int i = 0; i < tiles.size(); ++i) {
        if(tiles.data()[i] == tilenumber){
            return true;
        }
    }
    return  false;
}

bool GenericScene::charcterNotOnTile(unsigned short tilenumber){ //returns true if charcters stands on this tile
    std::vector<unsigned short> tiles = tilesBelowCharcter();
    for (int i = 0; i < tiles.size(); ++i) {
        if(tiles.data()[i] != tilenumber){
            return true;
        }
    }
    return  false;
}


unsigned short GenericScene::getCharcterXTile(){
    return (bg1X+charcterX+Charcter_x_offset)/8;
}

unsigned short GenericScene::getCharcterYTile(){
    return (bg1Y+charcterY+Charcter_y_offset)/8;
}

bool GenericScene::charterAgainstTile(bool right, int tilenumber) {
    std::vector<unsigned short> tiles = tilesAgainstCharcter(right);
    for (int i = 0; i < tiles.size(); ++i) {
        if(tiles.data()[i] == tilenumber){
            return true;
        }
    }
    return  false;
}

bool GenericScene::charterNotAgainstTile(bool right, int tilenumber) {
    std::vector<unsigned short> tiles = tilesAgainstCharcter(right);
    for (int i = 0; i < tiles.size(); ++i) {
        if(tiles.data()[i] != tilenumber){
            return true;
        }
    }
    return  false;
}