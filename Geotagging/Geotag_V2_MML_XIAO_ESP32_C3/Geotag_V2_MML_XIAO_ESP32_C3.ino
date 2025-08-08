#include <TinyGPS++.h>
#include <HardwareSerial.h>
#include <SPI.h>
#include <SD.h>

// --- Pin Definitions ---
#define SCK   D8
#define MISO  D9
#define MOSI  D10
#define CS    D5
#define BUTTON_PIN D3

// --- GPS and Serial ---
TinyGPSPlus gps;
HardwareSerial GPS(1);  // UART1 for GPS

// --- File ---
File logFile;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Booting...");

  // Button input with internal pull-up
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Start GPS on UART1 - RX on GPIO20 (D7), TX not used
  GPS.begin(38400, SERIAL_8N1, 20, -1);

  // Setup SPI for SD card
  SPI.begin(SCK, MISO, MOSI, CS);
  if (!SD.begin(CS)) {
    Serial.println("SD card mount failed!");
    while (true);  // Stop here
  }

  Serial.println("SD card initialized.");
  if (!SD.exists("/gps_log.csv")) {
    logFile = SD.open("/gps_log.csv", FILE_WRITE);
    if (logFile) {
      logFile.println("Date,Time,Latitude,Longitude,Altitude(m),Satellites");
      logFile.close();
      Serial.println("CSV header written.");
    }
  }
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);

  while (GPS.available()) {
    char c = GPS.read();
    gps.encode(c);

    if (gps.location.isUpdated()) {
      // Build date and time strings
      char dateStr[11];
      char timeStr[9];
      sprintf(dateStr, "%02d/%02d/%04d", gps.date.day(), gps.date.month(), gps.date.year());
      sprintf(timeStr, "%02d:%02d:%02d", gps.time.hour(), gps.time.minute(), gps.time.second());

      double lat = gps.location.lat();
      double lng = gps.location.lng();
      double alt = gps.altitude.meters();
      int sats = gps.satellites.value();

      Serial.printf("%s %s - Lat: %.6f, Lon: %.6f, Alt: %.2f m, Sats: %d\n",
                    dateStr, timeStr, lat, lng, alt, sats);

      // Log only if button is pressed (button is active LOW)
      if (buttonState == LOW) {
        logFile = SD.open("/gps_log.csv", FILE_APPEND);
        if (logFile) {
          logFile.printf("%s,%s,%.6f,%.6f,%.2f,%d\n",
                         dateStr, timeStr, lat, lng, alt, sats);
          logFile.close();
          Serial.println("Logged to SD.");
        } else {
          Serial.println("Could not open file to log!");
        }
      } else {
        Serial.println("Button not pressed — not logging.");
      }

      delay(1000);  // Log/print every second
    }
  }
}
