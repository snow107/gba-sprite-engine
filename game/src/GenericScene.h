//
// Created by jelle on 2019/11/29.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H

#include <libgba-sprite-engine/scene.h>
#define CHARACTER_HEIGHT 32
#define CHARACTER_WIDTH 16



class GenericScene : public Scene {
private:
    const unsigned short* Level_Tiles;

    short Scene_width;
    short Scene_heigth;
    int starX,starY;
    void tick(u16 keys) override;
    int  collisionArray[7] = {0x02, 0x06, 0x07, 0x09, 0x0A, 0x18,0x29};
    int specialJumpArray[2]={0x41,0x42};

protected:
    std::unique_ptr<Background> bg1;
    std::unique_ptr<Sprite> charcter;
    std::unique_ptr<Sprite> ster;
    int charcterX,charcterY;
    int bg1X,bg1Y;
    int v1X,v1Y,d1X,d1Y;
    int x,y,resetX,resetY;
    bool specialjump=false;
    bool specialjumpActive=false;
    bool starActive =true;
    void collisionBewegen(int speedX,int speedY);
    bool groundCheck(std::vector<unsigned short> tiles,int tileNumber);
    void deadCheck(std::vector<unsigned short> tiles);
    void specialJumpCheck(std::vector<unsigned short>  tiles);
    bool charcterVerticalcheck(int tileNumber);
    bool charcteraHorizontaalCheck(int tileNumber);
    void move();
    int getTilenumber(int tilex,int tiley);

public:
    GenericScene(std::shared_ptr<GBAEngine> engine, short sceneWidth,
                 short sceneHeigth,int resetX,int resetY,int starX,int starY,  const unsigned short *levelTiles)
            : Scene(engine), Scene_width(sceneWidth),Scene_heigth(sceneHeigth), Level_Tiles(levelTiles),resetX(resetX),resetY(resetY),starX(starX),starY(starY) {}
    virtual void onTick(u16 keys) =0;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
