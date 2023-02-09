/*
    Código fuente - Práctica 1 - Arquitectura de Computadores y Ensambladores 1
    Grupo:  07
    Integrantes:
        - Alvaro Norberto García Meza 202109567
        - Damián Ignacio Peña Afre 202110568
        - Daniel Estuardo Cuque Ruíz 202112145
        - José Manuel Ibarra Pirir 202001800
*/

#include "NoControllerMatrix/NoControllerMatrix.h"
#include "NoControllerMatrix/NoControllerMatrix.cpp"

#include "Frames/Frames.h"
#include "Frames/Frames.cpp"


int leftMatrixRowPins[8] = {30,31,32,33,34,35,36,37};
int leftMatrixColumnPins[8] = {40,41,42,43,44,45,46,47};

NoControllerMatrix leftMatrix(leftMatrixRowPins, leftMatrixColumnPins);

void setup() {

  leftMatrix.initMatrix();
  leftMatrix.resetMatrix();

}

void loop() {

  leftMatrix.setMatrix(signoIgual);

}