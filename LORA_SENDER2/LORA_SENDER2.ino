#include <SPI.h>
#include <LoRa.h> 
int buttonPin = 8;

int check = 10;

 
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

  int skip = 1;

  int val = 125;
  int val1 = 150;

  if(buttonState == 1)
  {
    if(check == 20 && skip==1)
    {
      LoRa.beginPacket(); 
      LoRa.print(val1);
      LoRa.endPacket();
      delay(500);
      check = 10;
      skip = 2;
      
    }
    else if(check == 10 && skip==1)
    {
      LoRa.beginPacket(); 
      LoRa.print(val);
      LoRa.endPacket();
      delay(500); 
      check = 20; 
    }     
  }
  
  delay(50);
 
}
