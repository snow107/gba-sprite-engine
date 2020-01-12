//
// Created by jelle on 2019/11/29.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H

#include <libgba-sprite-engine/scene.h>



class GenericScene : public Scene {
private:
    const unsigned short* Level_Tiles;
    short Charcter_heigth;
    short Charcter_width;
    short Charcter_y_offset;
    short Charcter_x_offset;
    short Scene_width;
    short Scene_heigth;
    void tick(u16 keys) override;
protected:
    std::unique_ptr<Background> bg1;
    std::unique_ptr<Sprite> charcter;
    int charcterX,charcterY;
    int bg1X,bg1Y;
    int v1X,v1Y,d1x,d1y;
    int x,y;
    int collisionX,colissionY;
    void collisionBewegen();
    void movebg1(int x, int y);
    void movecharcter(int x, int y);
    bool charcterVerticalcheck();
    bool charcteraHorizontaalCheck();
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
                 short sceneHeigth, short charterwidth, short charterheigth, short charterXOffsetTiles,
                 short charterYOffsetTiles, const unsigned short *levelTiles)
            : Scene(engine), Charcter_width(charterwidth) , Charcter_heigth(charterheigth)
            , Charcter_x_offset(charterXOffsetTiles), Charcter_y_offset(charterYOffsetTiles), Scene_width(sceneWidth),
              Scene_heigth(sceneHeigth), Level_Tiles(levelTiles) {}
    virtual void onTick(u16 keys) =0;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
