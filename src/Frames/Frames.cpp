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
bool no08[8][] {
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
