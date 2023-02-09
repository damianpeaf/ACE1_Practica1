
#ifndef NoControllerMatrix_h
#define NoControllerMatrix_h

#include "Arduino.h"

class NoControllerMatrix {

    // TODO: Use a cpp file for this class  

  public:
    NoControllerMatrix(int rp[8], int cp[8]) {
        for(int i = 0; i < 8; i++){
            this->rowPins[i] = rp[i];
            this->columnPins[i] = cp[i];
        }
    }
    
    void setMatrix(bool matrix[8][8]){
        for(int row = 0; row < 8; row++){

            // Turn on the row
            digitalWrite(this->rowPins[row], LOW);

            // Turn on the columns
            for(int column = 0; column < 8; column++){
                
                if(matrix[row][column]){
                    digitalWrite(this->columnPins[column], HIGH);
                }
            }

            // Delay
            delay(MULTIPLEXER_DELAY);

            // Turn off the row
            digitalWrite(this->rowPins[row], HIGH);

            // Turn off the columns
            for(int column = 0; column < 8; column++){
                digitalWrite(this->columnPins[column], LOW);
            }
        }
    };

    void initMatrix(){
        for(int pin = 0; pin < 8; pin++){
            pinMode(this->rowPins[pin], OUTPUT);
            pinMode(this->columnPins[pin], OUTPUT);
        }
    }

    void resetMatrix(){
        for(int pin = 0; pin < 8; pin++){
            digitalWrite(this->rowPins[pin], LOW);
            digitalWrite(this->columnPins[pin], HIGH);
        }
    }
    

  private:
    int MULTIPLEXER_DELAY = 1;
    int rowPins[8];
    int columnPins[8];
};

#endif