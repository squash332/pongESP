idf_component_register(SRCS "game_state.cpp" "game.cpp" "menu.cpp" "game_over.cpp" "main.cpp"
                       REQUIRES display game_object ball paddle blocks constants touch screen audio
                       INCLUDE_DIRS "include")
spiffs_create_partition_image(storage ../components/spiffs FLASH_IN_PROJECT)