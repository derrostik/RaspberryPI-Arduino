#include <Wire.h>

#define SLAVE_ADDRESS 0x04
 
char i2cData;
 
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  Serial.println("I2C Ready!");
}
 
void loop() {
  delay(100);
}

void receiveData(int byteCount) {
  while ( Wire.available()) {
    i2cData = Wire.read();
    digitalWrite(13, i2cData);
  }
}

void sendData(){
  while (Wire.available()) {
    Wire.write("1");
    delay(1000);
    Serial.println("AAA");
  }
}
