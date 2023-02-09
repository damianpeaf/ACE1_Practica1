
#ifndef NoControllerMatrix_h
#define NoControllerMatrix_h

#include "Arduino.h"

class NoControllerMatrix {

    // TODO: Use a cpp file for this class  

  public:
    NoControllerMatrix(int rowPins[8], int columnPins[8]);
    
    void setMatrix(bool matrix[8][8]){
        for(int row = 0; row < 8; row++){

            // Turn on the row
            digitalWrite(rowPins[row], LOW);

            // Turn on the columns
            for(int column = 0; column < 8; column++){
                
                if(matrix[row][column]){
                    digitalWrite(columnPins[column], HIGH);
                }
            }

            // Delay
            delay(MULTIPLEXER_DELAY);

            // Turn off the row
            digitalWrite(rowPins[row], HIGH);

            // Turn off the columns
            for(int column = 0; column < 8; column++){
                digitalWrite(columnPins[column], LOW);
            }
        }
    };

    void initMatrix(){
        for(int pin = 0; pin < 8; pin++){
            pinMode(rowPins[row], OUTPUT);
            pinMode(columnPins[row], OUTPUT);
        }
    }

    void resetMatrix(){
        for(int pin = 0; pin < 8; pin++){
            digitalWrite(rowPins[row], LOW);
            digitalWrite(columnPins[row], HIGH);
        }
    }
    

  private:
    int MULTIPLEXER_DELAY = 1;
};

#endif