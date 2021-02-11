// First we inclue the libraries
#include <OneWire.h>
#include <DallasTemperature.h>

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
}

void loop(void) {
  // put your main code here, to run repeatedly:
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus

  Serial.print("Requesting temperatures...");
  sensors.requestTemperatures();
  // Send the command to get temperature readings

  Serial.println("DONE");

  Serial.print("Temperature is:");
  Serial.print(sensors.getTempCByIndex(0));
  Serial.print((char)176); //shows degrees character
  Serial.print("C | ");
  // Why "byIndex"?
  //You can have more than one DS18B20 on the same bus.
  // 0 refers to the first IC on the wire
  delay(2000);

}
