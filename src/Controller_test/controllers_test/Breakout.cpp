#include "Breakout.h"

// --- Brick ---

Brick::Brick(int objectRow, int objectColumn) {
    this -> objectRow = objectRow;
    this -> objectColumn = objectColumn;
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
    for (j = 6; j < 11; j++){
        Paddle lPaddle(7, j);
        Paddle rPaddle(7, j + 1);

        lPaddle.setNextPaddle(&rPaddle);
        rPaddle.setNextPaddle(&lPaddle);

        this -> table[7][j] = &lPaddle;
        this -> table[7][j+1] = &rPaddle;
    }

    // Create the ball
    Ball ball(3, 8);
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