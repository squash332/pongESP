#include "touch.hpp"

Touch::Touch() {

    indev = bsp_display_get_input_dev();

}

bool Touch::read() {

       
    lv_indev_state_t state = lv_indev_get_state(indev);
    if (state == LV_INDEV_STATE_PRESSED) {
        lv_point_t point;
        lv_indev_get_point(indev, &point);
        x = point.x;
        y = point.y;
        // printf("%ld, %ld\n", x, y);
        return true;
    }
    return false;
}

