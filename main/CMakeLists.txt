idf_component_register(SRCS "game_state.cpp" "main.cpp" "screens/game_over.cpp" "screens/game.cpp" "screens/menu.cpp" "screens/settings.cpp" "helpers.cpp"
                       REQUIRES display game_object ball paddle blocks constants touch screen audio
                       INCLUDE_DIRS "include" )
spiffs_create_partition_image(storage ../components/spiffs FLASH_IN_PROJECT)