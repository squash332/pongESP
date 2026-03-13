#pragma once
#include "lvgl.h"
#include <vector>
#include "constants.hpp"
#include "game_object.hpp"

class Block : public GameObject
{
public:
    Block(lv_obj_t* parent, uint32_t x, uint32_t y);
    ~Block() = default;

    

    bool alive;

};
