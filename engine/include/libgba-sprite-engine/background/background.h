//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_BACKGROUND_H
#define GBA_SPRITE_ENGINE_BACKGROUND_H


#include <libgba-sprite-engine/gba/tonc_types.h>
#define MAP32X32 0
#define MAP32X64 1
#define MAP64X32 2
#define MAP64X64 3

class Background {
private:
    void buildRegister();
    u32 getBgControlRegisterIndex();


protected:
    const void *data;
    const void *map;
    int size, bgIndex;
    int mapSize;
    int screenBlockIndex, charBlockIndex;
    int mapLayout;

public:
    const int getScreenBlock() { return screenBlockIndex; }
    const int getCharBlock() { return charBlockIndex; }
    void useMapScreenBlock(int block) { screenBlockIndex = block; }
    void scroll(int x, int y);
    void scrollSpeed(int dx, int dy);

    Background(int bgIndex, const void *data, int size, const void* map, int mapSize) : data(data), bgIndex(bgIndex), size(size), map(map),
                                                                                        screenBlockIndex(0), charBlockIndex(1), mapSize(mapSize) { mapLayout=0;}
                                                                                        
    Background(int bgIndex,const void *data,int size,const void* map, int mapSize, int screenBlock,int charBlock, int mapLayout) : data(data), size(size), map(map), mapSize(mapSize), bgIndex(bgIndex),
                                                                                                                                   screenBlockIndex(screenBlock), charBlockIndex(charBlock), mapLayout(mapLayout){}

     virtual void persist();
    void updateMap(const void* map);
    void clearMap();
    void clearData();
};


#endif //GBA_SPRITE_ENGINE_BACKGROUND_H
