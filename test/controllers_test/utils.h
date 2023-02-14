#ifndef utils_H
#define utils_H

extern bool fullMessage [8][143];

extern bool resizedMessage [8][16];
extern int currentLeftSideCol;

void cycleMessageLeft();
void computeResizedMessage();
void cycleMessageRight();

#endif