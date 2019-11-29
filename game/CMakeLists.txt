project(game)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/scene_start/start_scene.cpp
        src/scene_start/start_scene.h src/scene_start/mainCharcters.h src/scene_1/scene_1.cpp src/scene_1/scene_1.h src/scene_1/tilemap.h src/genericScene.cpp src/genericScene.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
