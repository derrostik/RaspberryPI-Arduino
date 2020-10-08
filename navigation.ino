#define ledPin 13
#define navPin 7
#define X_DIR 5
#define X_STP 6

int navigation = 0;
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
  navigation = digitalRead(navPin);
  if(navigation){
    digitalWrite(ledPin, 0);
    /*digitalWrite(X_DIR, LOW);
    step(X_STP, stps);*/
  }else{
    digitalWrite(ledPin, 1);
    Serial.println("Navigation");
    delay(5000);
    /*digitalWrite(X_DIR, HIGH);
    step(X_STP, stps);*/
    //НАВИГАЦИЯ
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
