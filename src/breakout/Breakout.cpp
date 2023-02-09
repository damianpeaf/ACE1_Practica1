#include "Breakout.h"

Paddle::Paddle()
{
    x = 5;
    y = 0;
    width = 5;
}

void Paddle::draw()
{
    screen.drawFrame(x, y, width, 1);
}

Block::Block()
{
    reset();
}

void Block::reset()
{
    for (int i = 0; i < totalBlocks; i++)
    {
        blocks[i].x = (i % columns) * 2 + 1;
        blocks[i].y = (i / columns) * 2 + 1;
        blocks[i].width = 2;
        blocks[i].height = 2;
        blocks[i].active = true;
    }
}

void Block::draw()
{
    for (int i = 0; i < totalBlocks; i++)
    {
        if (blocks[i].active)
        {
            screen.drawFrame(blocks[i].x, blocks[i].y, blocks[i].width, blocks[i].height);
        }
    }
}

Ball::Ball()
{
    reset();
}

void Ball::reset()
{
    xSpeed = 2;
    ySpeed = -2;
    x = 8;
    y = 1
}

void Ball::move()
{
    x += xSpeed;
    y += ySpeed;
}

void Ball::collision(Paddle &paddle, Block &block)
{
}

void Ball::draw()
{
}

Breakout::Breakout()
{
}

Breakout::~Breakout()
{
}

void Breakout::draw()
{
    paddle.draw();
    block.draw();
    ball.draw();
    battract.draw();
}

void Breakout::controls()
{
    // TODO: añadir controles
}
