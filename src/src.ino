/*
    Código fuente - Práctica 1 - Arquitectura de Computadores y Ensambladores 1
    Grupo:  07
    Integrantes:
        - Alvaro Norberto García Meza 202109567
        - Damián Ignacio Peña Afre 202110568
        - Daniel Estuardo Cuque Ruíz 202112145
        - José Manuel Ibarra Pirir 202001800
*/

#include <LedControl.h>

#include "NoControllerMatrix/NoControllerMatrix.h"
#include "NoControllerMatrix/NoControllerMatrix.cpp"

#include "NoControllerMatrix/DualMatrixController.h"
#include "NoControllerMatrix/DualMatrixController.cpp"

#include "breakout/Breakout.h"


int leftMatrixRowPins[8] = {30,31,32,33,34,35,36,37};
int leftMatrixColumnPins[8] = {40,41,42,43,44,45,46,47};

NoControllerMatrix leftMatrix(leftMatrixRowPins, leftMatrixColumnPins);

//DIN,CLK,LOAD,#Devices
LedControl rightMatrix(11, 13, 10, 1);

DualMatrixController screen(&leftMatrix, &rightMatrix);

unsigned long actualTime = millis();

Breakout breakout;

bool fullMessage [8][143] = {
  //     ¿                   P                   R                    A                  1                   =                    G                   R                    U                 P                     O                 0                   7                    =                     B                ?                                   
  {0,0,0,1,1,0,0,0, 0, 1,1,1,1,1,1,1,0, 0, 1,1,1,1,1,1,1,0, 0, 0,1,1,1,1,1,1,0, 0, 0,0,0,1,0,0,0,0, 0, 0,0,0,0,0,0,0,0, 0, 0,1,1,1,1,1,1,0, 0, 1,1,1,1,1,1,1,0, 0, 1,0,0,0,0,0,0,1, 0, 1,1,1,1,1,1,1,0, 0, 0,1,1,1,1,1,1,0, 0, 0,0,0,1,1,1,1,0, 0, 0,0,1,1,1,1,1,1, 0, 0,0,0,0,0,0,0,0, 0, 1,1,1,1,1,1,1,0, 0, 0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 0,0,0,1,0,0,0,0, 0, 1,1,1,1,1,1,1,1, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 0,0,1,0,0,0,0,1, 0, 0,0,0,0,0,0,0,1, 0, 1,1,1,1,1,1,1,1, 0, 1,0,0,0,0,0,0,1, 0, 1,1,0,0,0,0,1,1},
  {0,0,0,1,1,0,0,0, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 0,0,0,1,0,0,0,0, 0, 1,1,1,1,1,1,1,1, 0, 1,0,0,0,0,0,0,0, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 0,0,1,0,0,0,0,1, 0, 0,0,0,0,0,0,0,1, 0, 1,1,1,1,1,1,1,1, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,1,1},
  {0,1,1,0,0,0,0,0, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 0,0,0,1,0,0,0,0, 0, 0,0,0,0,0,0,0,0, 0, 1,0,0,0,0,0,0,0, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,1, 0, 0,0,1,0,0,0,0,1, 0, 0,0,0,0,0,0,0,1, 0, 0,0,0,0,0,0,0,0, 0, 1,1,1,1,1,1,1,0, 0, 0,0,0,0,0,0,1,1},
  {1,1,0,0,0,0,0,0, 0, 1,1,1,1,1,1,1,0, 0, 1,1,1,1,1,1,1,0, 0, 1,1,1,1,1,1,1,1, 0, 0,0,0,1,0,0,0,0, 0, 1,1,1,1,1,1,1,1, 0, 1,0,0,0,0,1,1,1, 0, 1,1,1,1,1,1,1,0, 0, 1,0,0,0,0,0,0,1, 0, 1,1,1,1,1,1,1,0, 0, 1,0,0,0,0,0,0,1, 0, 0,0,1,0,0,0,0,1, 0, 0,0,0,0,0,0,0,1, 0, 1,1,1,1,1,1,1,1, 0, 1,0,0,0,0,0,0,1, 0, 0,0,0,0,0,1,1,0},
  {1,1,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,0, 0, 1,0,0,0,1,1,0,0, 0, 1,0,0,0,0,0,0,1, 0, 0,0,0,1,0,0,0,0, 0, 1,1,1,1,1,1,1,1, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,1,1,0,0, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,0, 0, 1,0,0,0,0,0,0,1, 0, 0,0,1,0,0,0,0,1, 0, 0,0,0,0,0,0,0,1, 0, 1,1,1,1,1,1,1,1, 0, 1,0,0,0,0,0,0,1, 0, 0,0,0,1,1,0,0,0},
  {1,1,0,0,0,0,1,1, 0, 1,0,0,0,0,0,0,0, 0, 1,0,0,0,0,1,1,0, 0, 1,0,0,0,0,0,0,1, 0, 0,0,0,1,0,0,0,0, 0, 0,0,0,0,0,0,0,0, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,1,1,0, 0, 1,0,0,0,0,0,0,1, 0, 1,0,0,0,0,0,0,0, 0, 1,0,0,0,0,0,0,1, 0, 0,0,1,0,0,0,0,1, 0, 0,0,0,0,0,0,0,1, 0, 0,0,0,0,0,0,0,0, 0, 1,0,0,0,0,0,0,1, 0, 0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0, 0, 1,0,0,0,0,0,0,0, 0, 1,0,0,0,0,0,1,1, 0, 1,0,0,0,0,0,0,1, 0, 0,0,0,1,0,0,0,0, 0, 0,0,0,0,0,0,0,0, 0, 0,1,1,1,1,1,1,0, 0, 1,0,0,0,0,0,1,1, 0, 0,1,1,1,1,1,1,0, 0, 1,0,0,0,0,0,0,0, 0, 0,1,1,1,1,1,1,0, 0, 0,0,0,1,1,1,1,0, 0, 0,0,0,0,0,0,0,1, 0, 0,0,0,0,0,0,0,0, 0, 1,1,1,1,1,1,1,0, 0, 0,0,0,1,1,0,0,0}
};

bool resizedMessage [8][16];
int currentLeftSideCol = 0;


void cycleMessageLeft () {
  
  computeResizedMessage();

  currentLeftSideCol++;

  if (currentLeftSideCol == 142) {
    currentLeftSideCol = 0;
  } 
}

void computeResizedMessage() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 16; j++) {
      
      if(j+currentLeftSideCol <= 142) {
        resizedMessage[i][j] = fullMessage[i][j+currentLeftSideCol];
      }else {
        resizedMessage[i][j] = fullMessage[i][j+currentLeftSideCol-143];
      }
    }
  }
}

void cycleMessageRight(){
  
  computeResizedMessage();

  currentLeftSideCol--;

  if (currentLeftSideCol == -1) {
    currentLeftSideCol = 142;
  } 
}

void setup() {

  Serial.begin(9600);
  screen.initMatrix();
  breakout.reset();
  cycleMessageLeft();

}

void loop() {

  // TEST BREAKOUT 
  // breakout.refreshMatrix();
  // screen.setMatrix(breakout.matrix);

  screen.setMatrix(resizedMessage);

  if (millis() - actualTime > 100) {
    actualTime = millis();
    cycleMessageLeft();
  }

}



// ? prev cycle function
// void cycleMatrix() {
//   bool colAux [8];

//   for (int i = 0; i < 8; i++) {
//     colAux[i] = dots[i][0];
//   }

//   for (int col = 0; col < 15; col++){
//     for (int row = 0; row < 8; row++){
//       dots[row][col] = dots[row][col + 1];
//     }
//   }

//   for (int i = 0; i < 8; i++) {
//     dots[i][15] = colAux[i];
//   }

// }