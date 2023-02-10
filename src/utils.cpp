
#include "utils.h"

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