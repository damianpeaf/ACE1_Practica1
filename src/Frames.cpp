#include "Frames.h"

//Numeros
bool no0[8][8] = {
  {0,0,0,1,1,1,1,0},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,0,1,1,1,1,0}
};
bool no1[8][8] = {
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1}
};
bool no2[8][8] = {
  {0,0,1,1,1,1,1,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,1,1,1,1,1,1},
  {0,0,1,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,1,1,1,1,1,1}
};
bool no3[8][8] = {
  {0,0,1,1,1,1,1,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,1,1,1,1,1,1}
};
bool no4[8][8] = {
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,1,1,1,1,1,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1}
};
bool no5[8][8] = {
  {0,0,1,1,1,1,1,1},
  {0,0,1,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,1,1,1,1,1,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,1,1,1,1,1,1}
};
bool no6[8][8] = {
  {0,0,1,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,1,1,1,1,1,1},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,1,1,1,1,1,1}
};
bool no7[8][8] = {
  {0,0,1,1,1,1,1,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1}
};
bool no8[8][8] = {
  {0,0,0,1,1,1,1,0},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,0,1,1,1,1,0},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,0,1,1,1,1,0}
};
bool no9[8][8] = {
  {0,0,0,1,1,1,1,0},
  {0,0,1,0,0,0,0,1},
  {0,0,1,0,0,0,0,1},
  {0,0,0,1,1,1,1,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1},
  {0,0,0,0,0,0,0,1}
};
//mensaje
bool letraP[8][8] = {
  {1,1,1,1,1,1,1,0},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,0},
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0}
};
bool letraR[8][8] = {
  {1,1,1,1,1,1,1,0},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,0},
  {1,0,0,0,1,1,0,0},
  {1,0,0,0,0,1,1,0},
  {1,0,0,0,0,0,1,1}
};
bool letraA[8][8] = {
  {0,1,1,1,1,1,1,0},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1}
};
bool letraG[8][8] = {
  {0,1,1,1,1,1,1,0},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {1,0,0,0,0,1,1,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {0,1,1,1,1,1,1,0}
};
bool letraU[8][8] = {
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {0,1,1,1,1,1,1,0}
};
bool letraO[8][8] = {
  {0,1,1,1,1,1,1,0},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {0,1,1,1,1,1,1,0}
};
bool letraB[8][8] = {
  {1,1,1,1,1,1,1,0},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,0},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,0}
};

//simbolos
bool interrogacionCierra[8][8]= {
  {0,1,1,1,1,1,1,0},
  {1,1,0,0,0,0,1,1},
  {1,0,0,0,0,0,1,1},
  {0,0,0,0,0,0,1,1},
  {0,0,0,0,0,1,1,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0,0}
};
bool interrogacionAbre[8][8] = {
  {0,0,0,1,1,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,1,1,0,0,0,0,0},
  {1,1,0,0,0,0,0,0},
  {1,1,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,1},
  {0,1,1,1,1,1,1,0}
};
bool signoIgual[8][8] = {
  {0,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {0,0,0,0,0,0,0,0},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};


//Objetivos Destruidos
bool destroy[8][8]{
  {1,1,1,0,0,1,1,1},
  {1,1,0,0,0,0,1,1},
  {1,0,1,0,0,1,0,1},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {1,0,1,0,0,1,0,1},
  {1,1,0,0,0,0,1,1},
  {1,1,1,0,0,1,1,1}
};
//Vidas
bool heart[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,0,0,1,1,0},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,0},
  {0,0,1,1,1,1,0,0},
  {0,0,0,1,1,0,0,0}
};
//Numeros pequeños
bool no01[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,0,0,1},
  {0,1,0,1,0,0,0,1},
  {0,1,0,1,0,0,0,1},
  {0,1,0,1,0,0,0,1},
  {0,1,1,1,0,0,0,1},
  {0,0,0,0,0,0,0,0}
};
bool no02[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,1,0,1,0,0,0,1},
  {0,1,0,1,0,1,1,1},
  {0,1,0,1,0,1,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no03[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,1,0,1,0,0,0,1},
  {0,1,0,1,0,1,1,1},
  {0,1,0,1,0,0,0,1},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no04[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,0,1},
  {0,1,0,1,0,1,0,1},
  {0,1,0,1,0,1,1,1},
  {0,1,0,1,0,0,0,1},
  {0,1,1,1,0,0,0,1},
  {0,0,0,0,0,0,0,0}
};
bool no05[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,1,0,1,0,0,0,1},
  {0,1,0,1,0,1,1,1},
  {0,1,0,1,0,1,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no06[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,1,0,1,0,1,0,0},
  {0,1,0,1,0,1,1,1},
  {0,1,0,1,0,1,0,1},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no07[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,1,0,1,0,0,0,1},
  {0,1,0,1,0,0,0,1},
  {0,1,0,1,0,0,0,1},
  {0,1,1,1,0,0,0,1},
  {0,0,0,0,0,0,0,0},
};
bool no08[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,1,0,1,0,1,0,1},
  {0,1,0,1,0,1,1,1},
  {0,1,0,1,0,1,0,1},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0},
};
bool no09[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,1,0,1,0,1,0,1},
  {0,1,0,1,0,1,1,1},
  {0,1,0,1,0,0,0,1},
  {0,1,1,1,0,0,0,1},
  {0,0,0,0,0,0,0,0},
};

void setMatrixNumber(int number, DualMatrixController *matrixController) {
  
  switch (number) {
    case 0:
      matrixController->setRightMatrix(no0);
      break;
    case 1:
      matrixController->setRightMatrix(no1);
      break;
    case 2:
      matrixController->setRightMatrix(no2);
      break;
    case 3:
      matrixController->setRightMatrix(no3);
      break;
    case 4:
      matrixController->setRightMatrix(no4);
      break;
    case 5:
      matrixController->setRightMatrix(no5);
      break;
    case 6:
      matrixController->setRightMatrix(no6);
      break;
    case 7:
      matrixController->setRightMatrix(no7);
      break;
    case 8:
      matrixController->setRightMatrix(no8);
      break;
    case 9:
      matrixController->setRightMatrix(no9);
    case 10:
      matrixController->setLeftMatrix(no1);
      matrixController->setRightMatrix(no0);
      break;
    case 11:
      matrixController->setLeftMatrix(no1);
      matrixController->setRightMatrix(no1);
      break;
    case 12:
      matrixController->setLeftMatrix(no1);
      matrixController->setRightMatrix(no2);
      break;
    case 13:

      matrixController->setLeftMatrix(no1);
      matrixController->setRightMatrix(no3);
      break;
    case 14:
      matrixController->setLeftMatrix(no1);
      matrixController->setRightMatrix(no4);
      break;
    case 15:
      matrixController->setLeftMatrix(no1);
      matrixController->setRightMatrix(no5);
      break;
    case 16:
      matrixController->setLeftMatrix(no1);
      matrixController->setRightMatrix(no6);
      break;
    case 17:
      matrixController->setLeftMatrix(no1);
      matrixController->setRightMatrix(no7);
      break;
    case 18:
      matrixController->setLeftMatrix(no1);
      matrixController->setRightMatrix(no8);
      break;
    case 19:
      matrixController->setLeftMatrix(no1);
      matrixController->setRightMatrix(no9);
      break;
    case 20:
      matrixController->setLeftMatrix(no2);
      matrixController->setRightMatrix(no0);
      break;
    case 21:
      matrixController->setLeftMatrix(no2);
      matrixController->setRightMatrix(no1);
      break;
    case 22:
      matrixController->setLeftMatrix(no2);
      matrixController->setRightMatrix(no2);
      break;
    case 23:
      matrixController->setLeftMatrix(no2);
      matrixController->setRightMatrix(no3);
      break;
    case 24:
      matrixController->setLeftMatrix(no2);
      matrixController->setRightMatrix(no4);
      break;
    case 25:
      matrixController->setLeftMatrix(no2);
      matrixController->setRightMatrix(no5);
      break;
    case 26:
      matrixController->setLeftMatrix(no2);
      matrixController->setRightMatrix(no6);
      break;
    case 27:
      matrixController->setLeftMatrix(no2);
      matrixController->setRightMatrix(no7);
      break;
    case 28:
      matrixController->setLeftMatrix(no2);
      matrixController->setRightMatrix(no8);
      break;
    case 29:
      matrixController->setLeftMatrix(no2);
      matrixController->setRightMatrix(no9);
      break;
    case 30:
      matrixController->setLeftMatrix(no3);
      matrixController->setRightMatrix(no0);
      break;
    case 31:
      matrixController->setLeftMatrix(no3);
      matrixController->setRightMatrix(no1);
      break;
    case 32:
      matrixController->setLeftMatrix(no3);
      matrixController->setRightMatrix(no2);
      break;
    case 33:
      matrixController->setLeftMatrix(no3);
      matrixController->setRightMatrix(no3);
      break;
    case 34:
      matrixController->setLeftMatrix(no3);
      matrixController->setRightMatrix(no4);
      break;
    case 35:
      matrixController->setLeftMatrix(no3);
      matrixController->setRightMatrix(no5);
      break;
    default:
      break;
  }
}
