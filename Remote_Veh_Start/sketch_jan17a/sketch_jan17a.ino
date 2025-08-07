int relayPin = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin , OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relayPin , HIGH ); // off Light
  delay(30000);
  digitalWrite(relayPin , LOW ); // on light
  delay(60000);

}
