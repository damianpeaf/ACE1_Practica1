#include "LedControl.h" // Import library to manage MAX
LedControl m_1 = LedControl(11,13,10,1); // DIn, CLK, LOAD, Devices
bool dots[8][8] = {
// 0   1  2  3  4  5  6  7 
  {1, 1, 1, 1, 1, 1, 1, 1}, // 0
  {0, 0, 0, 0, 0, 0, 0, 0}, // 1
  {0, 0, 0, 0, 0, 0, 0, 0}, // 2
  {0, 0, 0, 0, 0, 0, 0, 0}, // 3
  {0, 0, 0, 0, 0, 0, 0, 0}, // 4
  {0, 0, 0, 0, 0, 0, 0, 0}, // 5
  {0, 0, 0, 0, 0, 0, 0, 0}, // 6
  {0, 0, 0, 0, 0, 0, 0, 0}  // 7
};
// define the byte
byte heart[8] = {
  B00000000,
  B01100110,
  B10011001,
  B10000001,
  B10000001,
  B01000010,
  B00100100,
  B00011000,
};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200); // Frecuency
  // Configurations to the drive matrix
  m_1.shutdown(0, false); // save energy and turn on
  m_1.setIntensity(0, 15); // Dispositive and Brightness 
  m_1.clearDisplay(0); // Clean the matrix
}

void iniMatrix() {
  for( int p= 30; p<38; p++) {
    pinMode(p, OUTPUT);
    pinMode(p+10, OUTPUT);
  }
}
void show_heart() {
  for(int i =0; i<8; i++) {
    m_1.setRow(0, i, heart[i]); // Device, the row, value
  }
}
void resetMatrix() {
  for(int p= 30; p<38; p++) {
    digitalWrite(p,0);
    digitalWrite(p+10, 1);
  }
}

void setMatrix() {
  for(int row = 30; row<38; row++ ) {
    //
    digitalWrite(row, LOW);
    for(int col= 40; col < 48; col++){
      //
      if( dots[row-30][col-40]){
        digitalWrite(col, HIGH);
      }
    }
    // 
    delay(1);
    digitalWrite(row, HIGH);
    for(int col= 40; col < 48; col++){
      //
      if( dots[row-30][col-40]){
        digitalWrite(col, LOW);
      }
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  iniMatrix();
  // resetMatrix();
  setMatrix();
  show_heart();
}
