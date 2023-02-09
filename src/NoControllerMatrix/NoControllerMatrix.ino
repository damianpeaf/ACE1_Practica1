#include <LedControl.h>
#include "DualMatrixController.h"


int leftMatrixRowPins[8] = {30,31,32,33,34,35,36,37};
int leftMatrixColumnPins[8] = {40,41,42,43,44,45,46,47};

NoControllerMatrix leftMatrix(leftMatrixRowPins, leftMatrixColumnPins);

//DIN,CLK,LOAD,#Devices
LedControl rightMatrix(11, 13, 10, 1);

DualMatrixController screen(&leftMatrix, &rightMatrix);

unsigned long actualTime = millis();

bool dots[8][16] = {
  {0,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
  {0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,1},
  {0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,1},
  {0,1,1,1,1,1,1,0,0,1,1,1,1,1,1,0},
};


void cycleMatrix() {
  bool colAux [8];

  for (int i = 0; i < 8; i++) {
    colAux[i] = dots[i][0];
  }

  for (int col = 0; col < 15; col++){
    for (int row = 0; row < 8; row++){
      dots[row][col] = dots[row][col + 1];
    }
  }

  for (int i = 0; i < 8; i++) {
    dots[i][15] = colAux[i];
  }

}

void setup() {

  Serial.begin(9600);
  screen.initMatrix();

}

void loop() {

  screen.setMatrix(dots);

  if (millis() - actualTime > 1000) {
    actualTime = millis();
    cycleMatrix();
  }

}
