#include <SPI.h>
#include <LoRa.h> 
int buttonPin = 8;
 
void setup() {
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);
  
  
  while (!Serial);  
  Serial.println("LoRa Sender");
  if (!LoRa.begin(433E6)) { // or 915E6, the MHz speed of yout module
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}
 
void loop() {

  int buttonState = digitalRead(buttonPin);

  int val = 255;
  int val1 = 0;

  if(buttonState == 0){
    LoRa.beginPacket(); 
    LoRa.print(val);
    LoRa.endPacket();
    
  }


    if(buttonState == 1 ){
    LoRa.beginPacket(); 
    LoRa.print(val1);
    LoRa.endPacket();
    
  }

  delay(5000);
 
}
