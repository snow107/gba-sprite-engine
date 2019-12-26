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
    if (!(ticknumber % 20)) { //searching for better solution (ideas are welcome)
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
    }

    if (keys & KEY_START) {

    } else if (keys & KEY_UP) {
        if (charcterOnGround()) {
            v1Y = 4;
            movebg1(0, 5);
        }
    } else if (keys & KEY_DOWN) {

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

    if (!charcterOnGround()) {
        if (!(ticknumber % 5))
            v1Y -= 1;
    } else {
        v1Y = 0;
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
    int charctertileY = ((bg1Y + charcterY + CHARTERHEIGTH) / 8)*SCENE_WIDTH;
    int charctertileX = (bg1X + charcterX + CHARTER_X_OFFSET)/8;
    return charctertileX + charctertileY;
}

void GenericScene::move(int x, int y) {
    if(((charcterY+CHARTERHEIGTH+128) - bg1Y < GBA_SCREEN_HEIGHT)|| ((SCENE_HEIGTH*8)-bg1Y <= GBA_SCREEN_HEIGHT) )
    {
        movecharcter(0,y);
    }
    else
    {
        movebg1(0,y);
    }
    if(SCENE_WIDTH + bg1X >= GBA_SCREEN_WIDTH && x > 0)
    {
        movecharcter(x,0);
    }
    else
    {
        movebg1(x,0);
    }
}

int GenericScene::getTilenumber(int tilex, int tiley) {
    int tile = tilex + tiley*32;
    if (tilex >= 32){
        tile += 0x03E0;;
    }
    if(tiley >= 32 && SCENE_HEIGTH == 64 && SCENE_WIDTH == 64)
    {
        tile += 0x0400;
    }
    return tile;
    //code used from: https://www.coranac.com/tonc/text/regbg.htm
}

std::vector<unsigned short> GenericScene::tilesBelowCharcter() {
    std::vector< unsigned short> tiles;
    for (int i = 0; i < CHARTERWIDTH/8; ++i) {
        tiles.push_back(Level_Tiles[getTilenumber(getCharcterXTile() + i, getCharcterYTile() + (CHARTERHEIGTH + CHARTER_Y_OFFSET) / 8)]);
    }
    return tiles;
}

std::vector<unsigned short> GenericScene::tilesAgainstCharcter(bool right) {

    std::vector< unsigned short> tiles;
    if (right) {
        for (int i = 0; i < CHARTERHEIGTH / 8; ++i) {
            tiles.push_back(Level_Tiles[getTilenumber(getCharcterXTile() + (CHARTERWIDTH) / 8 + 1, getCharcterYTile() + i)]);
        }
    }
    else {
        for (int i = 0; i < CHARTERHEIGTH / 8; ++i) {
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
    return (bg1X+charcterX+CHARTER_X_OFFSET)/8;
}

unsigned short GenericScene::getCharcterYTile(){
    return (bg1Y+charcterY+CHARTER_Y_OFFSET)/8;
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