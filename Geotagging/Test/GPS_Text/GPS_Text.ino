#include <TinyGPS++.h>
#include <HardwareSerial.h>

TinyGPSPlus gps;
HardwareSerial GPS(1);  // UART1

void setup() {
  Serial.begin(115200);                  // Serial Monitor
  GPS.begin(38400, SERIAL_8N1, 20, -1);  // GPS on GPIO20 (D10), TX only

  Serial.println("📡 Waiting for GPS fix...");
}

void loop() {
  while (GPS.available()) {
    char c = GPS.read();
    gps.encode(c);  // Feed character to GPS parser

    if (gps.location.isUpdated()) {
      Serial.println("------ GPS FIX ------");
      Serial.print("Latitude: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("Longitude: ");
      Serial.println(gps.location.lng(), 6);

      Serial.print("Date: ");
      Serial.print(gps.date.day());
      Serial.print("/");
      Serial.print(gps.date.month());
      Serial.print("/");
      Serial.println(gps.date.year());

      Serial.print("Time (UTC): ");
      Serial.print(gps.time.hour());
      Serial.print(":");
      Serial.print(gps.time.minute());
      Serial.print(":");
      Serial.println(gps.time.second());

      Serial.print("Satellites: ");
      Serial.println(gps.satellites.value());

      Serial.print("HDOP: ");
      Serial.println(gps.hdop.hdop());

      Serial.println("---------------------\n");
    }
  }
}
