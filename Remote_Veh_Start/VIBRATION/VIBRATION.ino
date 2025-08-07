int vib_pin=7;
int led_pin=13;

void setup() {
  pinMode(vib_pin,INPUT);
  pinMode(led_pin,OUTPUT);
}

void loop() {
  int val;
  val=digitalRead(vib_pin);
  if(val==1)
  {
    digitalWrite(led_pin,HIGH);
    delay(20);

   }
   else
   digitalWrite(led_pin,LOW);
}
