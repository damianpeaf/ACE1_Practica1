#include "Breakout.h"

Brick::Brick(int xPos, int yPos){
    this -> xPos = xPos;
    this -> yPos = yPos;
}

Brick::setNextBrick(Brick *brick){
    this -> nextBrick = brick;
}

Breakout::reset(){

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 16; j++){
            this -> table[i][j] = nullptr;
        }
    }

    for(int i = 0; i < 4; i++){
        for (int j = 0 ; j < 16; j+= 2){
            Brick rBrick =  new Brick(i, j + 1);
            Brick lBrick =  new Brick(i, j);

            lBrick.setNextBrick(&rBrick);
            rBrick.setNextBrick(&lBrick);

            this -> table[i][j] = lBrick;
            this -> table[i][j+1] = rBrick;
        }
    }
}

Breakout::getMatrix(){
    bool matrix[8][16];

    for(int i = 0; i < 8; i++){
        for (int j = 0 ; j < 16; j++){
            if(this -> table[i][j] != nullptr){
                matrix[i][j] = this -> table[i][j].getElement();
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}