#pragma once
#include "lvgl.h"

class GameObject {
protected:
    lv_obj_t* obj;

public:
    GameObject(lv_obj_t* parent);
    virtual ~GameObject() = default;

    void setPosition(uint32_t x, uint32_t y);
    void setSize(uint32_t w, uint32_t h);
    void setColor(uint32_t color);
    lv_obj_t* getObj();
    
    virtual void update() {} // update ball pos, paddle position etc
};