// First we inclue the libraries
#include <OneWire.h>
#include <DallasTemperature.h>

//Data wire is pluggd into pin 2 on the Arduino
#define ONE_WIRE_BUS 4

int ledPin = 13;
#define fuel 8
#define engine 9



float temp = 10.00;

// Setup a OneWire instance to communicate with any OneWire Devices
//(not just Maxim/Dallas temperature ICs)

OneWire oneWire(ONE_WIRE_BUS);

//Pass our oneWire reference to Dallas Temperature

DallasTemperature sensors(&oneWire);

void setup() {
    // Start up the library
  sensors.begin();
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(fuel, OUTPUT);
  pinMode(engine, OUTPUT);
  digitalWrite(fuel, HIGH);
  digitalWrite(engine, HIGH);
}

void loop(void) {

  boolean ledState = digitalRead(ledPin);//check if the LED is turned on or off. Returns 1 or 0
  
  // put your main code here, to run repeatedly:
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus

  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();
  // Send the command to get temperature readings

  Serial.println("DONE");

  Serial.print("Temperature is:");
  temp = sensors.getTempCByIndex(0);
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print((char)176); //shows degrees character
  Serial.print("C | ");

  
  // Why "byIndex"?
  //You can have more than one DS18B20 on the same bus.
  // 0 refers to the first IC on the wire
  

  if(ledState == 0 && temp < 5){//if LED is off and button code is ok
          digitalWrite(ledPin, HIGH);
          digitalWrite(fuel , LOW);
          delay(3000);       
          digitalWrite(engine , LOW); 
          delay(1000);
          digitalWrite(engine , HIGH); 
      }else if(ledState == 1 && temp > 20 ){//if LED is on and button code is ok
          digitalWrite(ledPin, LOW);
          digitalWrite(fuel , HIGH); 
      }
  delay(1000);

}
