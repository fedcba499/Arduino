#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

#define cfp 4
#define bms 5
#define eopp 6
#define start 7

int led = 13;

unsigned long last = millis();//set timer

void setup() {
  mySerial.begin(9600);
  pinMode(cfp, OUTPUT);
  pinMode(bms, OUTPUT);
  pinMode(eopp, OUTPUT);
  pinMode(start, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(cfp, HIGH);
  digitalWrite(bms, HIGH);
  digitalWrite(eopp, HIGH);
  digitalWrite(start, HIGH); 
}

void loop() {

if(mySerial.available() > 1)
{    
    int input = mySerial.parseInt();//read serial input and convert to integer (-32,768 to 32,767)    

    if(millis() - last > 250)
    {//if time now is 250 milliseconds greater than last time
    
        if(input == 1111)
        {//if button is down
          digitalWrite(cfp, LOW);
          delay(5000);
          digitalWrite(cfp, HIGH);
        }
        if(input == 2222)
        {//if button is down
          digitalWrite(bms, LOW);
        }
        if(input == 3333)
        {//if button is down
          digitalWrite(eopp, LOW);
          delay(5000);
          digitalWrite(eopp, HIGH);
        }
        if(input == 4444)
        {//if button is down
          digitalWrite(start, LOW);
          delay(4000);
          digitalWrite(start, HIGH);
        }
    }

    mySerial.flush();//clear the serial buffer for unwanted inputs   
    last = millis();//reset timer   
  }
 delay(20);//delay little for better serial communication
}
