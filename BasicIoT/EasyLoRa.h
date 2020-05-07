// ===================================================
// Put all pin mappings and library here
// ===================================================
// =====================
// System
// =====================
char SYS_ChipID[15];

// =====================
// Serial
// =====================
#define BAUD_RATE 115200

// =====================
// WiFi
// =====================
#include <WiFi.h>
char WIFI_SSID[32]     = "Easy LoRa"; // CHANGE HERE TO YOUR WIFI NAME
char WIFI_PASSWORD[32] = "EasyLoRa123"; // CHANGE HERE TO YOUR WIFI PASSWORD

// =====================
// MQTT - ThingsBoard
// =====================
#include <PubSubClient.h>

// Used as Internet connection for MQTT
WiFiClient mqttNetClient;
#define MQTT_BUFFER_SIZE 256 // Default is 128
#define MQTT_QOS 1
#define MQTT_RETAINED true

char MQTT_SERVER[32] = "easylora.vn"; // Parameter
int MQTT_PORT = 1883; // Parameter

// Node Basic IoT in demo account
char MQTT_USERNAME[32] = "yxqFqCaIxMoR0RB4clda"; // CHANGE HERE TO DEVICE AUTHENTICATION CODE
char MQTT_SECRET[32] = "This is not needed"; // Any non-empty code is valid for ThingsBoard MQTT // Parameter

// =============
// For device
// =============
// Publish device telemetry
#define MQTT_API_DEVICE_TELEMETRY "v1/devices/me/telemetry"

// =====================
// Cron jobs
// =====================
// Syncing services
unsigned long CRONJOB_SYNC_SERVICE_START_MILLIS = millis();
unsigned long CRONJOB_SYNC_SERVICE_CURRENT_MILLIS;
const unsigned long CRONJOB_SYNC_SERVICE_PERIOD = 1000; // miliseconds

// Polling sensors
unsigned long CRONJOB_POLLINGSENSOR_START_MILLIS = millis();
unsigned long CRONJOB_POLLINGSENSOR_CURRENT_MILLIS;
// Parameter bane: POLLING_PERIOD
long CRONJOB_SYNC_POLLINGSENSOR_PERIOD = 4500; // miliseconds 
