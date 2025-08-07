// Define pins for the HC-SR04
const int trigPin = A3;
const int echoPin = A4;

// Define the pins for the LEDs
const int ledPin = 13; // Built-in LED
const int ledPin2 = A6; // Connect to Detonator

// Define a distance threshold in centimeters
const int distanceThreshold = 50;

void setup() {
  // Initialize the Serial Monitor
  Serial.begin(9600);

  // Initialize the pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // Set the initial state of ledPin2 to HIGH
  digitalWrite(ledPin2, HIGH);

  // Initial delay of 2 minutes (120,000 ms)
  Serial.println("System warming up... Please wait 2 minutes.");
  delay(120000); // 2 minutes delay
  Serial.println("System active. Starting measurements...");
}

void loop() {
  // Send a 10-microsecond pulse to the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echo pin and calculate the distance
  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2; // Convert to centimeters

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Blink the first LED if the distance is below the threshold
  if (distance > 1 && distance < distanceThreshold) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin2, LOW);
    delay(3000);
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, HIGH);
    delay(500);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin2, HIGH);
  }

  // Small delay before the next measurement
  delay(100);
}