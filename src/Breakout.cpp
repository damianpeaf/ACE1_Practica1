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
    int newobjectRow = (this -> ball -> objectRow) + (this -> ball -> rowSpeed);
    int newobjectColumn = (this -> ball -> objectColumn) + (this -> ball -> columnSpeed);

    GameObject *collidedObject;

    if (newobjectRow < 0 || newobjectRow > 7 || newobjectColumn < 0 || newobjectColumn > 15){
        collidedObject = nullptr;
    } else {
        collidedObject = this -> table[newobjectRow][newobjectColumn];
    }

    // * Collision detection

    // - Walls collision
    // -- Ball collision with lateral walls
    if(newobjectColumn < 0 || newobjectColumn > 15){
        this -> ball -> invertcolumnSpeed();
        Serial.println("Collision with lateral walls");
    }

    // -- Ball collision with the roof
    else if(newobjectRow < 0){
        this -> ball -> invertrowSpeed();
        Serial.println("Collision with the roof");
    }

    // -- Ball collision with the floor
    else if(newobjectRow > 7){
        lifeLost();
        Serial.println("Collision with the floor");
    }
    
    // -- empty space collision
    else if(collidedObject == nullptr){
        Serial.println("Empty space collision");
        moveBall();
        return;
    }

    // - Game object collision
    // -- Ball collision with paddle
    else if (collidedObject -> objectType == 2){
        // ? TODO: make the ball bounce in a different way depending on the paddle position
        this -> ball -> invertrowSpeed();
        Serial.println("Paddle collision " + String(collidedObject -> objectRow) + ", " + String(collidedObject -> objectColumn));
    }

    // -- Ball collision with brick
    else if (collidedObject -> objectType == 3){
        this -> ball -> invertrowSpeed();
        this -> hasCollided = true;
        destroyBrick((Brick *) collidedObject);
        Serial.println("Brick collision");
    }

    // * New position
    this -> hasCollided = true;
    moveBall();

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

void Breakout::printMatrix(){
    for(int i = 0; i < 8; i++){
        for (int j = 0 ; j < 16; j++){
            Serial.print(this -> matrix[i][j]);
            Serial.print(" ");
        }
        Serial.println();
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

void Breakout::moveBall(){
    // clear ball position
    this -> table[this -> ball -> objectRow][this -> ball -> objectColumn] = nullptr;

    // update ball position
    this -> ball -> objectRow = this -> ball -> getNewobjectRow();
    this -> ball -> objectColumn = this -> ball -> getNewobjectColumn();

    // update ball position in the table
    this -> table[this -> ball -> objectRow][this -> ball -> objectColumn] = this -> ball;
}

void Breakout::destroyBrick(Brick *brick){
    Serial.println("Brick collision function");

    this -> score += 1;
    this -> table [brick -> objectRow][brick -> objectColumn] = nullptr;
    this -> table [brick -> nextBrick -> objectRow][brick -> nextBrick -> objectColumn] = nullptr;

    if(this -> score == 32){
        this -> hasWon = true;
    }
}

void Breakout::lifeLost(){
    this -> hp -= 1;
    if(this -> hp == 0){
        this -> hasLost = true;
    }
}