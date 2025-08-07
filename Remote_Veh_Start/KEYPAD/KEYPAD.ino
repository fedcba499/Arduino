#include <Keypad.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

const byte numRows = 4;
const byte numCols = 4;

char keymap[numRows][numCols]= 
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','c'},
  {'*','0','#','D'},
};

byte rowPins[numRows] = {9,8,7,6};
// Rows 0 to 3

byte colPins[numCols] = {5,4,3,2};
// Cols 0 to 3

// initialize an instance of Keypad class

Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

const int rs = 12, en = 11, d4 = 7, d5 = 6, d6 = 5, d7 = 4;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

char password[4];

char keypressed=0;

int i=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Setup the LCD's number of coloumns and rows
  lcd.begin(20,4);
  lcd.setCursor( 3, 0);
  lcd.print("201 ENGR REGT");

}

// If key is pressed, this key is stores in 'keypressed' variable
// If key is not equal to 'NO_KEY', then this key is printed out
// If count = 17, then count is reset to 0 ( this means no key is pressed during the whole keypad scan process

void loop() {
  // put your main code here, to run repeatedly:
  keypressed = myKeypad.getKey();

  if(keypressed != NO_KEY)
  {
    Serial.print(keypressed);
  }
  if(key is presssed)
  {
      lcd.setCursor(0,1);
      lcd.print("Enter Password");
      lcd.setCursor(0,2);
      initialpassword();
  }

  if (keypressed)
  {
    password[i++]=keypressed;
    lcd.print(keypressed);
  }

  if(i==4)
  {

    delay(200);

    for(int j=0;j<4;j++)

    initial_password[j]=EEPROM.read(j);

    if(!(strncmp(password, initial_password,4)))

    {

      liquid_crystal_display.clear();

      liquid_crystal_display.print("Pass Accepted");

      digitalWrite(relay_pin, LOW);

      delay(2000);

      liquid_crystal_display.setCursor(0,1);

      delay(2000);

    }

    else

    {

      digitalWrite(relay_pin, HIGH);

      liquid_crystal_display.clear();

      liquid_crystal_display.print("Wrong Password");

      delay(2000);

    }

  }

  

}


void initialpassword(){

  for(int j=0;j<4;j++)

    EEPROM.write(j, j+49);

  for(int j=0;j<4;j++)

    initial_password[j]=EEPROM.read(j);

}
