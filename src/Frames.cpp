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
bool no00[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,0,0,1},
  {0,1,0,1,0,0,0,1},
  {0,1,0,1,0,0,0,1},
  {0,1,0,1,0,0,0,1},
  {0,1,1,1,0,0,0,1},
  {0,0,0,0,0,0,0,0}
};
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
bool no10[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,1,0,1},
  {0,0,0,1,0,1,0,1},
  {0,0,0,1,0,1,0,1},
  {0,0,0,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no11[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,0,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,0,0,0,0,0}
};
bool no12[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,1,0,0},
  {0,0,0,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no13[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no14[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,0,1,0,1},
  {0,0,0,1,0,1,0,1},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,0,0,0,0,0}
};
bool no15[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,1,0,0},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no16[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,1,0,0},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,1,0,1},
  {0,0,0,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no17[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,0,0,0,0,0},
};

bool no18[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,1,0,1},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,1,0,1},
  {0,0,0,1,0,1,1,1},
  {0,0,0,0,0,0,0,0},
};

bool no19[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,1,0,1},
  {0,0,0,1,0,1,1,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,0,0,0,0,0,0,0},
};
bool no20[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,1,0,1},
  {0,1,1,1,0,1,0,1},
  {0,1,0,0,0,1,0,1},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no21[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,1,1,1,0,0,0,1},
  {0,1,0,0,0,0,0,1},
  {0,1,1,1,0,0,0,1},
  {0,0,0,0,0,0,0,0}
};

bool no22[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,0,0,1},
  {0,1,1,1,0,1,1,1},
  {0,1,0,0,0,1,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no23[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,0,0,1},
  {0,1,1,1,0,1,1,1},
  {0,1,0,0,0,0,0,1},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no24[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,0,1},
  {0,0,0,1,0,1,0,1},
  {0,1,1,1,0,1,1,1},
  {0,1,0,0,0,0,0,1},
  {0,1,1,1,0,0,0,1},
  {0,0,0,0,0,0,0,0}
};
bool no25[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,0,0,1},
  {0,1,1,1,0,1,1,1},
  {0,1,0,0,0,1,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no26[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,1,0,1,0,1,0,0},
  {0,1,1,1,0,1,1,1},
  {0,1,0,0,0,1,0,1},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no27[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,0,0,1},
  {0,1,1,1,0,0,0,1},
  {0,1,0,0,0,0,0,1},
  {0,1,1,1,0,0,0,1},
  {0,0,0,0,0,0,0,0},
};
bool no28[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,1,0,1},
  {0,1,1,1,0,1,1,1},
  {0,1,0,0,0,1,0,1},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0},
};
bool no29[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,1,0,1},
  {0,1,1,1,0,1,1,1},
  {0,1,0,0,0,0,0,1},
  {0,1,1,1,0,0,0,1},
  {0,0,0,0,0,0,0,0},
};
bool no30[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,1,0,1},
  {0,1,1,1,0,1,0,1},
  {0,0,0,1,0,1,0,1},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no31[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,1,1,1,0,0,0,1},
  {0,0,0,1,0,0,0,1},
  {0,1,1,1,0,0,0,1},
  {0,0,0,0,0,0,0,0}
};
bool no32[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,0,0,1},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,1,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no33[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,0,0,1},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};
bool no34[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,0,1},
  {0,0,0,1,0,0,0,1},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,0,0,0},
  {0,1,1,1,0,0,0,1},
  {0,0,0,0,0,0,0,0}
};
bool no35[8][8] {
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,1,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,1,0,0,0,0},
  {0,1,1,1,0,1,1,1},
  {0,0,0,0,0,0,0,0}
};

void setMatrixNumberHP(int number, DualMatrixController *matrixController) {
  
  switch (number) {
    case 0:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no00);
      break;
    case 1:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no01);
      break;
    case 2:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no02);
      break;
    case 3:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no03);
      break;
    case 4:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no04);
      break;
    case 5:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no05);
      break;
    case 6:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no06);
      break;
    case 7:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no07);
      break;
    case 8:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no08);
      break;
    case 9:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no09);
    case 10:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no10);
      break;
    case 11:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no11);
      break;
    case 12:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no12);
      break;
    case 13:

      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no13);
      break;
    case 14:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no14);
      break;
    case 15:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no15);
      break;
    case 16:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no16);
      break;
    case 17:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no17);
      break;
    case 18:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no18);
      break;
    case 19:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no19);
      break;
    case 20:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no20);
      break;
    case 21:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no21);
      break;
    case 22:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no22);
      break;
    case 23:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no23);
      break;
    case 24:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no24);
      break;
    case 25:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no25);
      break;
    case 26:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no26);
      break;
    case 27:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no27);
      break;
    case 28:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no28);
      break;
    case 29:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no29);
      break;
    case 30:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no30);
      break;
    case 31:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no31);
      break;
    case 32:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no32);
      break;
    case 33:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no33);
      break;
    case 34:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no34);
      break;
    case 35:
      matrixController->setLeftMatrix(heart);
      matrixController->setRightMatrix(no35);
      break;
    default:
      break;
  }
}

void setMatrixNumberScore(int number, DualMatrixController *matrixController) {
  
  switch (number) {
    case 0:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no00);
      break;
    case 1:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no01);
      break;
    case 2:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no02);
      break;
    case 3:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no03);
      break;
    case 4:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no04);
      break;
    case 5:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no05);
      break;
    case 6:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no06);
      break;
    case 7:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no07);
      break;
    case 8:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no08);
      break;
    case 9:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no09);
    case 10:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no10);
      break;
    case 11:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no11);
      break;
    case 12:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no12);
      break;
    case 13:

      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no13);
      break;
    case 14:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no14);
      break;
    case 15:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no15);
      break;
    case 16:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no16);
      break;
    case 17:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no17);
      break;
    case 18:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no18);
      break;
    case 19:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no19);
      break;
    case 20:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no20);
      break;
    case 21:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no21);
      break;
    case 22:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no22);
      break;
    case 23:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no23);
      break;
    case 24:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no24);
      break;
    case 25:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no25);
      break;
    case 26:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no26);
      break;
    case 27:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no27);
      break;
    case 28:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no28);
      break;
    case 29:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no29);
      break;
    case 30:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no30);
      break;
    case 31:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no31);
      break;
    case 32:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no32);
      break;
    case 33:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no33);
      break;
    case 34:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no34);
      break;
    case 35:
      matrixController->setLeftMatrix(destroy);
      matrixController->setRightMatrix(no35);
      break;
    default:
      break;
  }
}

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



