#include "Breakout.h"

// --- Brick ---

Brick::Brick(int xPos, int yPos) {
    this -> xPos = xPos;
    this -> yPos = yPos;
}

Paddle::Paddle(int xPos, int yPos) {
    this -> xPos = xPos;
    this -> yPos = yPos;
}

Ball::Ball(int speedX, int speedY) {
    this -> speedX = speedX;
    this -> speedY = speedY;
}


void Brick::setNextBrick(Brick *brick) {
    this -> nextBrick = brick;
}

void Paddle::setNextPaddle(Paddle *paddle) {
    this -> nextPaddle = paddle;
}

// --- Breakout ---

void Breakout::reset() {

    // Reset the table
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 16; j++){
            this -> table[i][j] = nullptr;
        }
    }

    // Create the bricks
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


    // Create the paddle
    Paddle paddle(7, 7);
    Paddle paddle2(7, 8);
    Paddle paddle3(7, 9);
    Paddle paddle4(7, 10);
    Paddle paddle5(7, 11);

    paddle.setNextPaddle(&paddle2);
    paddle2.setNextPaddle(&paddle3);
    paddle3.setNextPaddle(&paddle4);
    paddle4.setNextPaddle(&paddle5);
    paddle5.setNextPaddle(&paddle);

    this -> table[7][7] = &paddle;
    this -> table[7][8] = &paddle2;
    this -> table[7][9] = &paddle3;
    this -> table[7][10] = &paddle4;
    this -> table[7][11] = &paddle5;

    // Create the ball
    Ball ball(1, 1);
    this -> table[6][8] = &ball;
    
}

void Breakout::pause() {}

void Breakout::refreshMatrix(){
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