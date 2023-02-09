#include "Arduino.h"

class Paddle : public Variables
{
public:
    Paddle();
    ~Paddle() {}

    void draw();
}

class Block : public Variables
{
public:
    Block();
    ~Block() {}
    static const int totalBlocks = 35;
    static const int columns = 7;
    static const int rows = 5;

    void reset();
    void draw()
};

class Ball : public Variables
{
public:
    Ball();
    ~Ball() {}

    void reset();
    void move();
    void collision();
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
