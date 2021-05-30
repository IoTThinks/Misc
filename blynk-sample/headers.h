// Declaration for libraries and variables
bool network_connected = false;
bool mobile_connected = false;

// =====================
// Serial
// =====================
#define BAUD_RATE 115200 //9600

// ========================================
// BLYNK
// ========================================
// https://github.com/blynkkk/blynk-library/blob/master/src/Blynk/BlynkConfig.h
#include <BlynkSimpleStream.h>
#define BLYNK_PRINT Serial
#define BLYNK_DEBUG

// Auth Token in the Blynk App.
char MOB_AUTH[64] = "======== TO CHANGE THIS =======";

// To check Blynk via http
#include <HTTPClient.h>
WiFiClient mobileNetClient;

// ========================================
// Syncing realtime for realtime service
// ========================================
unsigned long CRONJOB_SYNC_REALTIME_START_MILLIS = millis();
unsigned long CRONJOB_SYNC_REALTIME_CURRENT_MILLIS;
// It takes around 5 seconds for mobile to reconnect. Do not re-run too fast
const unsigned long CRONJOB_SYNC_REALTIME_PERIOD = 900; // miliseconds

// ========================================
// Polling a sensor
// ========================================
unsigned long CRONJOB_POLLING_SENSOR_START_MILLIS = millis();
unsigned long CRONJOB_POLLING_SENSOR_CURRENT_MILLIS;
long CRONJOB_POLLING_SENSOR_PERIOD = 2100; // miliseconds to poll a sensor, 2100ms

// ========================================
// Watchdog to reconnect services
// ========================================
unsigned long CRONJOB_WATCHDOG_START_MILLIS = millis();
unsigned long CRONJOB_WATCHDOG_SENSOR_CURRENT_MILLIS;
long CRONJOB_WATCHDOG_SENSOR_PERIOD = 30100; // miliseconds to poll a sensor, 30100ms
int WATCHDOG_ERRORCOUNT = 0;
const int WATCHDOG_ERRORMAX = 10; // Max count before reboot
