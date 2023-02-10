
// Botons to manage all
const int BTN_IZQ = 5;
const int BTN_INIT = 6;
const int BTN_DER = 7;
// Some variables to manage the configurate mode 
int btn_init_state;
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
  Serial.begin(1200);
  // declare buttons
  pinMode(BTN_IZQ, INPUT_PULLUP);
  pinMode(BTN_INIT, INPUT_PULLUP);
  pinMode(BTN_DER, INPUT_PULLUP);
  // take the time;
  timeMillis = millis(); // start capture the time
}

void initial_mode() {
  int init_status = digitalRead(BTN_INIT);
  if(init_status == LOW){
    // first check in what mode the app is
    if((millis() - previousMillis) >= interval){
      previousMillis = millis(); // capture the time when the mode was changed
      buttons_mode = 1;
      Serial.println("INIT button was changed to game mode");
      Serial.println("Button Middle held for 3 seconds");
    }               
  } else {
    previousMillis = millis();
  } 
  
  if(!digitalRead(BTN_IZQ)){
    Serial.println("Change the move of the loop text from left to right");
    delay(50); 
  }    

  if(!digitalRead(BTN_DER)){
    Serial.println("Change the move of the loop text from right to left");
    delay(50); 
  }    

}
void game_mode() {
  int init_status = digitalRead(BTN_INIT);
  if(init_status == LOW){
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
  
  if(!digitalRead(BTN_IZQ)){
    Serial.println("MOVE TO LEFT!");
    delay(50); 
  }    

  if(!digitalRead(BTN_DER)){
    Serial.println("MOVE TO RIGHT");
    delay(50); 
  } 
}
void configuration_mode() {
  int init_status = digitalRead(BTN_INIT);

  if(init_status == LOW){
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
      else if((millis() - previousMillis) >= interval_2){
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
  
  if(!digitalRead(BTN_IZQ)){
    Serial.println("REAMINING LIFES!");
    delay(50); 
  }    

  if(!digitalRead(BTN_DER)){
    Serial.println("CHANGE VOLUMEN!");
    delay(50); 
  } 
}
void loop() {
  // put your main code here, to run repeatedly:
  // evaluate the status of the buttons to know in which case we are
  switch (buttons_mode) {
    case 0:
      Serial.println("Running the text in a loop, waiting for a new instruction");
      initial_mode();
      break;
    case 1:
      Serial.println("Running the game, waiting to move or configuration mode");
      game_mode();
      break;
    case 2:
      Serial.println("Running the configuration screen, waiting to see lifes or change volumen or return");
      configuration_mode();
      break;
  }

}
