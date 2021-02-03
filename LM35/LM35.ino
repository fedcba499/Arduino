float temp;
int tempPin = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  temp = analogRead(tempPin);
  // read analog volt from sensor and save to variable temp

  temp = temp * 0.48828125;
  //convert the analog volt to its temperature equivalent

  Serial.print("Temperature = ");
  Serial.print(temp); // display temperature value
  Serial.print("*C");
  Serial.println();
  delay(1000); //update sensor reading after every second

}
