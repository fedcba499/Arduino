#include <HardwareSerial.h>

HardwareSerial GPS(1);  // Use UART1

void setup() {
  Serial.begin(115200);                  // USB Serial Monitor
  GPS.begin(38400, SERIAL_8N1, 20, -1);  // RX = GPIO20, TX = not used (-1)

  Serial.println("✅ Listening for GPS NMEA data on GPIO20 @ 38400 baud...");
}

void loop() {
  while (GPS.available()) {
    char c = GPS.read();
    Serial.write(c);  // Forward GPS data to Serial Monitor
  }
}
