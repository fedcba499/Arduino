#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

int ledPin = 13;
int ledPin2 = 12;
#define battery 4
#define fuel 5
#define oil 6
#define pnumatic 7
#define self 8

unsigned long last = millis();//set timer

void setup() {
  mySerial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(battery, OUTPUT);
  pinMode(fuel, OUTPUT);
  pinMode(oil, OUTPUT);
  pinMode(pnumatic, OUTPUT);
  pinMode(self, OUTPUT);
  
  digitalWrite(battery , HIGH); 
  digitalWrite(fuel , HIGH); 
  digitalWrite(oil , HIGH); 
  digitalWrite(pnumatic , HIGH); 
  digitalWrite(self , HIGH);


}

void loop() {

  boolean ledState = digitalRead(ledPin);//check if the LED is turned on or off. Returns 1 or 0
  boolean ledState2 = digitalRead(ledPin2);
  
  if(mySerial.available() > 1){    
    int input = mySerial.parseInt();//read serial input and convert to integer (-32,768 to 32,767)    

    if(millis() - last > 250){//if time now is 250 milliseconds greater than last time
      if(ledState == 0 && input == 1234){//if LED is off and button code is ok
          digitalWrite(ledPin, HIGH);
          digitalWrite(battery , LOW);
          delay(2000);
          digitalWrite(fuel , LOW);
          delay(5000); 
          digitalWrite(fuel , HIGH); 
          delay(2000);   
          digitalWrite(fuel , LOW);  
          delay(5000); 
          digitalWrite(fuel , HIGH);
          delay(1000);
          digitalWrite(oil , LOW);
          delay(5000);
          digitalWrite(oil , HIGH);
          delay(2000);
          digitalWrite(oil , LOW);
          delay(5000);
          digitalWrite(oil , HIGH);
          delay(1000);
          digitalWrite(pnumatic , LOW); 
          delay(5000);
          digitalWrite(pnumatic , HIGH); 
          
      }else if(ledState2 == 0 && input == 4321){//if LED is on and button code is ok
          digitalWrite(pnumatic , LOW); 
          digitalWrite(self , LOW);
          delay(5000);
          digitalWrite(pnumatic , HIGH); 
          digitalWrite(self , HIGH);
      }else if(ledState == 1 && input == 1234){//if LED is on and button code is ok
          digitalWrite(ledPin, LOW); 
      }
      else if(ledState2 == 1 && input == 4321){//if LED is on and button code is ok
          digitalWrite(ledPin, LOW); 
      }
      
      
    }
    
    mySerial.flush();//clear the serial buffer for unwanted inputs   
    last = millis();//reset timer   
  }
  delay(20);//delay little for better serial communication
 
}
