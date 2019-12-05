project(Michiel_achtergrondTest)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/startScene/start_scene.cpp src/startScene/start_scene.h
        src/startScene/probeerSpiegel.h
        )

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
