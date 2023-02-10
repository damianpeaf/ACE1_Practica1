#include "Breakout.h"

// --- Brick ---

Brick::Brick(int xPos, int yPos) {
    this -> xPos = xPos;
    this -> yPos = yPos;
}

void Brick::setNextBrick(Brick *brick) {
    this -> nextBrick = brick;
}

// --- Breakout ---

void Breakout::reset() {
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
}

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