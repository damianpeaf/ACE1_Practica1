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

#include "Controllers.h"
#include "DualMatrixController.h"
#include "Breakout.h"
#include "utils.h"


int leftMatrixRowPins[8] = {30,31,32,33,34,35,36,37};
int leftMatrixColumnPins[8] = {40,41,42,43,44,45,46,47};

NoDriverMatrix leftMatrix(leftMatrixRowPins, leftMatrixColumnPins);

//DIN,CLK,LOAD,#Devices
LedControl rightMatrix(11, 13, 10, 1);

DualMatrixController screen(&leftMatrix, &rightMatrix);

unsigned long actualTime = millis();

Breakout breakout;

void setup() {

  Serial.begin(9600);
  screen.initMatrix();
  breakout.reset();
  cycleMessageLeft();
  initiate_buttons();
}

void loop() {

  // evaluate the status of the buttons to know in which case we are
  switch (buttons_mode) {

    // Initial Message MODE
    case 0:
      // Serial.println("Running the text in a loop, waiting for a new instruction");
      screen.setMatrix(resizedMessage);
      if(!controller_init_matrix){
        if (millis() - actualTime > map(analogRead(POTR), 0, 255, 40, 100)) {
          actualTime = millis();
          cycleMessageLeft();
        }
      }else {
        if (millis() - actualTime > map(analogRead(POTR), 0, 255, 40, 100)) {
          actualTime = millis();
          cycleMessageRight();
        }        
      }
      initial_mode();
      break;
    
    // Game MODE
    case 1:
      // Serial.println("Running the game, waiting to move or configuration mode");
      breakout.refreshMatrix();
      screen.setMatrix(breakout.matrix);
      game_mode();
      break;
    
    // Configuration MODE
    case 2:
      // Serial.println("Running the configuration screen, waiting to see lifes or change volumen or return");
      configuration_mode();
      break;
  }

}