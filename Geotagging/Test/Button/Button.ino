const int inputPin = D3;  // Pin to read from

void setup() {
  Serial.begin(115200);
  pinMode(inputPin, INPUT_PULLUP);  // Or INPUT_PULLUP if using button to GND
}

void loop() {
  int signal = digitalRead(inputPin);

  if (signal == HIGH) {
    Serial.println("Pin D3: HIGH");
  } else {
    Serial.println("Pin D3: LOW");
  }

  delay(500); // Slow down the prints
}
