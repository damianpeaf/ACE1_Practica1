
#ifndef NoControllerMatrix_h
#define NoControllerMatrix_h

#include "Arduino.h"

class NoControllerMatrix {

  public:
    NoControllerMatrix(int rp[8], int cp[8]);
    
    void setMatrix(bool matrix[8][8]);

    void initMatrix(void);

    void resetMatrix(void);

  private:
    int MULTIPLEXER_DELAY = 1;
    int rowPins[8];
    int columnPins[8];
};

#endif