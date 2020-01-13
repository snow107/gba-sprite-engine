//
// Created by jelle on 2019/11/29.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H

#include <libgba-sprite-engine/scene.h>
#define Charcter_height 32
#define Charcter_width 16
#define  COLLISIONARRAYSIZE 6

class GenericScene : public Scene {
private:
    const unsigned short* Level_Tiles;

    short Scene_width;
    short Scene_heigth;
    int starX,starY;
    void tick(u16 keys) override;
    int  collisionArray[6] = {0x02, 0x06, 0x07, 0x09, 0x0A, 0x18};

protected:
    std::unique_ptr<Background> bg1;
    std::unique_ptr<Sprite> charcter;
    std::unique_ptr<Sprite> ster;
    int charcterX,charcterY;
    int bg1X,bg1Y;
    int v1X,v1Y,d1X,d1Y;
    int x,y,resetX,resetY;
    int collisionX,colissionY;
    bool dead = false;
    void collisionBewegen(int speedX,int speedY);
    void movebg1(int x, int y);
    void movecharcter(int x, int y);
    void deadCheck();
    bool charcterVerticalcheck(int tileNumber);
    bool charcteraHorizontaalCheck(int tileNumber);
    std::vector<unsigned short> tilesBelowCharcter();
    std::vector<unsigned short> tilesAgainstCharcter(bool right); //otherwise lift
    int getBottemLeftCharcterTile();
    void move();
    int getTilenumber(int tilex,int tiley);
    unsigned short getCharcterXTile(); //returns left tile number
    unsigned short getCharcterYTile(); //returns top tile number
    bool charcterOnTile(unsigned short tilenumber);
    bool charcterNotOnTile(unsigned short tilenumber);
    bool charterAgainstTile(bool right, int tilenumber); //otherwise left
    bool charterNotAgainstTile(bool right, int tilenumber); //otherwise left
    int ticknumber;

public:
    GenericScene(std::shared_ptr<GBAEngine> engine, short sceneWidth,
                 short sceneHeigth,int resetX,int resetY,int starX,int starY,  const unsigned short *levelTiles)
            : Scene(engine), Scene_width(sceneWidth),Scene_heigth(sceneHeigth), Level_Tiles(levelTiles),resetX(resetX),resetY(resetY),starX(starX),starY(starY) {}
    virtual void onTick(u16 keys) =0;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
