
#ifndef DualMatrixController_h
#define DualMatrixController_h

#include "Arduino.h"
#include <LedControl.h>

#include "NoDriverMatrix.h"

class DualMatrixController {

    public:
        DualMatrixController(
            NoDriverMatrix *leftMatrix,
            LedControl *rightMatrix
        );

    void setMatrix(bool matrix[8][16]);

    void initMatrix(void);

    void resetMatrix(void);

    private:
        NoDriverMatrix *leftMatrix;
        LedControl *rightMatrix;
};

#endif
