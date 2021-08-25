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

  // read the input on analog pin 0
  int handValue = analogRead(A0);

  // read the input on analog pin 1
  int gearValue = analogRead(A1);

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float handVoltage = handValue * (5.0 / 1023.0);

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float gearVoltage = gearValue * (5.0 / 1023.0);

  int hand = 0;

  int gear = 0;

  if (handVoltage < 1)
  {
    Serial.println("Hand Break is ON");
    hand = 1;
  }
  else
  {
    hand = 0;
    Serial.println("Hand Break is OFF");
  }

  if (gearVoltage < 1)
  {
    Serial.println("Neutral Gear is ON");
    gear = 1;
  }
  else
  {
    gear = 0;
    Serial.println("Neutral Gear is OFF");
  }

  boolean ledState = digitalRead(led);//check if the LED is turned on or off. Returns 1 or 0
  
  if(mySerial.available() > 1){    
    int input = mySerial.parseInt();//read serial input and convert to integer (-32,768 to 32,767)    
    Serial.print(input);
    if(millis() - last > 250){//if time now is 250 milliseconds greater than last time
      if(ledState == 0 && input == 2222){//if LED is off and button code is ok
        if(hand == 1 && gear == 1){
          digitalWrite(led, HIGH);
          digitalWrite(fuel , LOW);
          delay(3000);       
          digitalWrite(engine , LOW); 
          delay(1000);
          digitalWrite(engine , HIGH); 
        }
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
