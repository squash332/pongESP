#include "blocks.hpp"

Block::Block(lv_obj_t *parent, uint32_t x, uint32_t y) : GameObject(parent)
{
    // lv_image_set_src(obj, &block);
    setSize(16, 16);
    setColor(0xFFFFFF);
    setPosition(x, y);
    lv_obj_set_style_radius(obj, 0, LV_PART_MAIN);

    alive = true;

}
