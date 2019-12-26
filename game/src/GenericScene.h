//
// Created by jelle on 2019/11/29.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H

#include <libgba-sprite-engine/scene.h>

class GenericScene : public Scene {
private:
    const unsigned short* Level_Tiles;
    short CHARTERHEIGTH;
    short CHARTERWIDTH;
    short CHARTER_Y_OFFSET;
    short CHARTER_X_OFFSET;
    short SCENE_WIDTH;
    short SCENE_HEIGTH;
    void tick(u16 keys) override;
protected:
    std::unique_ptr<Background> bg1;
    std::unique_ptr<Sprite> charcter;
    int charcterX,charcterY;
    int bg1X,bg1Y;
    int v1X,v1Y;
    void movebg1(int x, int y);
    void movecharcter(int x, int y);
    bool charcterOnGround();
    bool charcteragainstwall(bool right); //otherwise left
    std::vector<unsigned short> tilesBelowCharcter();
    std::vector<unsigned short> tilesAgainstCharcter(bool right); //otherwise lift
    int getBottemLeftCharcterTile();
    void move(int x,int y);
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
            : Scene(engine), CHARTERWIDTH(charterwidth) , CHARTERHEIGTH(charterheigth)
            , CHARTER_X_OFFSET(charterXOffsetTiles), CHARTER_Y_OFFSET(charterYOffsetTiles), SCENE_WIDTH(sceneWidth),
              SCENE_HEIGTH(sceneHeigth), Level_Tiles(levelTiles) {}
    virtual void onTick(u16 keys) =0;
};


#endif //GBA_SPRITE_ENGINE_PROJECT_GENERICSCENE_H
