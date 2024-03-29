#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX


#define fuel 4
#define engine 5

int led = 13;

unsigned long last = millis();//set timer

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(fuel, OUTPUT);
  pinMode(engine, OUTPUT);
  digitalWrite(fuel, HIGH);
  digitalWrite(engine, HIGH);
}

void loop() {

  boolean ledState = digitalRead(led);//check if the LED is turned on or off. Returns 1 or 0
  
  if(mySerial.available() > 1){    
    int input = mySerial.parseInt();//read serial input and convert to integer (-32,768 to 32,767)    
    Serial.print(input);
    if(millis() - last > 250){//if time now is 250 milliseconds greater than last time
      if(ledState == 0 && input == 2222){//if LED is off and button code is ok
          digitalWrite(led, HIGH);
          digitalWrite(fuel , LOW);
          delay(3000);       
          digitalWrite(engine , LOW); 
          delay(1000);
          digitalWrite(engine , HIGH);
      }else if(ledState == 1 && input == 2222){//if LED is on and button code is ok
          digitalWrite(led, LOW);
          digitalWrite(fuel , HIGH); 
      }
      
    }
    
    mySerial.flush();//clear the serial buffer for unwanted inputs   
    last = millis();//reset timer   
  }
  delay(20);//delay little for better serial communication
 
}
