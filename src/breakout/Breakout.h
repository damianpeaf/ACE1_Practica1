#include "Arduino.h"

class Paddle : public Variables
{
public:
    Paddle();
    ~Paddle() {}

    int x;
    int y;
    int width;

    void draw();
}

class Block : public Variables
{
public:
    Block();
    ~Block() {}
    static const int totalBlocks = 64;
    static const int columns = 16;
    static const int rows = 4;

    void reset();
    void draw()
};

class Ball : public Variables
{
public:
    Ball();
    ~Ball() {}

    int x;
    int y;
    int xSpeed;
    int ySpeed;

    void reset();
    void move();
    // TODO: añadir propiedad para buzzer
    void collision(Paddle &paddle, Block &block);
    void draw();
}

class bAttract : public Variables
{
public:
    void draw(U8G2_ST7920_128X64_1_6800 &screen);
};

class Breakout : public Variables
{

public:
    Breakout();
    ~Breakout() {}

    Paddle paddle;
    Block block;
    Ball ball;
    bAttract attract;

    void draw();
    void logic();
}
