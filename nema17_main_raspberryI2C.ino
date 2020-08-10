//Красный и желтый, синий и зеленый
#include <Wire.h>

#define X_DIR 10
#define X_STP 11
#define SLAVE_ADDRESS 0x04

int delayTime = 5000; //Delay between each pause (uS)
char i2cData;
int stps = 200;

void step(byte stepperPin, int steps){
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepperPin, HIGH);
    delayMicroseconds(delayTime); 
    digitalWrite(stepperPin, LOW);
    delayMicroseconds(delayTime); 
  }
}

void setup(){
  Serial.begin(9600);
  pinMode(X_DIR, OUTPUT); 
  pinMode(X_STP, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  Serial.println("I2C Ready!");
}

void loop(){
  delay(100);
}

void receiveData(int byteCount) {
  while ( Wire.available()) {
    i2cData = Wire.read();
    if(i2cData == 0){
      digitalWrite(13, i2cData);
      Serial.println("ТУДА");
      digitalWrite(X_DIR, HIGH);
      step(X_STP, stps);
      delay(1000);

      Serial.println("ОБРАТНО");
      digitalWrite(X_DIR, LOW);
      step(X_STP, stps);
      delay(1000);
    }else{
      digitalWrite(13, i2cData);
    }
  }
}

void sendData(){
  Wire.write(1);
}
