#include "ball.hpp"
extern std::unique_ptr<Paddle> paddle;

Ball::Ball(lv_obj_t *parent) : GameObject(parent)
{
    block_count = COLS * ROWS;
    active = true; // after 5 or 6 games, games insta crashed, probably because i set the active flag true in class and not here in constructor (fixed)
    setSize(BALL_SIZE, BALL_SIZE);
    setColor(0xFFFFFF);

    x = rand() % (DISPLAY_WIDTH - 10);
    y = rand() % (DISPLAY_HEIGHT / 2) + 100;

    vx = 2;
    vy = -2;

    setPosition(x, y);
}

void Ball::update()
{
    x += vx;
    y += vy;
    hitBlock = false;

    if (collidedSides())
        vx = -vx;

    if (collidedTop())
        vy = -vy;

    collidedBlock();
    collidedPaddle();

    setPosition(x, y);
    // if (gameOver()) if game over, popup -> stops game, shows Score, time elapsed, Options: play again, Back to Menu
    if (gameOver())
    {
        printf("GAME OVER: y=%ld row=%d block_count=%ld\n", y, getBallRow(), block_count);
        active = false;
    }
}

bool Ball::collidedSides()
{
    return (x <= X_OFFSET || x > DISPLAY_WIDTH - getWidth() - X_OFFSET);
}

bool Ball::collidedTop()
{
    return (y <= Y_OFFSET);
    // || y > DISPLAY_HEIGHT - getHeight() - Y_OFFSET) btm check
}

bool Ball::gameOver()
{
    if (y > DISPLAY_HEIGHT - getHeight() - Y_OFFSET || block_count == 0)
        return true;

    return false;
}

bool Ball::collidedBlock()
{
    int16_t ball_col = getBallCol();
    int16_t ball_row = getBallRow();

    if (ball_col < 0 || ball_col >= COLS || ball_row < 0 || ball_row >= ROWS)
        return false;

    if (blocks[ball_col][ball_row])
    {
        blocks[ball_col][ball_row] = false;
        bsp_display_lock(0);
        lv_obj_del_async(blocks_objs[ball_col][ball_row]);
        ;
        bsp_display_unlock();
        blocks_objs[ball_col][ball_row] = nullptr;
        score += 10;
        int blockX = ball_col * (TILE_SIZE + SPACING) + X_OFFSET;
        int blockY = ball_row * (TILE_SIZE + SPACING / 2) + Y_OFFSET;

        int blockCenterX = blockX + TILE_SIZE / 2;
        int blockCenterY = blockY + TILE_SIZE / 2;

        int dx = getCenterX() - blockCenterX;
        int dy = getCenterY() - blockCenterY;

        if (abs(dx) > abs(dy))
            vx = -vx;
        else
            vy = -vy;

        block_count--;
        hitBlock = true;
        return true;
    }

    return false;
}

bool Ball::collidedPaddle()
{
    if (!paddle)
        return false;
    // AABB
    bool overlap = x < paddle->getX() + paddle->getWidth() && x + getWidth() > paddle->getX() && y < PADDLE_Y_POS + paddle->getHeight() && y + getHeight() > PADDLE_Y_POS;

    if (!overlap)
        return false;

    vy = -abs(vy);

    float hitPosition = (getCenterX() - paddle->getX()) / (float)paddle->getWidth();
    hitPosition = hitPosition * 2.0f - 1.0f;

    vx = hitPosition * 3;

    y = PADDLE_Y_POS - getHeight() - 1;

    return true;
}

int16_t Ball::getCenterX() const
{
    return x + getWidth();
}

int16_t Ball::getCenterY() const
{
    return y + getWidth();
}

int16_t Ball::getBallCol() const
{
    return (getCenterX() - X_OFFSET) / (TILE_SIZE + SPACING);
}
int16_t Ball::getBallRow() const
{
    return (getCenterY() - Y_OFFSET) / (TILE_SIZE + SPACING / 1.5);
}

uint32_t Ball::getScore() const
{
    return score;
}