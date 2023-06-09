#include "Breakout.h"

// --- Brick ---

Brick::Brick(int objectRow, int objectColumn) {
    this -> objectRow = objectRow;
    this -> objectColumn = objectColumn;
    this -> objectType = 3;
}

void Brick::setNextBrick(Brick *brick) {
    this -> nextBrick = brick;
}

// --- Paddle ---

Paddle::Paddle(int objectRow, int objectColumn) {
    this -> objectRow = objectRow;
    this -> objectColumn = objectColumn;
    this -> objectType = 2;
}


void Paddle::setNextPaddle(Paddle *paddle) {
    this -> nextPaddle = paddle;
}

void Paddle::moveLeft() {
    if(this -> objectColumn > 0){
        this -> objectColumn--;
        if (this -> nextPaddle != nullptr){
            this -> nextPaddle -> moveLeft();
        }
    }
}

void Paddle::moveRight(bool isRoot){
    // Condition only for the root paddle object
    if(this -> objectColumn < 11 || !isRoot){
        this -> objectColumn++;
        if (this -> nextPaddle != nullptr){
            this -> nextPaddle -> moveRight(false);
        }
    }
}


// --- Ball ---

Ball::Ball() {
    this -> objectType = 1;
}

void Ball::setPos(int objectRow, int objectColumn) {
    this -> objectRow = objectRow;
    this -> objectColumn = objectColumn;
}

void Ball::setSpeed(int rowSpeed, int columnSpeed) {
    this -> columnSpeed = columnSpeed;
    this -> rowSpeed = rowSpeed;
}

void Ball::invertcolumnSpeed() {
    this -> columnSpeed = -this -> columnSpeed;
}

void Ball::invertrowSpeed() {
    this -> rowSpeed = -this -> rowSpeed;
}

int Ball::getNewobjectRow() {
    return  (this -> objectRow) + (this -> rowSpeed); 
}

int Ball::getNewobjectColumn() {
    return  (this -> objectColumn) + (this -> columnSpeed); 
}

// --- Breakout ---

void Breakout::reset() {

    this -> hp = 3;
    this -> score = 0;
    this -> hasCollided = false;
    this -> hasWon = false;
    this -> hasLost = false;

    // Reset the table
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 16; j++){
            this -> table[i][j] = nullptr;
        }
    }

    // Create the bricks
    for(int i = 0; i < 4; i++){
        for (int j = 0 ; j < 16; j+= 2){
            Brick *rBrick = new Brick(i,j + 1);
            Brick *lBrick = new Brick(i,j);

            lBrick->setNextBrick(rBrick);
            rBrick->setNextBrick(lBrick);

            this -> table[i][j] = lBrick;
            this -> table[i][j+1] = rBrick;
        }
    }


    // Create the paddle
    Paddle *paddle = new Paddle(7,6);
    Paddle *paddle2 = new Paddle(7,7);
    Paddle *paddle3 = new Paddle(7,8);
    Paddle *paddle4 = new Paddle(7,9);
    Paddle *paddle5 = new Paddle(7,10);
    paddle->setNextPaddle(paddle2);
    paddle2->setNextPaddle(paddle3);
    paddle3->setNextPaddle(paddle4);
    paddle4->setNextPaddle(paddle5);
    paddle5->setNextPaddle(nullptr);

    this -> rootPaddle = paddle;
    this -> table[7][6] = paddle;
    this -> table[7][7] = paddle2;
    this -> table[7][8] = paddle3;
    this -> table[7][9] = paddle4;
    this -> table[7][10] = paddle5;
    
    // Create the ball
    Ball *b = new Ball();
    b->setSpeed(-1, 1);
    b->setPos(6, 8);

    this -> ball = b;
    this -> table[6][8] = b;
}


void Breakout::movePaddleLeft(){
    this -> rootPaddle -> moveLeft();
    movePaddle();    
}


void Breakout::movePaddleRight(){
    this -> rootPaddle -> moveRight(true);
    movePaddle();    
}

void Breakout::update(){

    // * Table info
    int newobjectRow = this->ball->getNewobjectRow();
    int newobjectColumn =this->ball-> getNewobjectColumn();
    GameObject *collidedObject = checkTablePosition(newobjectRow, newobjectColumn);

    // * Collision detection

    // - Walls collision
    // -- Ball collision with lateral walls
    if(newobjectColumn < 0 || newobjectColumn > 15){
        this -> ball -> invertcolumnSpeed();
    }

    // -- Ball collision with the roof
    else if(newobjectRow < 0){
        this -> ball -> invertrowSpeed();
    }

    // -- Ball collision with the floor
    else if(newobjectRow > 8){
        lifeLost();
    }
    
    // -- empty space collision
    else if(collidedObject == nullptr){
        moveBall();
        return;
    }

    // - Game object collision
    // -- Ball collision with paddle
    else if (collidedObject -> objectType == 2){
        // ? TODO: make the ball bounce in a different way depending on the paddle position
        this -> ball -> invertrowSpeed();
    }

    // -- Ball collision with brick
    else if (collidedObject -> objectType == 3){
        if( this -> ball -> rowSpeed == -1){
            this -> ball -> invertrowSpeed();
        }else{
            this -> ball -> invertcolumnSpeed();
        }
        destroyBrick((Brick *) collidedObject);
    }

    // Check next posible collision
    collidedObject = checkTablePosition(this->ball->getNewobjectRow(), this->ball-> getNewobjectColumn());
    this -> hasCollided = true;

    if (collidedObject == nullptr){
        moveBall();
    }else{
        update(); 
    }

}

GameObject* Breakout::checkTablePosition(int row, int column){
    GameObject *collidedObject;

    if (row < 0 || row > 7 || column < 0 || column > 15){
        collidedObject = nullptr;
    } else {
        collidedObject = this -> table[row][column];
    }

    return collidedObject;
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

void Breakout::movePaddle(){

    // clear paddle row
    for (int i = 0; i < 16; i++){
        this -> table[7][i] = nullptr;
    }

    Paddle *auxPaddle = this -> rootPaddle;
    while (auxPaddle != nullptr){
        this -> table[auxPaddle -> objectRow][auxPaddle -> objectColumn] = auxPaddle;
        auxPaddle = auxPaddle -> nextPaddle;
    }
}

void Breakout::updateBallPosition(){
    // clear ball position
    this -> table[this -> ball -> objectRow][this -> ball -> objectColumn] = nullptr;

    // update ball position
    this -> ball -> objectRow = this -> ball -> getNewobjectRow();
    this -> ball -> objectColumn = this -> ball -> getNewobjectColumn();
}

void Breakout::moveBall(){
    updateBallPosition();
    // update ball position in the table
    this -> table[this -> ball -> objectRow][this -> ball -> objectColumn] = this -> ball;

}

void Breakout::destroyBrick(Brick *brick){
    this -> score += 1;
    this -> table [brick -> objectRow][brick -> objectColumn] = nullptr;
    this -> table [brick -> nextBrick -> objectRow][brick -> nextBrick -> objectColumn] = nullptr;

    if (score % 2 == 0){
        this -> hp += 1;
    }

    if(this -> score == 32){
        this -> hasWon = true;
    }
}

void Breakout::lifeLost(){
    this -> hp -= 1;
    resetGameLifeLost();
    if(this -> hp == 0){
        this -> hasLost = true;
    }
}

void Breakout::resetGameLifeLost(){

    // Reset the table, but keep the bricks
    for (int i = 4; i < 8; i++){
        for (int j = 0; j < 16; j++){
            this -> table[i][j] = nullptr;
        }
    }

    // Create the paddle
    Paddle *paddle = new Paddle(7,6);
    Paddle *paddle2 = new Paddle(7,7);
    Paddle *paddle3 = new Paddle(7,8);
    Paddle *paddle4 = new Paddle(7,9);
    Paddle *paddle5 = new Paddle(7,10);
    paddle->setNextPaddle(paddle2);
    paddle2->setNextPaddle(paddle3);
    paddle3->setNextPaddle(paddle4);
    paddle4->setNextPaddle(paddle5);
    paddle5->setNextPaddle(nullptr);

    this -> rootPaddle = paddle;
    this -> table[7][6] = paddle;
    this -> table[7][7] = paddle2;
    this -> table[7][8] = paddle3;
    this -> table[7][9] = paddle4;
    this -> table[7][10] = paddle5;
    
    // Create the ball
    Ball *b = new Ball();
    b->setSpeed(-1, 1);

    // Randomize the ball position
    int randomRow = 6; // ?
    int randomColumn = rand()%(16);

    b->setPos(randomRow, randomColumn);

    this -> ball = b;
    this -> table[randomRow][randomColumn] = b;
}