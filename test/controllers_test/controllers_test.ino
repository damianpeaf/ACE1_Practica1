// IMPORTS
#include <LedControl.h>
#include "DualMatrixController.h"
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


// Botons to manage all
const int BTN_IZQ = 5;
const int BTN_INIT = 6;
const int BTN_DER = 7;
const int POTR = A0;

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
  cycleMessageLeft();  
}
void move_left_0(){
  if(digitalRead(BTN_IZQ) == LOW && last_btn_left_state == HIGH){
    controller_init_matrix = false;
    Serial.println("Change the move of the loop text from left to right");
  }   
}
void move_right_0() {
  if(digitalRead(BTN_DER) == LOW && last_btn_right_state == HIGH){
    controller_init_matrix = true;
    Serial.println("Change the move of the loop text from right to left");
  }  
}
void change_init_0(){
  if(digitalRead(BTN_INIT) == LOW){
    // first check in what mode the app is
    if((millis() - previousMillis) >= interval){
      previousMillis = millis(); // capture the time when the mode was changed
      buttons_mode = 1;
      Serial.println("INIT button was changed to game mode");
      Serial.println("Button Middle held for 3 seconds");
      controller_init_matrix = false;
      return true;
    }               
  } else {
    previousMillis = millis();
  }  
}
void initial_mode() {
  change_init_0();
  move_left_0();
  move_right_0();
    
  last_btn_left_state = digitalRead(BTN_IZQ); 
  last_btn_init_state = digitalRead(BTN_INIT); 
  last_btn_right_state = digitalRead(BTN_DER); 
}

void move_left_1(){
  if(digitalRead(BTN_IZQ) == LOW && last_btn_left_state == HIGH){
    Serial.println("MOVE TO LEFT!");
  }
}
void move_right_1() {
  if(digitalRead(BTN_DER) == LOW && last_btn_right_state == HIGH){
    Serial.println("MOVE TO RIGHT!");      
  }  
}

void change_init_1(){
  if(digitalRead(BTN_INIT) == LOW){
    // first check in what mode the app is
    if((millis() - previousMillis) >= interval){
      previousMillis = millis(); // capture the time when the mode was changed
      buttons_mode = 2;
      Serial.println("INIT button was changed to configurate mode");
      Serial.println("Button Middle held for 3 seconds");
      configuration_mode();
    }               
  } else {
    previousMillis = millis();
  } 
}
void game_mode() {
  screen.initMatrix();
  change_init_1();
  move_left_1();    
  move_right_1();
  last_btn_left_state = digitalRead(BTN_IZQ); 
  last_btn_init_state = digitalRead(BTN_INIT); 
  last_btn_right_state = digitalRead(BTN_DER);
}

void move_left_2(){
  if(digitalRead(BTN_IZQ) == LOW && last_btn_left_state == HIGH){
    Serial.println("SEE REMAINING LIFES");
  }  
}
void move_right_2(){
  if(digitalRead(BTN_DER) == LOW && last_btn_right_state == HIGH){
    Serial.println("CHANGE VOLUME");
  }  
}
void configuration_mode() {
  while(true){
    if(digitalRead(BTN_INIT) == LOW){

    btn_init_start_time = millis();
    while(digitalRead(BTN_INIT) == LOW){
      //  
    }
    unsigned long restTime = millis();
    
    Serial.println(restTime - btn_init_start_time);
    if((restTime - btn_init_start_time) >= 3000){
      previousMillis = millis(); // capture the time when the mode was changed
      buttons_mode = 0;
      btn_init_pressed = false;  
      Serial.println("THE GAME WAS CANCELED!");
      Serial.println("Button Middle held for 3 seconds");  
      return;
    }
    else if((restTime - btn_init_start_time) >= 2000){
      previousMillis = millis(); // capture the time when the mode was changed
      buttons_mode = 1;
      btn_init_pressed = false;
      Serial.println("RESUMING GAME!");
      Serial.println("Button Middle held for 2 seconds");
      return;                
    }
  }

  move_left_2();
  move_right_2();

  last_btn_left_state = digitalRead(BTN_IZQ); 
  last_btn_init_state = digitalRead(BTN_INIT); 
  last_btn_right_state = digitalRead(BTN_DER);

  }
}

void mode_0() {
  while(buttons_mode != 1){
    initial_mode();
    screen.setMatrix(resizedMessage);
    if(!controller_init_matrix){
      if (millis() - actualTime > map(analogRead(POTR), 0, 255, 40, 100)) {
        actualTime = millis();
        cycleMessageLeft();
      }
    }else {
      if (millis() - actualTime > map(analogRead(POTR), 0, 255, 40, 100)) {
        actualTime = millis();
        cycleMessageRight();
      }         
    }
  }
}



void loop() {
  // put your main code here, to run repeatedly:
  // evaluate the status of the buttons to know in which case we are
  mode_0();
  game_mode();
}
