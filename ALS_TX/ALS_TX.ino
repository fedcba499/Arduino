#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

SoftwareSerial mySerial(2, 3); // RX, TX

const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int buttonPin_1 = 8;

int buttonPin_2 = 9;

int buttonPin_3 = 10;

int led = 13;

unsigned long last = millis();//set timer

const byte numRows = 4;
const byte numCols = 4;

char keymap[numRows][numCols]= 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','c'},
  {'*','0','#','D'},
};

byte rowPins[numRows] = {22,24,26,28};
// Rows 0 to 3

byte colPins[numCols] = {30,32,34,36};
// Cols 0 to 3

// initialize an instance of Keypad class

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

int k = 0;

int j = 0;

int i = 0;

char password[4];

char masterPassword[4] = "2489";

void setup() {
  pinMode(buttonPin_1, INPUT);
  pinMode(buttonPin_2, INPUT);
  pinMode(buttonPin_3, INPUT);
  pinMode(led, INPUT);
  
  mySerial.begin(9600);  
  Serial.begin(9600);
  // Setup the LCD's number of coloumns and rows
  lcd.begin(20,4);
  lcd.setCursor( 3, 0);
  lcd.print("201 ENGR REGT");  
}

void loop()
{

  if(mySerial.available() > 1)
  {
    int input = mySerial.parseInt();
    // read serial input and convert to integer (-32,768 to 32,767)
    digitalWrite(led, HIGH);
    
    if(millis() - last > 250)
    {
      // if time now is 250 milliseconds greater than last time
      if(input > 1000 && input < 2000)
      {
        input = input -1000;

        // print on Serial moniter as Temp 
        Serial.print("Temperature = ");
        Serial.print(input); // display temperature value
        Serial.print("*C");
        Serial.println();

        lcd.setCursor(0,1);
        lcd.print("Temp of Veh = ");
        lcd.print(int(input));
        lcd.print("^C");  
        
        lcd.setCursor(0,2);   
        lcd.print("Eng Status = "); 
      }
      delay(20);      
    }
    mySerial.flush();//clear the serial buffer for unwanted inputs   
    last = millis();//reset timer        
  }
  delay(20);//delay little for better serial communication
  
}
