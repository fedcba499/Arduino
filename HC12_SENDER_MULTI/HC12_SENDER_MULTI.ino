
#include <SoftwareSerial.h>

#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

SoftwareSerial mySerial(2, 3); //RX, TX

int buttonPin_1 = 8;

int buttonPin_2 = 9;

int buttonPin_3 = 10;

unsigned long last = millis();//set timer

void setup() {
  pinMode(buttonPin_1, INPUT);
  pinMode(buttonPin_2, INPUT);
  pinMode(buttonPin_3, INPUT);
  mySerial.begin(9600);
  Serial.begin(9600);
  // Setup the LCD's number of coloumns and rows
  lcd.begin(20,4);
  lcd.setCursor( 3, 0);
  lcd.print("201 ENGR REGT");
   
}

void loop() 
{
 
  int buttonState_1 = digitalRead(buttonPin_1);
  int buttonState_2 = digitalRead(buttonPin_2);
  int buttonState_3 = digitalRead(buttonPin_3);
  
  if(buttonState_1 == 1)
  {
    //if button is down
    mySerial.println(1111);//send unique code to the receiver in this case 1111
  }
  delay(20);//delay little for better serial communication

  if(buttonState_2 == 1)
  {
    //if button is down
    mySerial.println(2222);//send unique code to the receiver in this case 2222
  }
  delay(20);//delay little for better serial communication

  if(buttonState_3 == 1)
  {
    //if button is down
    mySerial.println(3333);//send unique code to the receiver in this case 3333
  }
  delay(20);//delay little for better serial communication

   if(mySerial.available() > 1)
    {    
      int input = mySerial.parseInt();//read serial input and convert to integer (-32,768 to 32,767)    
      Serial.print("1234");
      if(millis() - last > 250)
      {
        //if time now is 250 milliseconds greater than last time
        if(input > 1000 && input<2000)
        {
          //Print on Serial moniter as Temp of 1
            Serial.print("Temperature of 1 = ");
            Serial.print(input - 1000); // display temperature value
            Serial.print("*C");
            Serial.println();

            lcd.setCursor( 0, 1);
            lcd.print("V-1 ENG=OF TEMP=");
            lcd.print(int(input-1000));
            lcd.print("^C");
            
            
        }
        delay(20);

        if(input > 2000 && input < 3000)
        {
          //Print on Serial moniter as Temp of 1
            Serial.print("Temperature of 2 = ");
            Serial.print(input - 2000); // display temperature value
            Serial.print("*C");
            Serial.println();

            lcd.setCursor( 0, 2);
            lcd.print("V-2 ENG=OF TEMP=");
            lcd.print(int(input-2000));
            lcd.print("^C");
            
            
        }
        delay(20);

        if(input > 3000 && input<4000)
        {
          //Print on Serial moniter as Temp of 1
            Serial.print("Temperature of 1 = ");
            Serial.print(input - 3000); // display temperature value
            Serial.print("*C");
            Serial.println();

            lcd.setCursor( 0, 3);
            lcd.print("V-3 ENG=OF TEMP=");
            lcd.print(int(input-3000));
            lcd.print("^C");
            
        }
        delay(20);    

      
      }
      
      mySerial.flush();//clear the serial buffer for unwanted inputs   
      last = millis();//reset timer   
    }
  
}
