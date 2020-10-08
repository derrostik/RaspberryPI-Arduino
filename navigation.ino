/*
 * Ардуино получает сигнал на пин с пишки. Всегда идет сигнал 1,
 * Поэтому я его инвертирую, и с пишки отправляю сигнал 0, чтобы
 * ардуино получило 0, инвертировала и запустила светодиод, иначе вечное
 * мигание светодиода. Это связано с тем, что есть помехи, которые
 * конвертируются в постоянный сигнал 1, и только при подключении к земле
 * срабатывает единичное действие.
 */


#define ledPin 13
#define inPin 7
#define outPin 8
#define X_DIR 5
#define X_STP 6

#include <SoftwareSerial.h>

SoftwareSerial Serial_2(2, 3); // RX, TX


int val = 0;
int delayTime = 1000;
int stps = 1000;
 
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(outPin, OUTPUT);
  pinMode(X_DIR, OUTPUT); 
  pinMode(X_STP, OUTPUT);
  pinMode(inPin, INPUT_PULLUP);
  Serial.println("Start");
}

bool flag = 0;

void loop()
{
  val = digitalRead(inPin);
  if(val){
    digitalWrite(ledPin, val);
    /*digitalWrite(X_DIR, LOW);
    step(X_STP, stps);*/
  }else{
    digitalWrite(ledPin, val);
    Serial.println(val);
    delay(5000);
    /*digitalWrite(X_DIR, HIGH);
    step(X_STP, stps);*/
    //ОТКРЫТЬ КРЫШУ
  }
  
}

void step(byte stepperPin, int steps){
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepperPin, HIGH);
    delayMicroseconds(delayTime); 
    digitalWrite(stepperPin, LOW);
    delayMicroseconds(delayTime); 
  }
}
