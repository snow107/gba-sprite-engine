//
// Created by jelle on 2019/11/29.
//
#include <array>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "GenericScene.h"

void GenericScene::tick(u16 keys) {
    onTick(keys);
    //keys inlezen en snelheid zetten
        if (keys & KEY_LEFT) {
//
           v1X-=1;     // v1X=-1;

            if(v1X<5){v1X=-5;}

        }
        else if (keys & KEY_RIGHT) {
            v1X+=1;
         //  v1X=1;
            if(v1X>5){v1X=+5;}

        }
        else{
            v1X--;
            if(v1X<0){v1X=0;}
        }
        if(charcterVerticalcheck(0))
        {
            v1Y++;
        }
        else
        {
            v1Y=0;
        }
        if(keys & KEY_UP && !charcterVerticalcheck(0)){

            v1Y=-8; //naar 6 voor 3
        }
    //kijken als nieuwe locatie mag
        collisionBewegen(v1X,v1Y);
        if (v1X > 0) {
            charcter.get()->flipHorizontally(false);
        }
        if (v1X < 0) {
            charcter.get()->flipHorizontally(true);
        }
        if (v1X == 0) {
            charcter.get()->stopAnimating();
           // charcter.get()->animateToFrame(8);
        }
        else {
            charcter.get()->animate();

        } if (keys & KEY_A) {
            backgroundPalette.get()->increaseBrightness(1);
        }
}
void GenericScene::collisionBewegen(int speedX,int speedY){

    int grootsteSnelheid =abs(speedX);
    if(abs(speedY)>abs(speedX)){grootsteSnelheid=abs(speedY);}
    for(int i=0;i<grootsteSnelheid;i++)
    {
        if(i<abs(speedX))
        {
            if(speedX>0)
            {
                if(charcteraHorizontaalCheck(0)){x+=1;}
            }
            if(speedX<0)
            {
                if(charcteraHorizontaalCheck(0)){x-=1;}
            }
        }
        if(i<abs(speedY))
        {
            if(speedY>0)
            {
                if(charcterVerticalcheck(0)){y+=1;};
            }
            if(speedY<0)
            {
                if(charcterVerticalcheck(0)){y-=1;};
            }

        }
        if(dead){y=resetY;x=resetX;dead=false;v1X=0;v1Y=0;}
        move();
    }
}
bool GenericScene::charcteraHorizontaalCheck(int tileNumber){
    if(v1X<0)//left
    {

        std::vector< unsigned short> tiles;

        tiles.push_back(Level_Tiles[getTilenumber((x-1)/8,(y+1)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x-1)/8,(y+9)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x-1)/8,(y+17)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x-1)/8,(y+25)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x-1)/8,(y+Charcter_height-1)/8)]);
        for(int k=0;k<6;k++)
        {
            for (int j=0;j<tiles.size();j++)
            {
                if(tiles.data()[j]== collisionArray[k])
                {
                    dead=true;
                }
            }
        }
        for (int i = 0; i < tiles.size(); ++i) {
            if(tiles.data()[i] != tileNumber){
                return false;
            }

        }
    }
    if(v1X>0)//right
    {
        std::vector< unsigned short> tiles;
        tiles.push_back(Level_Tiles[getTilenumber((x+Charcter_width)/8,(y+1)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x+Charcter_width)/8,(y+9)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x+Charcter_width)/8,(y+17)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x+Charcter_width)/8,(y+25)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x+Charcter_width)/8,(y+Charcter_height-1)/8)]);
        for(int k=0;k<6;k++)
        {
            for (int j=0;j<tiles.size();j++)
            {
                if(tiles.data()[j]== collisionArray[k])
                {
                    dead=true;
                }
            }
        }
        for (int i = 0; i < tiles.size(); ++i) {
            if(tiles.data()[i] != tileNumber){
                return false;
            }

        }
    }
    return true;
}

bool GenericScene::charcterVerticalcheck(int tileNumber){
    if(v1Y>0) //omlaag
    {
        std::vector< unsigned short> tiles;
        tiles.push_back(Level_Tiles[getTilenumber(((x+1)/8),(y+Charcter_height)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber(((x+9)/8),(y+Charcter_height)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber(((x+Charcter_width-1)/8),(y+Charcter_height)/8)]);
        for(int k=0;k<COLLISIONARRAYSIZE;k++)
     //  for(auto &k:collisionArray)
        {
            for (int j=0;j<tiles.size();j++)
            {
                if(tiles.data()[j]== collisionArray[k])
                {
                    dead=true;
                }
            }
        }
        for (int i = 0; i < tiles.size(); ++i) {
            if (tiles.data()[i] != tileNumber) {
                return false;
            }
        }
    }
    if(v1Y<0)//omhoog
    {
        std::vector< unsigned short> tiles;
        tiles.push_back(Level_Tiles[getTilenumber((x+1)/8,(y-1)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x+9)/8,(y-1)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x+Charcter_width-1)/8,(y-1)/8)]);
        for(int k=0;k<6;k++)
        {
            for (int j=0;j<tiles.size();j++)
            {
                if(tiles.data()[j]== collisionArray[k])
                {
                    dead=true;
                }
            }
        }
        for (int i = 0; i < tiles.size(); ++i) {
            if (tiles.data()[i] != tileNumber) {
                return false;
            }
        }
    }
    return true;
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
void GenericScene::deadCheck() {
    int collisionArray[] = {0x07, 0x08,0x18,0x02,0x09,0x0A};
    for(int i=0;i<6;i++)
    {
        if(!charcterVerticalcheck(collisionArray[i]))
        {
            dead=true;
        }
    /*    if(!charcteraHorizontaalCheck(collisionArray[i]))
        {
            dead =true;
        }*/
    }
}

std::vector<unsigned short> GenericScene::tilesBelowCharcter() {

    int charXtile = getCharcterXTile();
    int charYtile = getCharcterYTile();
    std::vector<unsigned short> tiles;
    for (int i = 0; i < 16 / 8; ++i) { //char with
        //  tiles.push_back(Level_Tiles[getTilenumber(getCharcterXTile() + i, getCharcterYTile() + (Charcter_heigth + Charcter_y_offset) / 8)]);
        tiles.push_back(Level_Tiles[getTilenumber(charXtile + 1 + i, charYtile + 1)]);
    }
    return tiles;
}
unsigned short GenericScene::getCharcterXTile(){

    return(bg1X+charcterX)/8;
}

unsigned short GenericScene::getCharcterYTile(){
    return (bg1Y+charcterY+24)/8;

}

std::vector<unsigned short> GenericScene::tilesAgainstCharcter(bool right) {
    int charXtile=getCharcterXTile();
    int charYtile=getCharcterYTile();
    std::vector< unsigned short> tiles;
    if (right) {
        for (int i = 0; i < 32 / 8; i++) { //char height
            //      tiles.push_back(Level_Tiles[getTilenumber(getCharcterXTile() + (Charcter_width) / 8 + 1, getCharcterYTile() + i)]);
            tiles.push_back(Level_Tiles[getTilenumber((x+16)/8, charYtile- i)]);
        }
    }
    else {
        for (int i = 0; i < 32 / 8; ++i) { //char height
            //    tiles.push_back(Level_Tiles[getTilenumber(getCharcterXTile() - 1, getCharcterYTile() + i)]);
            tiles.push_back(Level_Tiles[getTilenumber(charXtile , charYtile - i)]);
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
bool GenericScene::charterAgainstTile(bool right, int tilenumber) {
    std::vector<unsigned short> tiles = tilesAgainstCharcter(right);
    for (int i = 0; i < tiles.size(); ++i) {
        if(tiles.data()[i] == tilenumber){
            return true;
        }
    }
    return  false;
}
void GenericScene::move() {

      // beneath code used from  https://wiki.nycresistor.com/wiki/GB101:Collision_Detection for moving bg1 or char
  if (x < 0)
        x = 0;
    else if (x+16> Scene_width*8)
        x = Scene_width*8-16;

   if (y < 0)
        y = 0;
    else if (y+32 > Scene_heigth*8)
        y = Scene_heigth*8-32;

    // If we're in the 1st quarter, lock the window on 0 and move the sprite
    if (x < GBA_SCREEN_WIDTH/2) {
        bg1X = 0;
        charcterX = x;
    }
        // If we're in the 4th quarter, lock the window as far as possible
        // without looping and move the sprite
    else if (x > Scene_width*8-GBA_SCREEN_WIDTH/2) {
        bg1X=Scene_width*8-GBA_SCREEN_WIDTH;
        charcterX=x-bg1X;

    }

    else {
        bg1X=x-GBA_SCREEN_WIDTH/2;
       charcterX=GBA_SCREEN_WIDTH/2;
    }

    if (y < GBA_SCREEN_HEIGHT/2-56) {
        bg1Y = 0;
        charcterY = y;
    }
        // If we're too close to the bottom, lock the screen and move the sprite
    else if (y > Scene_heigth*8-(GBA_SCREEN_HEIGHT/2)-56) {
        bg1Y = Scene_heigth*8-GBA_SCREEN_HEIGHT;
        charcterY = y - bg1Y;
    }
        // Lock the sprite and move the screen otherwise
    else {
        bg1Y = y - GBA_SCREEN_HEIGHT/2+56;
        charcterY = GBA_SCREEN_HEIGHT/2-56;
    }
   // end code used from  https://wiki.nycresistor.com/wiki/GB101:Collision_Detection



    charcter.get()->moveTo(charcterX,charcterY);
    bg1.get()->scroll(bg1X,bg1Y);
}

