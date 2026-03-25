idf_component_register(SRCS "game_state.cpp" "game.cpp" "menu.cpp" "game_over.cpp" "main.cpp"
                       REQUIRES display game_object ball paddle blocks constants touch screen
                       INCLUDE_DIRS "include")