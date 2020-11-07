#define ledPin 13
#define openPin 2
#define closePin 3
#define X_DIR 5
#define X_STP 6

int open = 0;
int close = 0;
int delayTime = 1000;
int stps = 1000;
 
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(openPin, INPUT_PULLUP);
  pinMode(X_DIR, OUTPUT); 
  pinMode(X_STP, OUTPUT);
  pinMode(closePin, INPUT_PULLUP);
  Serial.println("Start");
}

bool flag = 0;

void loop()
{
  open = digitalRead(openPin);
  if(open){
    digitalWrite(ledPin, open);
    Serial.println("Open roof");
    delay(5000);
    /*digitalWrite(X_DIR, LOW);
    step(X_STP, stps);*/
  }else{
    digitalWrite(ledPin, open);
  }
 close = digitalRead(closePin);
 if(close){
   digitalWrite(ledPin, close);
   Serial.println("Close roof");
   delay(5000);
   /*digitalWrite(X_DIR, LOW);
   step(X_STP, stps);*/
  }else{
   digitalWrite(ledPin, close);
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
