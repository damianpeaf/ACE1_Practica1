// IMPORTS
#include <LedControl.h>
#include "DualMatrixController.h"
#include "Breakout.h"
#include "utils.h"
// MATRIX 
bool controller_init_matrix = false;
int leftMatrixRowPins[8] = {30,31,32,33,34,35,36,37};
int leftMatrixColumnPins[8] = {40,41,42,43,44,45,46,47};
NoDriverMatrix leftMatrix(leftMatrixRowPins, leftMatrixColumnPins);

//DIN,CLK,LOAD,#Devices
LedControl rightMatrix(11, 13, 10, 1);
DualMatrixController screen(&leftMatrix, &rightMatrix);
unsigned long actualTime = millis();
Breakout breakout;

// Botons to manage all
const int BTN_IZQ = 5;
const int BTN_INIT = 6;
const int BTN_DER = 7;

int btn_left_state;
int btn_init_state;
int btn_right_state;

int last_btn_left_state = HIGH;
int last_btn_init_state = HIGH;
int last_btn_right_state = HIGH;
// Some variables to manage the configurate mode 
unsigned long btn_init_start_time;
bool btn_init_pressed = false;

// Use millis to capture the time, intervals and modes
unsigned long timeMillis;
unsigned long previousMillis = 0;
const long interval = 3000;
const long interval_2 = 2000;
int buttons_mode = 0; // 0 is the first mode to control the text loop, 1 to control the game mode, and 2 the pause / configurate mode

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // declare buttons
  pinMode(BTN_IZQ, INPUT_PULLUP);
  pinMode(BTN_INIT, INPUT_PULLUP);
  pinMode(BTN_DER, INPUT_PULLUP);
  // INIT MATRIX
  screen.initMatrix();
  breakout.reset();
  cycleMessageLeft();  
}

void initial_mode() {
  int btn_left_state = digitalRead(BTN_IZQ);
  int btn_init_state = digitalRead(BTN_INIT);
  int btn_right_state = digitalRead(BTN_DER);
  
  if(btn_init_state == LOW){
    // first check in what mode the app is
    if((millis() - previousMillis) >= interval){
      previousMillis = millis(); // capture the time when the mode was changed
      buttons_mode = 1;
      Serial.println("INIT button was changed to game mode");
      Serial.println("Button Middle held for 3 seconds");
      controller_init_matrix = false;
    }               
  } else {
    previousMillis = millis();
  } 
  
  if(btn_left_state == LOW && last_btn_left_state == HIGH){
    controller_init_matrix = false;
    Serial.println("Change the move of the loop text from left to right");
    delay(50); 
  }    

  if(btn_right_state == LOW && last_btn_right_state == HIGH){
    controller_init_matrix = true;
    Serial.println("Change the move of the loop text from right to left");
    delay(50);
  }  
  
  last_btn_left_state = btn_left_state; 
  last_btn_init_state = btn_init_state; 
  last_btn_right_state = btn_right_state; 
     

}
void game_mode() {
  int btn_left_state = digitalRead(BTN_IZQ);
  int btn_init_state = digitalRead(BTN_INIT);
  int btn_right_state = digitalRead(BTN_DER);
  if(btn_init_state == LOW){
    // first check in what mode the app is
    if((millis() - previousMillis) >= interval){
      previousMillis = millis(); // capture the time when the mode was changed
      buttons_mode = 2;
      Serial.println("INIT button was changed to configurate mode");
      Serial.println("Button Middle held for 3 seconds");
    }               
  } else {
    previousMillis = millis();
  } 
  
  if(btn_left_state == LOW && last_btn_left_state == HIGH){
    Serial.println("MOVE TO LEFT!");
    delay(50); 
     
  }    

  if(btn_right_state == LOW && last_btn_right_state == HIGH){
    Serial.println("MOVE TO RIGHT!");
    delay(50); 
    
  }  
  last_btn_left_state = btn_left_state; 
  last_btn_init_state = btn_init_state; 
  last_btn_right_state = btn_right_state; 
}
void configuration_mode() {
  int btn_left_state = digitalRead(BTN_IZQ);
  int btn_init_state = digitalRead(BTN_INIT);
  int btn_right_state = digitalRead(BTN_DER);

  if(btn_init_state == LOW){
    if(!btn_init_pressed){
      btn_init_start_time = millis();
      btn_init_pressed = true;
    }else {
      if((millis()- btn_init_start_time) >= interval){
        previousMillis = millis(); // capture the time when the mode was changed
        buttons_mode = 0;
        btn_init_pressed = false;                
        Serial.println("THE GAME WAS CANCELED!");
        Serial.println("Button Middle held for 3 seconds");   
      }
      else if((millis() - previousMillis) >= interval){
      previousMillis = millis(); // capture the time when the mode was changed
      buttons_mode = 1;
      btn_init_pressed = false;  
      Serial.println("RESUMING GAME!");
      Serial.println("Button Middle held for 2 seconds");
      }
    }
  }else {
    if(btn_init_pressed) {
      btn_init_pressed = false;      
    }
  }
  
  if(btn_left_state == LOW && last_btn_left_state == HIGH){
    Serial.println("SEE REMAINING LIFES");
    delay(50); 
     
  }    

  if(btn_right_state == LOW && last_btn_right_state == HIGH){
    Serial.println("CHANGE VOLUME");
    delay(50); 
    
  }  
  last_btn_left_state = btn_left_state; 
  last_btn_init_state = btn_init_state; 
  last_btn_right_state = btn_right_state; 
}
void loop() {
  // put your main code here, to run repeatedly:
  // evaluate the status of the buttons to know in which case we are
  switch (buttons_mode) {
    case 0:
      // Serial.println("Running the text in a loop, waiting for a new instruction");
      if(!controller_init_matrix){
        screen.setMatrix(resizedMessage);
        if (millis() - actualTime > 100) {
          actualTime = millis();
          cycleMessageLeft();
        }
      }else {
        screen.setMatrix(resizedMessage);
        if (millis() - actualTime > 100) {
          actualTime = millis();
          cycleMessageRight();
        }        
      }
      initial_mode();
      break;
    case 1:
      // Serial.println("Running the game, waiting to move or configuration mode");
      breakout.refreshMatrix();
      screen.setMatrix(breakout.matrix);
      game_mode();
      break;
    case 2:
      // Serial.println("Running the configuration screen, waiting to see lifes or change volumen or return");
      configuration_mode();
      break;
  }

}
