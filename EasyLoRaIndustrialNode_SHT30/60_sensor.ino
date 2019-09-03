// ====================================
// COMMONDITY SENSOR
// ====================================
/*
SHT30 via I2C
VCC: Brown
GND: Black
DATA: Yellow - P1
CLK: Blue - P2

Reference: https://github.com/Sensirion/arduino-sht/blob/master/examples/multiple-sht-sensors/multiple-sht-sensors.ino
*/

#include <Wire.h>
#include "SHTSensor.h"
// Normal i2c address
SHTSensor sht(SHTSensor::SHT3X);

void setupSensor() {  
  Serial.println("[SENSOR] Setup sensor");
  Wire.begin(FREE_PIN1, FREE_PIN2);  // SDA, SCL
   
  if (sht.init()) {
      Serial.println("[SENSOR] Setup sensor OK");
  } else {
      Serial.println("[SENSOR] Setup sensor FAILED");
  }
  sht.setAccuracy(SHTSensor::SHT_ACCURACY_MEDIUM); // only supported by SHT3x  
}

String getSensor() {
  String returnValue ="";
  
  if (sht.readSample()) {
    returnValue = "cs_humid:" + (String)sht.getHumidity() + 
                       ", cs_temp:" + (String)sht.getTemperature();                       
  } else {
    returnValue = "cs_event:error";
  }
      
  Serial.println("[SENSOR] Sensor value=" + (String)returnValue);
  return returnValue;
}
