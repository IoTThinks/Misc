/*
 *  This sketch is to test wifi connection
 */

#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti WiFiMulti;
#define WIFI_NAME "EasyLoRa"
#define WIFI_PWD "Password"

void WiFiEvent(WiFiEvent_t event)
{  
  switch(event) {
    case SYSTEM_EVENT_STA_GOT_IP:
      Serial.print("[WiFi] WiFi connected. ");
      Serial.print("IP address: ");
      Serial.println(WiFi.localIP());
      break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
      Serial.println("[WiFi] WiFi lost connection.  Attempting to reconnect...");
      WiFi.reconnect();
      break;
    case SYSTEM_EVENT_STA_START:
      Serial.println("[WiFi] WiFi station start");
      break;
    case SYSTEM_EVENT_STA_CONNECTED:
      Serial.println("[WiFi] WiFi station connected to AP");
      break;
    case SYSTEM_EVENT_AP_START:
      Serial.println("[WiFi] WiFi AP start");
      break;
    default:      
      Serial.printf("[WiFi] Unhandled WiFi Event %d\n", event);       
      break;
  }
}

void setupWiFi()
{
    // delete old config
    WiFi.disconnect(true);
    delay(1000);

    WiFi.onEvent(WiFiEvent);

    WiFi.begin(WIFI_NAME, WIFI_PWD);
    Serial.println("[WiFi] Wait for WiFi...");
}

void setup()
{
    // Setup Serial
    Serial.begin(9600);
    delay(10);

    // Setup WiFi
    setupWiFi();
}


void loop()
{
  // Do nothing
}

