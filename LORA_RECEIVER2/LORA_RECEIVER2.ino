#include <SPI.h>
#include <LoRa.h> 
int LED = 3;
#define fuel 4
#define engine 5
String inString = "";    // string to hold input
int val = 100;
 
void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  pinMode(fuel, OUTPUT);
  pinMode(engine, OUTPUT);
  digitalWrite(fuel, HIGH);
  digitalWrite(engine, HIGH);
  
  while (!Serial);
  Serial.println("LoRa Receiver");
  if (!LoRa.begin(433E6)) { // or 915E6
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
 
void loop() {
  
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) { 
    // read packet    
    while (LoRa.available())
    {
      int inChar = LoRa.read();
      inString += (char)inChar;
      val = inString.toInt();
      if( val == 125)
      {  
       digitalWrite(LED,HIGH); 
       digitalWrite(fuel , LOW);
       delay(3000);       
       digitalWrite(engine , LOW); 
       delay(1000);
       digitalWrite(engine , HIGH);       
                   
      } 
      else if( val == 150)
      {
         digitalWrite(LED, LOW);     
      }
    }
    inString = "";     
    LoRa.packetRssi();    
  }
      
  Serial.println(val);  
  //analogWrite(LED, val);
  delay(50);
  
}
