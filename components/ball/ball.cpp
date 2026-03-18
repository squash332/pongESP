#include "ball.hpp"
extern Paddle *paddle;

Ball::Ball(lv_obj_t *parent) : GameObject(parent)
{

    setSize(BALL_SIZE, BALL_SIZE);
    setColor(0xFFFFFF);

    x = rand() % (DISPLAY_WIDTH - 10) ;
    y = rand() % (DISPLAY_HEIGHT / 2) + 100;

    vx = 2;
    vy = -2;

    setPosition(x, y);
}

void Ball::update()
{
    x += vx;
    y += vy;

    // checkPaddleCollision();
    // checkBlockCollision();
    // checkBottomCollision(); // game over

    // left right
    if (collidedSides())
        vx = -vx;

    if (collidedTop())
        vy = -vy;

    collidedBlock();
    collidedPaddle();

    //     // TODO

    setPosition(x, y);
}

bool Ball::collidedSides()
{
    return (x <= X_OFFSET || x > DISPLAY_WIDTH - getWidth() - X_OFFSET);
}

bool Ball::collidedTop()
{
    return (y <= Y_OFFSET || y > DISPLAY_HEIGHT - getHeight() - Y_OFFSET);
    // || y > DISPLAY_HEIGHT - getHeight() - Y_OFFSET) btm check
}

bool Ball::collidedBlock()
{
    int16_t ball_center_x = x + getWidth() / 2;
    int16_t ball_center_y = y + getHeight() / 2;

    int16_t ball_col = (ball_center_x - X_OFFSET) / (TILE_SIZE + SPACING);
    int16_t ball_row = (ball_center_y - Y_OFFSET) / (TILE_SIZE + SPACING / 2);
    
    if (ball_col < 0 || ball_col >= COLS || ball_row < 0 || ball_row >= ROWS)
        return false;

    if (blocks[ball_col][ball_row]) {
        blocks[ball_col][ball_row] = false;
        bsp_display_lock(0);
        lv_obj_del(blocks_objs[ball_col][ball_row]);
        bsp_display_unlock();
        int blockX = ball_col * (TILE_SIZE + SPACING) + X_OFFSET;
        int blockY = ball_row * (TILE_SIZE + SPACING / 2) + Y_OFFSET;

        int blockCenterX = blockX + TILE_SIZE / 2;
        int blockCenterY = blockY + TILE_SIZE / 2;

        int dx = ball_center_x - blockCenterX;
        int dy = ball_center_y - blockCenterY;

        if (abs(dx) > abs(dy))
            vx = -vx;
        else
            vy = -vy;

        return true;
    }


    return false;
}

bool Ball::collidedPaddle() {
    
    
    return false;    
}
