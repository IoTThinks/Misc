static bool wifi_connected = false;
String WiFi_Ip;

void setupWiFi()
{
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  WiFi.setSleep(false); // Do not sleep

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to WiFi..");
}

void stopWiFi()
{
  Serial.println("[WiFi] Wifi is disabled.");
  WiFi.mode(WIFI_OFF);
}

void reconnectWiFi()
{
  WiFi.reconnect();
}
