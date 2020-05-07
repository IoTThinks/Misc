// https://pubsubclient.knolleary.net/
// https://github.com/knolleary/pubsubclient
// =====================
// MQTT
// =====================
PubSubClient mqttClient;

void setupMQTT() {
  // Should be connected to internet
  mqttClient.setClient(mqttNetClient);
  mqttClient.setServer(MQTT_SERVER, MQTT_PORT);

  // MQTT listener
  // Not need in this tutorial
  // mqttClient.setCallback(mqttMessageReceived);

  // Connect to MQTT
  while (connectToMQTT() != true) 
  {
    delay(500);
    Serial.println("Connecting to MQTT..");
  }
  Serial.println("Connected to MQTT..");
}

bool connectToMQTT() {
  // Client id, username, password
  // NULL for not using password
  return mqttClient.connect(SYS_ChipID, MQTT_USERNAME, NULL);
}

// ====================
// Basic commands
// ====================
// Public status of MQTT
bool isMQTTConnected()
{
  return mqttClient.connected();
}

void publishToMQTT(const char* topic, const char* message) 
{
  Serial.print("[MQTT] <= Send to MQTT: ");
  Serial.println(message);
 
  // Publish a message
  mqttClient.publish(topic, message, MQTT_RETAINED);
}

// Read the MQTT receive and send buffers and process any messages it finds.
void syncMQTT() 
{  
  mqttClient.loop(); // Sends and receives packets
  yield(); 
}
