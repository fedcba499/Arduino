#include <VirtualWire.h>
#define ledPin 6
#define fuel 4
#define engine 5
 

void setup()
{
    vw_set_rx_pin(11);
    vw_setup(2000);
    pinMode(ledPin, OUTPUT);    
    vw_rx_start();
    pinMode(fuel, OUTPUT);
    pinMode(engine, OUTPUT);
    digitalWrite(fuel, HIGH);
    digitalWrite(engine, HIGH);
}

void loop()
{
        
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;     
 
    if (vw_get_message(buf, &buflen))
    {
      
      if(buf[0]=='a')
      {  
       digitalWrite(ledPin,HIGH); 
       digitalWrite(fuel , LOW);
       delay(3000);       
       digitalWrite(engine , LOW); 
       delay(1000);
       digitalWrite(engine , HIGH);       
                   
      }  
      else if(buf[0]=='b')
      {      
       digitalWrite(ledPin,LOW);
       digitalWrite(fuel , HIGH);        
     
      }
    }
}
