#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

int ledPin = 13;

unsigned long last = millis();//set timer

float temp;

float temp_2;

int tempPin = 0;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  boolean ledState = digitalRead(ledPin);//check if the LED is turned on or off. Returns 1 or 0

  temp = analogRead(tempPin);
  // read analog volt from sensor and save to variable temp

  temp = temp * 0.48828125;
  //convert the analog volt to its temperature equivalent

  temp_2 = 2000.00 + temp;
  
  Serial.print("Temperature = ");
  Serial.print(temp); // display temperature value
  Serial.print("*C");
  Serial.println();

  mySerial.println(temp_2);//send unique code to the receiver in this case 1000 + temp
  
  if(mySerial.available() > 1){    
    int input = mySerial.parseInt();//read serial input and convert to integer (-32,768 to 32,767)    

    if(millis() - last > 250)
    {
      //if time now is 250 milliseconds greater than last time
      if(ledState == 0 && input == 2222)
      {
        //if LED is off and button code is ok
          digitalWrite(ledPin, HIGH);
      }
      else if(ledState == 1 && input == 2222)
      {
        //if LED is on and button code is ok
          digitalWrite(ledPin, LOW); 
      } 
      
    }
    
    mySerial.flush();//clear the serial buffer for unwanted inputs   
    last = millis();//reset timer   
  }
  delay(20);//delay little for better serial communication
  delay(1000); //update sensor reading after every second
 
}
