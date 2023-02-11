#ifndef Controllers_H
#define Controllers_H

#include "Arduino.h"

// Botons PINS
extern const int BTN_IZQ;
extern const int BTN_INIT;
extern const int BTN_DER;
extern const int POTR;


// Button previous states
extern int last_btn_left_state;
extern int last_btn_init_state;
extern int last_btn_right_state;

// MATRIX
extern bool controller_init_matrix;


// Some variables to manage the configurate mode 
extern unsigned long btn_init_start_time;
extern bool btn_init_pressed;

// Use millis to capture the time, intervals and modes
extern unsigned long timeMillis;
extern unsigned long previousMillis;
extern const long interval;
extern const long interval_2;
extern int buttons_mode;

void initial_mode();
void game_mode();
void configuration_mode();
void initiate_buttons();

#endif