//Красный и желтый, синий и зеленый

//Direction pin
#define X_DIR 10

//Step pin
#define X_STP 11

int delayTime = 5000; //Delay between each pause (uS)

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
}

void loop(){

  Serial.println("ТУДА");
  digitalWrite(X_DIR, HIGH);
  step(X_STP, stps);
  delay(1000);

  Serial.println("ОБРАТНО");
  digitalWrite(X_DIR, LOW);
  step(X_STP, stps);
  delay(1000);

}
