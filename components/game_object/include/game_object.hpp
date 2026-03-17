#pragma once
#include "lvgl.h"

class GameObject {
protected:
    lv_obj_t* obj;

public:
    GameObject(lv_obj_t* parent);
    virtual ~GameObject() = default;

    void setPosition(uint32_t x, uint32_t y); // relative to top left corner
    void setSize(uint32_t w, uint32_t h); // relative to top left corner
    void setColor(uint32_t color); // hex format -> 0x000000
    lv_obj_t* getObj();

    int32_t getX() const;
    int32_t getY() const;

    uint32_t getWidth() const;
    uint32_t getHeight() const;
    
    virtual void update() {} // update ball pos, paddle position etc
};