idf_component_register(SRCS "touch.cpp"
                       REQUIRES esp_lcd_touch_gt911 esp-box-3 lvgl
                       INCLUDE_DIRS "include")