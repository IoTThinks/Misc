#include "EasyLoRaIndustrialNode.h"

void setup() {  
  setupSerial();
  setupLED();  
  //setupWiFi();
  delay(1000);
  setupLoRa();
  //setupSensor();  
  setupModbus();
  
  // Blink all leds
  blinkAllLEDs();
}

void loop() { 
  // Blink LED 1 for another loop
  onLED1();
  delay(500);
  offLED1();
  delay(500);

  // Send message from commodity sensor
  //String cs_data=getSensor();  
  //delay(1000);

  // Send message from modbus sensor
  String mb_data = getModbusSensor();
  delay(2000);

  // Send json-like data to gateway
  //sendLoRaMessage(cs_data + "," + mb_data);
  //sendLoRaMessage(cs_data);
  
  //String loraMsg = receiveLoRaMessage();
  //Serial.println("Received LoRa Message: " + loraMsg);
}
