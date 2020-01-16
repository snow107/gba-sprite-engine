//
// Created by jelle on 2019/11/29.
//
#include <array>

#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "GenericScene.h"

void GenericScene::tick(u16 keys) {
    onTick(keys);
    //keys inlezen en snelheid zetten
        if (keys & KEY_LEFT) {
           v1X-=1;
           if(v1X<5){v1X=-5;}
        }
        else if (keys & KEY_RIGHT) {
            v1X+=1;
            if(v1X>5)v1X=+5;
        }
        else{
            v1X--;
            if(v1X<0)v1X=0;
        }
        if(charcterVerticalcheck(0))v1Y++;
        else v1Y=0;
        if(keys & KEY_UP && !charcterVerticalcheck(0)){
           v1Y = -8;
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
                if(charcteraHorizontaalCheck(0))x+=1;
            }
            if(speedX<0)
            {
                if(charcteraHorizontaalCheck(0))x-=1;
            }
        }
        if(i<abs(speedY))
        {
            if(speedY>0)
            {
                if(charcterVerticalcheck(0))y+=1;
            }
            if(speedY<0)
            {
                if(charcterVerticalcheck(0))y-=1;
            }

        }
        move();
       if(specialjumpActive && specialjump)
       {
           v1Y=-14;
           specialjump=false;
           for(int j=0;j<abs(v1Y);j++)
           {
               if(charcterVerticalcheck(0))y-=1;
               move();
           }
       }
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
        deadCheck(tiles);
        if(groundCheck(tiles,tileNumber))return false;
    }
    if(v1X>0)//right
    {
        std::vector< unsigned short> tiles;
        tiles.push_back(Level_Tiles[getTilenumber((x+Charcter_width)/8,(y+1)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x+Charcter_width)/8,(y+9)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x+Charcter_width)/8,(y+17)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x+Charcter_width)/8,(y+25)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x+Charcter_width)/8,(y+Charcter_height-1)/8)]);
       deadCheck(tiles);
      if(groundCheck(tiles,tileNumber))return false;
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
        deadCheck(tiles);
        if(specialjumpActive) specialJumpCheck(tiles);
        if(groundCheck(tiles,tileNumber))return false;
    }
    if(v1Y<0)//omhoog
    {
        std::vector< unsigned short> tiles;
        tiles.push_back(Level_Tiles[getTilenumber((x+1)/8,(y-1)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x+9)/8,(y-1)/8)]);
        tiles.push_back(Level_Tiles[getTilenumber((x+Charcter_width-1)/8,(y-1)/8)]);
        deadCheck(tiles);
        if(groundCheck(tiles,tileNumber))return false;
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
bool GenericScene::groundCheck(std::vector<unsigned short> tiles,int tileNumber) {
    for (int i = 0; i < tiles.size(); ++i) {
        if (tiles.data()[i] != tileNumber)return true;
    }
    return false;
}
void GenericScene::deadCheck(std::vector<unsigned short> tiles) {
    for(int k=0;k<COLLISIONARRAYSIZE;k++)
    {
        for (int j=0;j<tiles.size();j++)
        {
            if(tiles.data()[j]== collisionArray[k])
            {
                y=resetY;x=resetX;
                v1X=0;v1Y=0;
            }
        }
    }
}
void GenericScene::specialJumpCheck(std::vector<unsigned short> tiles){
        for (int j=0;j<tiles.size();j++)
        {
            bool leftleg =false;
            bool rightleg=false;
            if(tiles.data()[j]== specialJumpArray[0])leftleg=true;
            if(tiles.data()[j+1]==specialJumpArray[1])rightleg=true;
            if(leftleg && rightleg){specialjump=true; break;}
        }
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

    if(starActive)
    {
        if(bg1X>=Scene_width*8-GBA_SCREEN_WIDTH-16 && bg1Y>=Scene_heigth*8-GBA_SCREEN_HEIGHT-16-80)
        {
            ster.get()->moveTo(Scene_width*8-GBA_SCREEN_WIDTH-bg1X+starX+1,Scene_heigth*8-GBA_SCREEN_HEIGHT-bg1Y+starY);
        }
        else ster.get()->moveTo(0,200);
    }
    charcter.get()->moveTo(charcterX,charcterY);
    bg1.get()->scroll(bg1X,bg1Y);
}

