#ifndef Controllers_H
#define Controllers_H

#include "Arduino.h"
#include "DualMatrixController.h"
#include "Breakout.h"
#include "Frames.h"

// Botons PINS
extern const int BTN_IZQ;
extern const int BTN_INIT;
extern const int BTN_DER;

// Potenciometer PIN
extern const int POTR;

// Buzzer PIN
extern const int BUZZER;
extern int buzzer_freq;

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
extern int buttons_mode;

void initial_mode();
void game_mode(DualMatrixController *screen, Breakout *game);
void configuration_mode(DualMatrixController *screen, int vidas);
void initiate_buttons();
void sound_buzzer(int duration);
void calculate_volume();

#endif