#include "Arduino.h"

class GameObject {
    public: 
    bool getElement() {
        return 1;
    }
}


class Ball: public GameObject {
    public: 
        Ball(int targetX, int targetY);

        int targetX;
        int targetY;
        int velocity = 1500;

        void getNextPosition();
}

class Paddle: public GameObject {
    public: 
        Paddle(Paddle *paddle);
        Paddle *nextPaddle;
}

class Brick: public GameObject {
    public: 
        Brick(int xPos, int yPos);

        int xPos;
        int yPos;

        Brick *nextBrick;

        void setNextBrick(Brick *brick);
}

class Breakout {
    public: 
    Breakout(){};

    int hp = 3;
    int score = 0;
    GameObject *table[8][16];

    void reset();
    void pause();
    void exit();

    bool getMatrix();
}