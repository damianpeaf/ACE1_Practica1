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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(1200); // Frecuency
  
}

void iniMatrix() {
  for( int p= 30; p<38; p++) {
    pinMode(p, OUTPUT);
    pinMode(p+10, OUTPUT);
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
}
