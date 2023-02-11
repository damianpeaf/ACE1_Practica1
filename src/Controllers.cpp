
#include "Controllers.h"

const int BTN_IZQ = 5;
const int BTN_INIT = 6;
const int BTN_DER = 7;
const int POTR = A0;


// Button previous states
int last_btn_left_state = HIGH;
int last_btn_init_state = HIGH;
int last_btn_right_state = HIGH;

// MATRIX
bool controller_init_matrix = false;


// Some variables to manage the configurate mode 
unsigned long btn_init_start_time;
bool btn_init_pressed = false;

// Use millis to capture the time, intervals and modes
unsigned long timeMillis;
unsigned long previousMillis = 0;
const long interval = 3000;
const long interval_2 = 2000;
int buttons_mode = 0; // 0 is the first mode to control the text loop, 1 to control the game mode, and 2 the pause / configurate mode



// Initial Message logic for buttons
void initial_mode() {
  
  if(digitalRead(BTN_INIT) == LOW){
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
  
  if(digitalRead(BTN_IZQ) == LOW && last_btn_left_state == HIGH){
    controller_init_matrix = false;
    Serial.println("Change the move of the loop text from left to right");
    delay(50); 
  }    

  if(digitalRead(BTN_DER) == LOW && last_btn_right_state == HIGH){
    controller_init_matrix = true;
    Serial.println("Change the move of the loop text from right to left");
    delay(50);
  }  
  
  last_btn_left_state = digitalRead(BTN_IZQ); 
  last_btn_init_state = digitalRead(BTN_INIT); 
  last_btn_right_state = digitalRead(BTN_DER); 
     

}

// Game logic for buttons
void game_mode() {
  if(digitalRead(BTN_INIT) == LOW){
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
  
  if(digitalRead(BTN_IZQ) == LOW && last_btn_left_state == HIGH){
    Serial.println("MOVE TO LEFT!");
    delay(50); 
     
  }    

  if(digitalRead(BTN_DER) == LOW && last_btn_right_state == HIGH){
    Serial.println("MOVE TO RIGHT!");
    delay(50); 
    
  }  
  last_btn_left_state = digitalRead(BTN_IZQ); 
  last_btn_init_state = digitalRead(BTN_INIT); 
  last_btn_right_state = digitalRead(BTN_DER); 
}

// Configurate/pause logic for buttons
void configuration_mode() {

  if(digitalRead(BTN_INIT) == LOW){
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
  
  if(digitalRead(BTN_IZQ) == LOW && last_btn_left_state == HIGH){
    Serial.println("SEE REMAINING LIFES");
    delay(50); 
     
  }    

  if(digitalRead(BTN_DER) == LOW && last_btn_right_state == HIGH){
    Serial.println("CHANGE VOLUME");
    delay(50); 
    
  }  
  last_btn_left_state = digitalRead(BTN_IZQ); 
  last_btn_init_state = digitalRead(BTN_INIT); 
  last_btn_right_state = digitalRead(BTN_DER); 
}

void initiate_buttons() {
  pinMode(BTN_IZQ, INPUT_PULLUP);
  pinMode(BTN_INIT, INPUT_PULLUP);
  pinMode(BTN_DER, INPUT_PULLUP);
}