project(game)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/scene_start/start_scene.cpp
        src/scene_start/start_scene.h src/scene_start/mainCharcters.h src/scene_1/scene_1.cpp src/scene_1/scene_1.h src/GenericScene.cpp src/GenericScene.h
        src/scene_2/scene_2.cpp src/scene_2/scene_2.h src/sprites/shared_star_circle_sonic.h src/sprites/sonic_for_star_circle.h src/sprites/star.h src/sprites/circle.h src/sprites/shared_kurby_sonic.h src/sprites/kurby.h src/sprites/sonic_for_kurby.h src/scene_3/scene_3.cpp src/scene_3/scene_3.h src/scene_4/scene_4.cpp src/scene_4/scene_4.h "src/end_scene/end_scene.cpp" "src/end_scene/end_scene.h" src/Tileset/tilesSpel.c src/Tileset/tilesSpel.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
