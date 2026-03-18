#include "touch.hpp"

Touch::Touch() {

    indev = lv_indev_get_next(nullptr);

}

bool Touch::read() {

    bsp_display_lock(0);
    lv_indev_read(indev);
    
    lv_indev_state_t state = lv_indev_get_state(indev);
    if (state == LV_INDEV_STATE_PRESSED) {
        lv_point_t point;
        lv_indev_get_point(indev, &point);
        x = point.x;
        y = point.y;
        bsp_display_unlock();
        // printf("%ld, %ld\n", x, y);
        return true;
    }
    return false;
}

