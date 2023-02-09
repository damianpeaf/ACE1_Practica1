
#ifndef DualMatrixController_h
#define DualMatrixController_h

#include "Arduino.h"
#include <LedControl.h>

#include "NoControllerMatrix.h"

class DualMatrixController {

    public:
        DualMatrixController(
            NoControllerMatrix *leftMatrix,
            LedControl *rightMatrix
        );

    void setMatrix(bool matrix[8][16]);

    void initMatrix(void);

    void resetMatrix(void);

    private:
        NoControllerMatrix *leftMatrix;
        LedControl *rightMatrix;
};

#endif
