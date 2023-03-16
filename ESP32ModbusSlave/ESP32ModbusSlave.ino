#include "EasyLoRa.h"

void setup() {
  // Serial
  setupSerial();

  // For M5
  // Lcd display
  setupDisplayLCD();
  turnOnLCD();
  
  // Speaker
  setupSpeaker();
  beepSpeaker();

  // Hello
  printlnUtil("MODBUS SLAVE SIMULATOR");
  
  // Modbus
  setupModbusSlave();
}

void loop() {
  #if defined(BOARD_M5)
    // To check for event and timeout
    M5.update();
  #endif
  
  runModbusSlave();
}

void printUtil(String text) {
  Serial.print(text);
  printLCD(text);
}

void printlnUtil(String text) {
  Serial.println(text);
  printlnLCD(text);
}
