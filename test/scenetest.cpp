//
// Created by Wouter Groeneveld on 28/07/18.
//

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/background.h>
#include "gtest/gtest.h"
#include "real_data.h"

class SceneSuite : public ::testing::Test {
protected:
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }
};

class SomeScene : public Scene {
private:
    std::unique_ptr<Sprite> someSprite1;
    std::unique_ptr<Sprite> someSprite2;
    std:: unique_ptr<Background> bg1,bg2;
    std::vector<Background *> backgroundvector;
public:
    SomeScene() : Scene(nullptr) { };
    std::vector<Sprite *> sprites() override {
        return {
            someSprite1.get(), someSprite2.get()
        };
    }

    std::vector<Background *> backgrounds() override {
        return backgroundvector;
    }

    void tick(u16 i) override {
    }

    void load() override {
        backgroundPalette=std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(bg_palette, sizeof(bg_palette)));

        bg1=std::unique_ptr<Background>(new Background(1,kulTiles,sizeof(kulTiles),map  ,sizeof(map)));
        bg2=std::unique_ptr<Background>(new Background(2,kulTiles,sizeof(kulTiles),map  ,sizeof(map)));

        backgroundvector.push_back(bg1.get());
        backgroundvector.push_back(bg2.get());

        someSprite1 = SpriteBuilder<Sprite>()
                .withLocation(1, 1)
                .buildPtr();
        someSprite2 = SpriteBuilder<Sprite>()
                .withLocation(2, 2)
                .buildPtr();
    }
};

TEST_F(SceneSuite, GetSpritesReturnsPointersOfBuiltSprites) {
    SomeScene scene;
    scene.load();

    auto sprites = scene.sprites();
    ASSERT_EQ(2, sprites.size());
    ASSERT_EQ(1, sprites.at(0)->getX());
    ASSERT_EQ(2, sprites.at(1)->getX());


}

TEST_F(SceneSuite,TestBackgrounds){
    SomeScene scene;
    scene.load();

    auto backgrounds = scene.backgrounds();
    ASSERT_EQ(backgrounds.size(),2);
}