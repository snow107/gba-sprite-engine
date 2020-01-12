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
    onTick(keys);
    //keys inlezen en snelheid zetten
        if (keys & KEY_LEFT) {
           v1X = -1;
        }
        else if (keys & KEY_RIGHT) {
            v1X =+1;
        }
        else{
            v1X=0;
        }

            v1Y= +1;

        if(keys & KEY_UP){
            v1Y= -1;
        }

    //kijken als nieuwe locatie mag
        collisionBewegen();
    if (keys & KEY_START) {}
        if (v1X > 0) {
            charcter.get()->flipHorizontally(false);
        }
        if (v1X < 0) {
            charcter.get()->flipHorizontally(true);
        }
        if (v1X == 0) {
            charcter.get()->stopAnimating();
            //charcter.get()->animateToFrame(5);
        }
        else {
            charcter.get()->animate();
        }if (keys & KEY_B) {
            movebg1(32, 0); //test function
        } if (keys & KEY_A) {
            backgroundPalette.get()->increaseBrightness(1);
        }



        move();


}
void GenericScene::collisionBewegen(){
    //loop voor meerde pixels tegelijk veranderen

   if(charcteraHorizontaalCheck()){x+=v1X;}
    if(charcterVerticalcheck()){y+=v1Y;};
  //  x+=v1X;
  // y+=v1Y;


}
bool GenericScene::charcteraHorizontaalCheck(){
    if(v1X<0)//left
    {
        //get tiles aan linkerkant op nieuwe positite x=x-v1X
        std::vector< unsigned short> tiles;

        for (int i = 0; i < 4 ; i++) { //char height
            tiles.push_back(Level_Tiles[getTilenumber((x-2-v1X)/8,(y+7)/8+i)]);
        }
        for (int i = 0; i < tiles.size(); ++i) { //nagaan als j ehier mag staan
            if(tiles.data()[i] != 0){
                return false;
            }
            //nagaan als je nu dood bent
        }
    }
    if(v1X>0)//right
    {
        //get tiles aan rechterkant op nieuwe positite x=x+v1X + dikte char
        std::vector< unsigned short> tiles;

            for (int i = 0; i < 4 ; i++) { //char height
                tiles.push_back(Level_Tiles[getTilenumber((x+15+v1X)/8,(y+7)/8+i)]);
            }
            for (int i = 0; i < tiles.size(); ++i) {
                if(tiles.data()[i] != 0){
                 return false;
                }
                //nagaan als je nu dood bent
            }
    }
    return true;
}

bool GenericScene::charcterVerticalcheck(){
    if(v1Y>0) //omlaag
    {
        std::vector< unsigned short> tiles;
        for (int i = 0; i < 3 ; i++) { //char height
            tiles.push_back(Level_Tiles[getTilenumber((x)/8+i,(y+31+v1Y)/8)]);
        }
        for (int i = 0; i < tiles.size(); ++i) {
            if (tiles.data()[i] != 0) {
                return false;
            }
        }
    }
    if(v1Y<0)//omhoog
    {
        std::vector< unsigned short> tiles;
        for (int i = 0; i < 3 ; i++) { //char height
            tiles.push_back(Level_Tiles[getTilenumber((x+7)/8+i,(y-v1Y)/8)]);
        }
        for (int i = 0; i < tiles.size(); ++i) {
            if (tiles.data()[i] != 0) {
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

std::vector<unsigned short> GenericScene::tilesBelowCharcter() {
    int charXtile=getCharcterXTile();
    int charYtile=getCharcterYTile();
    std::vector< unsigned short> tiles;
    for (int i = 0; i < 16/8; ++i) { //char with
        //  tiles.push_back(Level_Tiles[getTilenumber(getCharcterXTile() + i, getCharcterYTile() + (Charcter_heigth + Charcter_y_offset) / 8)]);
        tiles.push_back(Level_Tiles[getTilenumber(charXtile +1+ i, charYtile+1) ]);
    }
    return tiles;
}
unsigned short GenericScene::getCharcterXTile(){
    // return (bg1X+charcterX+Charcter_x_offset)/8;
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
            tiles.push_back(Level_Tiles[getTilenumber(charXtile + 2, charYtile- i)]);
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

bool GenericScene::charcterNotOnTile(unsigned short tilenumber){ //returns true if charcters stands not on this tile
    std::vector<unsigned short> tiles = tilesBelowCharcter();
    for (int i = 0; i < tiles.size(); ++i) {
        if(tiles.data()[i] != tilenumber){
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

bool GenericScene::charterNotAgainstTile(bool right, int tilenumber) {
    std::vector<unsigned short> tiles = tilesAgainstCharcter(right);
    for (int i = 0; i < tiles.size(); ++i) {
        if(tiles.data()[i] != tilenumber){
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




void GenericScene::move() {
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

    /*    if((charcterX+15) < (GBA_SCREEN_WIDTH/2) && (bg1X==0)) {
            charcterX += x;
            if(charcterX<=0)charcterX=0;
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
        }*/


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
//y
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

    //    charcterY -=y;
     //  bg1Y-=y;


    charcter.get()->moveTo(charcterX,charcterY);
    bg1.get()->scroll(bg1X,bg1Y);
}

