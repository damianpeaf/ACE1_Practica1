
#include "Controllers.h"

const int BTN_IZQ = 5;
const int BTN_INIT = 6;
const int BTN_DER = 7;
const int POTR = A0;
const int BUZZER = 8;
int buzzer_freq = 500;


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
unsigned long timeToDisplayScore = 0;
unsigned long previousMillis = 0;
unsigned long updateMillis = 0;
const long interval = 3000;
const long interval_2 = 2000;
int buttons_mode = 0; // 0 is the first mode to control the text loop, 1 to control the game mode, and 2 the pause / configurate mode

// Separeted functions
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
// Initial Message logic for buttons
void initial_mode() {
  
  change_init_0();
  move_left_0();
  move_right_0();
  
  last_btn_left_state = digitalRead(BTN_IZQ); 
  last_btn_init_state = digitalRead(BTN_INIT); 
  last_btn_right_state = digitalRead(BTN_DER); 
     

}
// Buttons logic
void move_left_1(Breakout *game){
  if(digitalRead(BTN_IZQ) == LOW && last_btn_left_state == HIGH){
    Serial.println("MOVE TO LEFT!");
    game -> movePaddleLeft();
    game->refreshMatrix();
  }
}
void move_right_1( Breakout *game) {
  if(digitalRead(BTN_DER) == LOW && last_btn_right_state == HIGH){
    Serial.println("MOVE TO RIGHT!");   
    game -> movePaddleRight();
    game->refreshMatrix();   
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

// Game logic for buttons
void game_mode(DualMatrixController *screen, Breakout *game) {

  // TODO: RESET THE GAME FOR FIRST TIME

  // * CONTROL INPUTS
  change_init_1();
  move_left_1(game);    
  move_right_1(game);
  
  last_btn_left_state = digitalRead(BTN_IZQ); 
  last_btn_init_state = digitalRead(BTN_INIT); 
  last_btn_right_state = digitalRead(BTN_DER);

  // * UPDATE GAME

  if (millis() - updateMillis >= 1000) {
    updateMillis = millis();
    game->update();

    // * GAME LOST/WON
    if(game -> hasLost){
      Serial.println("GAME OVER");
      // TODO: SHOW SCORE
      while(true) {
        setMatrixNumber(game -> score, screen);
        if(millis() - timeToDisplayScore >= 3000) {
          break;
        }
      }
      buttons_mode = 0;

    }

    if(game -> hasWon){
        Serial.println("YOU WON");
        sound_buzzer(1500);
        delay(1500);
        buttons_mode = 0;
    }

    // * Collision detection
    if (game -> hasCollided){
      sound_buzzer(100);
      game -> hasCollided = false;
    }

    game->refreshMatrix();
  }

  screen->setMatrix(game -> matrix);

}

// Configurate/pause logic for buttons
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

void initiate_buttons() {
  pinMode(BTN_IZQ, INPUT_PULLUP);
  pinMode(BTN_INIT, INPUT_PULLUP);
  pinMode(BTN_DER, INPUT_PULLUP);
}

void initiate_buzzer() {
  pinMode(BUZZER, OUTPUT);
}

void sound_buzzer(int duration) {
  tone(BUZZER, buzzer_freq, duration);
}