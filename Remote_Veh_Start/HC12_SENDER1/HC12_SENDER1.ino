
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX, TX

int buttonPin = 8;

int buttonPin2 = 9;


void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  mySerial.begin(9600);
}

void loop() {
 
  int buttonState = digitalRead(buttonPin);
  int buttonState2 = digitalRead(buttonPin2);
  
  if(buttonState == 1){//if button is down
    mySerial.println(1234);//send unique code to the receiver in this case 1234
  }
  delay(20);//delay little for better serial communication

  if(buttonState2 == 1){//if button is down
    mySerial.println(4321);//send unique code to the receiver in this case 1234
  }
  delay(20);//delay little for better serial communication
}
