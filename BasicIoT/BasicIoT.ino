// Include required EasyLoraGateway libraries
#include "EasyLoRa.h"

// ===================================================
// Main Program
// ===================================================
// This runs once when the gateway boots. 
void setup() {  
  setupSerial();  
  setChipID();
  setupWiFi();
  setupMQTT();
  setupProcessor();
}

// Do the real works here
void loop() {  
  // MQTT
  runCronjob_syncingServices();
  yield();

  // Sensor
  runCronJob_pollingSensors();
  yield();
}

// Task 1: Syncing common services
void runCronjob_syncingServices()
{  
  CRONJOB_SYNC_SERVICE_CURRENT_MILLIS = millis();
  if (CRONJOB_SYNC_SERVICE_CURRENT_MILLIS - CRONJOB_SYNC_SERVICE_START_MILLIS >= 
      CRONJOB_SYNC_SERVICE_PERIOD)
  {    
    // Send and receive commands from Portal
    syncMQTT();
  
    // Reset timer
    CRONJOB_SYNC_SERVICE_START_MILLIS = CRONJOB_SYNC_SERVICE_CURRENT_MILLIS;
  }
}

// Task 2: Polling sensors
void runCronJob_pollingSensors()
{    
  CRONJOB_POLLINGSENSOR_CURRENT_MILLIS = millis();
 
  if (CRONJOB_POLLINGSENSOR_CURRENT_MILLIS - CRONJOB_POLLINGSENSOR_START_MILLIS >= 
      CRONJOB_SYNC_POLLINGSENSOR_PERIOD)
  {
    // Get sensor value
    String sensorValue = getSensorValue();

    // Upload to ThingsBoard
    publishDeviceTelemetry("temp", string2Char(sensorValue));
    
    // Reset timer
    CRONJOB_POLLINGSENSOR_START_MILLIS = CRONJOB_POLLINGSENSOR_CURRENT_MILLIS;
  }
}
