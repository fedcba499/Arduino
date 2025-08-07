// First we inclue the libraries
#include <OneWire.h>
#include <DallasTemperature.h>

#define ledPin 13
#define fuel 5
#define engine 6

//Data wire is pluggd into pin 2 on the Arduino
#define ONE_WIRE_BUS 4

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
  Serial.println("Dallas Temperature IC Control Library Demo");
  pinMode(ledPin, OUTPUT);  
  pinMode(fuel, OUTPUT);
  pinMode(engine, OUTPUT);
  digitalWrite(fuel, HIGH);
  digitalWrite(engine, HIGH);
}

void loop(void) {
  // put your main code here, to run repeatedly:
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus

  boolean ledState = digitalRead(ledPin);

  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();
  // Send the command to get temperature readings

  Serial.println("DONE");

  Serial.print("Temperature is:");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print("*C | ");
  // Why "byIndex"?
  //You can have more than one DS18B20 on the same bus.
  // 0 refers to the first IC on the wire

  if (sensors.getTempCByIndex(0) < 5 && ledState == 0)
  {
    digitalWrite(ledPin,HIGH); 
    digitalWrite(fuel , LOW);
    delay(3000);       
    digitalWrite(engine , LOW); 
    delay(1000);
    digitalWrite(engine , HIGH);  
  }
  delay (20);
  if (sensors.getTempCByIndex(0) > 15 && ledState == 1)
  {
    digitalWrite(ledPin,LOW);
    digitalWrite(fuel , HIGH);  
  }
  
  delay(2000);

}
