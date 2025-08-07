
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX, TX

int cfpPin = 8; 
int bmsPin = 9; 
int eoppPin = 10; 
int startPin = 11; 

int led = 13;

void setup() {
  pinMode(cfpPin, INPUT);
  pinMode(bmsPin, INPUT);
  pinMode(eoppPin, INPUT);
  pinMode(startPin, INPUT);
  pinMode(led, OUTPUT);
  mySerial.begin(9600);
}


void loop() {
 
  int cfpState = digitalRead(cfpPin);   
  int bmsState = digitalRead(bmsPin); 
  int eoppState = digitalRead(eoppPin); 
  int startState = digitalRead(startPin); 
  
  if(cfpState == 1)
  {//if button is down
    mySerial.println(1111);//send unique code to the receiver in this case 1234    
  }
  delay(20);//delay little for better serial communication
  if(bmsState == 1)
  {//if button is down
    mySerial.println(2222);//send unique code to the receiver in this case 1234
  }
  delay(20);//delay little for better serial communication
  if(eoppState == 1)
  {//if button is down
    mySerial.println(3333);//send unique code to the receiver in this case 1234
  }
  delay(20);//delay little for better serial communication
  if(startState == 1)
  {//if button is down
    mySerial.println(4444);//send unique code to the receiver in this case 1234
  }
  delay(20);//delay little for better serial communication
}
