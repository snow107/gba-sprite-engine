//
// Created by jelle on 2019/11/28.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H
#define GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H

#include <libgba-sprite-engine/scene.h>


class scene_1 : public Scene {
    private:
        std::unique_ptr<Sprite> charcter;
        std::unique_ptr<Background> bg1;
        std::unique_ptr<Background> bg2;
        int bg1X,bg1Y;
        int v1X,v1Y;
        int charcterX,charcterY;
        int ticknumber;
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

public:
        std::vector<Sprite *> sprites() override;
        std::vector<Background *> backgrounds() override;

        scene_1(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

        void load() override;
        void tick(u16 keys) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_SCENE_1_H
