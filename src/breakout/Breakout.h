#include "Arduino.h"

class GameObject {
    public: 
        bool getElement() {
            return 1;
        }
};


// class Ball: public GameObject {
//     public: 
//         Ball(int targetX, int targetY);

//         int targetX;
//         int targetY;
//         int velocity = 1500;

//         void getNextPosition();
// }

// class Paddle: public GameObject {
//     public: 
//         Paddle(Paddle *paddle);
//         Paddle *nextPaddle;
// }

class Brick: public GameObject {
    public: 
        Brick(int xPos, int yPos){
            this -> xPos = xPos;
            this -> yPos = yPos;
        }

        int xPos;
        int yPos;

        Brick *nextBrick;

        void setNextBrick(Brick *brick){
            this -> nextBrick = brick;
        }
};

class Breakout {
    public: 
    Breakout(){};

    int hp = 3;
    int score = 0;
    GameObject *table[8][16];

    bool matrix [8][16];

    void reset(){
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 16; j++){
                this -> table[i][j] = nullptr;
            }
        }

        for(int i = 0; i < 4; i++){
            for (int j = 0 ; j < 16; j+= 2){
                Brick rBrick(i, j + 1)  ;
                Brick lBrick(i, j);

                lBrick.setNextBrick(&rBrick);
                rBrick.setNextBrick(&lBrick);

                this -> table[i][j] = &lBrick;
                this -> table[i][j+1] = &rBrick;
            }
        }
    };

    void pause();
    void exit();

    void refreshMatrix(){
        for(int i = 0; i < 8; i++){
            for (int j = 0 ; j < 16; j++){
                if(this -> table[i][j] != nullptr){
                    this -> matrix[i][j] = this -> table[i][j] -> getElement();
                } else {
                    this-> matrix[i][j] = 0;
                }
            }
        }
    }
};