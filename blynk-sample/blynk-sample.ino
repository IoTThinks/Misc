#include "headers.h"

void setup()
{
  setupSerial();
  setupNetwork();
  setupMobile();
  setupSensor();
}

void loop()
{
  // To check status of all service
  syncAllServiceStatus();

  // To get values from sensors
  getSensorValues();
}

// To sync status of all services
void syncAllServiceStatus()
{
  // Sync service status
  CRONJOB_SYNC_REALTIME_CURRENT_MILLIS = millis();
  if (CRONJOB_SYNC_REALTIME_CURRENT_MILLIS - CRONJOB_SYNC_REALTIME_START_MILLIS >= CRONJOB_SYNC_REALTIME_PERIOD)
  {
    // To check status of 
    syncNetworkStatus();
    syncMobileStatus();
  }

  // Get sensor
  CRONJOB_POLLING_SENSOR_START_MILLIS = millis();
  if (CRONJOB_POLLING_SENSOR_CURRENT_MILLIS - CRONJOB_POLLING_SENSOR_START_MILLIS >= CRONJOB_POLLING_SENSOR_PERIOD)
  {
    // To get sensor values
    getSensorValues();
  }

  // Watchdog to reconnect services
  CRONJOB_WATCHDOG_START_MILLIS = millis();
  if (CRONJOB_WATCHDOG_SENSOR_CURRENT_MILLIS - CRONJOB_WATCHDOG_START_MILLIS >= CRONJOB_WATCHDOG_SENSOR_PERIOD)
  {
    // If reach error threshold, restart
    if(WATCHDOG_ERRORCOUNT >= WATCHDOG_ERRORMAX)
    {
      ESP.restart();
    }
    else
    {
        WATCHDOG_ERRORCOUNT ++; // Increase the error count
    }
    
    // Still below error threshold, to check for services
    if(!network_connected) // To reconnect networks
    {
      reconnectNetwork();
    }
    else if(!mobile_connected) // only check mobile if network is connected
    {
      reconnectMobile();
    }
    else
    {
      // Reset the counter if network and mobile is connected
      WATCHDOG_ERRORCOUNT = 0;
    }
  }
}
