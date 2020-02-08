#include "EasyLoRa.h"

void setup() {  
  setupSerial();  
  //setupWiFi();
  setChipID();
  setNetworkID();
  setupSerialBT();
  setupPreference();
  setupLED();  
  //setupButton();  
      
  setupLoRa();
  // setupSensor();  
  setupModbus();
  setupActuator();
  //setupOTA();
}

void loop() { 
  // Check heap mem
  // logHeap();

  // Received LoRa message is processed in callback

  // Not in use
  // buttonPressed();
  // waitingForOTA();

  runCronJob_pollingNodes();
  
  // Delay a bit for watch dog
  vTaskDelay(1);
}

// ====================================
// Cron job - Update sensor
// ====================================
void runCronJob_pollingNodes()
{    
  CRONJOB_POLLING_NODE_CURRENT_MILLIS = millis();
 
  if ((CRONJOB_POLLING_NODE_CURRENT_MILLIS - CRONJOB_POLLING_NODE_START_MILLIS) >= POLLING_PERIOD)
  {    
    updateInternalSensorData();        
    
    // Reset timer
    CRONJOB_POLLING_NODE_START_MILLIS = CRONJOB_POLLING_NODE_CURRENT_MILLIS;
  }
}
