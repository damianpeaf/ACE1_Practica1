#ifndef Breakout_H
#define Breakout_H

#include "Arduino.h"

class GameObject {
    public: 
        bool getElement() { return 1; }
        int objectType = 0;
        int objectRow; 
        int objectColumn;
    
};

class Ball: public GameObject {
    public: 
        Ball();


        int columnSpeed;
        int rowSpeed;
        int refreshRate = 1500;

        void setPos(int objectRow, int objectColumn);
        void setSpeed(int rowSpeed, int columnSpeed);

        void invertcolumnSpeed();
        void invertrowSpeed();

        int getNewobjectRow();
        int getNewobjectColumn();
};

class Paddle: public GameObject {
    public: 
        Paddle(int objectRow, int objectColumn);


        Paddle *nextPaddle;

        void moveLeft();
        void moveRight(bool isRoot);

        void setNextPaddle(Paddle *paddle);
};


class Brick: public GameObject {
    public: 
        Brick(int objectRow, int objectColumn);

        Brick *nextBrick;

        void setNextBrick(Brick *brick);
};

class Breakout {
    public: 
        Breakout(){};

        // props
        bool matrix [8][16];
        int hp = 3;
        int score = 0;
        bool hasCollided = false;
        bool hasWon = false;
        bool hasLost = false;


        // methods
        void reset();
        void update();

        void movePaddleLeft();
        void movePaddleRight();

        void refreshMatrix();

    private:
        // props
        GameObject *table[8][16];
        Paddle *rootPaddle;
        Ball *ball;

        // methods
        void movePaddle();
        void moveBall();
        void lifeLost();
        void destroyBrick(Brick *brick);
        void updateBallPosition();
        void resetGameLifeLost();
        GameObject* checkTablePosition(int row, int column);
};

#endif