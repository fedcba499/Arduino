#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Servo.h>

SoftwareSerial mySerial(2, 3); // RX, TX

Servo myServo;

#define ONE_WIRE_BUS 4

int vibPin = 5;

int servoPosn = 0;

#define glowPlug 8
#define engHeat 9

int ledPin = 13;

unsigned long last = millis();//set timer

float temp;

float temp_1;

int tempPin = 0;

// Setup a OneWire instance to communicate with any OneWire Devices
//(not just Maxim/Dallas temperature ICs)

OneWire oneWire(ONE_WIRE_BUS);

//Pass our oneWire reference to Dallas Temperature

DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(vibPin, INPUT);
  sensors.begin();
  Serial.println("Temperature Sensor");
  myServo.attach(6);
  pinMode(glowPlug, OUTPUT);
  pinMode(engHeat, OUTPUT);

  digitalWrite(glowPlug, HIGH);
  digitalWrite(engHeat, HIGH);
}

void loop() {

  boolean ledState = digitalRead(ledPin);//check if the LED is turned on or off. Returns 1 or 0

  int val;

  
  
  // call sensors.requestTemperatures() to issue a global temperature
  // request to all devices on the bus
  Serial.print("Requesting temperatures...");
  
  sensors.requestTemperatures();
  // Send the command to get temperature readings

  Serial.println("DONE");

  // read analog volt from sensor and save to variable temp

  temp = sensors.getTempCByIndex(0);

  temp_1 = 1000.00 + temp;
  
  Serial.println(val);
  
  mySerial.println(int(temp_1));
  delay(20);
  //send unique code to the receiver in this case 1000 + temp

  if (val == 1)
  {
    temp_1 = temp_1 + 100;
    delay(20);
    Serial.println("vib = ON");
  }                                                                                                         
  
  Serial.print("Temperature = ");
  Serial.print(temp); // display temperature value
  Serial.print("*C");
  Serial.println();

  
  
  if(mySerial.available() > 1){    
    int input = mySerial.parseInt();//read serial input and convert to integer (-32,768 to 32,767)    
    Serial.print("1234");
    if(millis() - last > 250)
    {
      //if time now is 250 milliseconds greater than last time
      if(ledState == 0 && input == 1111)
      {
      
        //if LED is off and button code is ok
          digitalWrite(ledPin, HIGH);
          for (servoPosn = 0; servoPosn <=180; servoPosn +=1)
          {            
            myServo.write(servoPosn);
            delay(10);
          }       
      }
      else if(ledState == 1 && input == 2222)
      {
        //if LED is on and button code is ok
          digitalWrite(ledPin, LOW); 
          for (servoPosn=180; servoPosn >= 0; servoPosn -=1)
          {
            myServo.write(servoPosn);
            delay(10);
          }
      } 
      
    }
    
    mySerial.flush();//clear the serial buffer for unwanted inputs   
    last = millis();//reset timer   
  }
  delay(20);//delay little for better serial communication
  delay(1000); //update sensor reading after every second
  val = digitalRead(vibPin);
 
}
