
int cfpPin = 8; 
int bmsPin = 9; 
int eoppPin = 10; 
int startPin = 11; 

#define cfp 4
#define bms 5
#define eopp 6
#define start 7

int led = 13;

void setup() {
  pinMode(cfpPin, INPUT);
  pinMode(bmsPin, INPUT);
  pinMode(eoppPin, INPUT);
  pinMode(startPin, INPUT);
  pinMode(cfp, OUTPUT);
  pinMode(bms, OUTPUT);
  pinMode(eopp, OUTPUT);
  pinMode(start, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(cfp, HIGH);
  digitalWrite(bms, HIGH);
  digitalWrite(eopp, HIGH);
  digitalWrite(start, HIGH);
}

void loop() {
 
  int cfpState = digitalRead(cfpPin);   
  int bmsState = digitalRead(bmsPin); 
  int eoppState = digitalRead(eoppPin); 
  int startState = digitalRead(startPin); 
  
  if(cfpState == 1)
  {//if button is down
    digitalWrite(cfp, LOW);
    delay(5000);
    digitalWrite(cfp, HIGH);
  }
  if(bmsState == 1)
  {//if button is down
    digitalWrite(bms, LOW);
  }
  if(eoppState == 1)
  {//if button is down
    digitalWrite(eopp, LOW);
    delay(5000);
    digitalWrite(eopp, HIGH);
  }
  if(startState == 1)
  {//if button is down
    digitalWrite(start, LOW);
    delay(4000);
    digitalWrite(start, HIGH);
  }
 delay(20);
}
