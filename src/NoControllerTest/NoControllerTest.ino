#include "NoControllerMatrix.h"


int leftMatrixRowPins[8] = {30,31,32,33,34,35,36,37};
int leftMatrixColumnPins[8] = {40,41,42,43,44,45,46,47};

NoControllerMatrix leftMatrix(leftMatrixRowPins, leftMatrixColumnPins);


bool interrogacionAbre[8][8] = {
  {0,0,0,1,1,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,1,1,0,0,0,0,0},
  {1,1,0,0,0,0,0,0},
  {1,1,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,1},
  {0,1,1,1,1,1,1,0},
};

void setup() {

  leftMatrix.initMatrix();
  leftMatrix.resetMatrix();

}

void loop() {

  leftMatrix.setMatrix(interrogacionAbre);

}
