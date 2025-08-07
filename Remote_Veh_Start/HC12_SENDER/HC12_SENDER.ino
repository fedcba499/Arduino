
#include <SoftwareSerial.h>

#include <LiquidCrystal.h>

SoftwareSerial mySerial(2, 3); //RX, TX

const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int buttonPin = 8; 

void setup() {
  pinMode(buttonPin, INPUT);
  mySerial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor( 1, 0);
  lcd.print("201 ENGR REGT"); 
}

void loop() {
 
  int buttonState = digitalRead(buttonPin);   
  
  if(buttonState == 1)
  {//if button is down
    mySerial.println(1234);//send unique code to the receiver in this case 1234
  }
  delay(20);//delay little for better serial communication
}
