## Why use Arduino IDE than PlatformIO?
Arduino IDE provides quick code development platform for arduino and esp32 boards. It creates single file with .ino extension, where as platformio creates several files which are not beginner freindly. platformIO takes time to create project, each and every time, whereas arduino ide creates project fast.

## Library in Arduino IDE
**Wire library** in Arduino IDE is used for communication with I2C ( Inter Integrated Circuit) like OLED Display, Sensors, EEPROM.

**fs.h** - to handle file system and read, write to sd card

**spi.h** - serial pheripheral interface protocol to interact with multiple serial monitor using master esp32 with all sensors like gps, touch etc.

## Tips & Tricks
- In C, C++ Variable ends with semicolon
- Using PROGMEM to store bitmap images in flash memory instead of ram, thus saving ram for cruicial processing tasks
