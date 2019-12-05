//
// Created by michi on 5/12/2019.
//


#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/palette/palette_manager.h>
#include <libgba-sprite-engine/allocator.h>

#include "startScene/start_scene.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    BeginScene* startScene = new BeginScene(engine);
    engine->setScene(startScene);

    while (true) {
        engine->update();
        engine->delay(1000);
    }

    return 0;
}
