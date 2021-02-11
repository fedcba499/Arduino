#include <Servo.h>

Servo myServo;

int servo_position = 0;

void setup() 
{
  Serial.begin(9600);
  myServo.attach (9);

}

void loop() 
{
  myServo.write(0); 
  // 0 full speed anti clockwise direction
  // 180 full speed in clockwise direction
  // 90 zero or stationary

  myServo.detach();
  // stops the serrvo

  
}
