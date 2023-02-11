#include "Arduino.h"

class GameObject {
    public: 
        bool getElement() { return 1; }
};

class Ball: public GameObject {
    public: 
        Ball(int speedX, int speedY);


        int speedX;
        int speedY;
        int velocity = 1500;

        void getNextPosition();
}

class Paddle: public GameObject {
    public: 
        Paddle(int xPos, int yPos);

        int xPos;
        int yPos;

        Paddle *nextPaddle;

        void moveLeft();
        void moveRight()

        void setNextPaddle(Paddle *paddle);
}


class Brick: public GameObject {
    public: 
        Brick(int xPos, int yPos);

        int xPos;
        int yPos;

        Brick *nextBrick;

        void setNextBrick(Brick *brick);
};

class Breakout {
    public: 
    Breakout(){};

    int hp = 3;
    int score = 0;
    GameObject *table[8][16];
    Paddle *paddle;
    Ball *ball;

    bool matrix [8][16];

    void reset();

    void pause();
    void exit();

    void refreshMatrix();
};