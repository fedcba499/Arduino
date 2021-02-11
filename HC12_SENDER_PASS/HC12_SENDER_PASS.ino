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
    char vibration[4] = "OFF";
    Serial.print("1234");
    
    if(millis() - last > 250)
    {
      // if time now is 250 milliseconds greater than last time
      if(input > 1000 && input < 2000)
      {
        input = input -1000;
        if (input > 100)
        {
          input = input - 100;
          vibration[4] = "ONN";
        }

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
        lcd.print(vibration[4]);  
      }
      delay(20);      
    }
    mySerial.flush();//clear the serial buffer for unwanted inputs   
    last = millis();//reset timer        
  }
  delay(20);//delay little for better serial communication
  
  int buttonState_1 = digitalRead(buttonPin_1);
  int buttonState_2 = digitalRead(buttonPin_2);
  int buttonState_3 = digitalRead(buttonPin_3);

  boolean ledState = digitalRead(led); // check if the LED is turned on or off

    lcd.setCursor( 0, 1);
    lcd.print("Enter Password");
    char keypressed = myKeypad.getKey();
    
    if(keypressed)
    {
      if(i==0)
      {
        lcd.setCursor(0,2);
        lcd.print("      "); 
      }
      password[i++] = keypressed;
      lcd.setCursor( k,2 );
      lcd.print(keypressed);
      k++;
    } 

    Serial.print(keypressed);
    if(i==4)
    {
      if(!(strncmp(password, masterPassword,4)))
      {
        lcd.setCursor(0,3);
        lcd.print("Pass Accepted");
        i = 0;
        k = 0; 
        Serial.print("pass");
        //if button is down
        j = 1;        
        //send unique code to the receiver in this case 1111  
      }
      else
      {
        lcd.setCursor(0,3);
        lcd.print("Wrong,  Retry");      
        i = 0;
        k = 0;   
      }
    }
    delay(20);
    digitalWrite(led, HIGH);
    if (j == 1 && buttonState_1 == 1)
    {
      Serial.print("Pass");
      mySerial.println(1111);
      delay(1000);
    }
    else if (j ==1 && buttonState_2 == 1)
    {
      Serial.print("2nd Pass");
      mySerial.println(2222);
      delay(1000);
    }
  
  delay(20);

}
