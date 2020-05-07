// ==========================
// PROCESSOR
// ==========================
bool proccessor_connected = false;

void setupProcessor()
{
  Serial.println("[PROC] Setup processor.");
}

// To publish gateway telemetry
// {"key1":"value1"}
// https://thingsboard.io/docs/reference/mqtt-api/#telemetry-upload-api
void publishDeviceTelemetry(const char* key, const char* value)
{
  char *outgoing = (char *) malloc (64);
  strcpy(outgoing, R"=====({")=====");
  strcat(outgoing, key);
  strcat(outgoing, R"=====(":")=====");
  strcat(outgoing, value);
  strcat(outgoing, R"=====("})=====");

  publishToMQTT(MQTT_API_DEVICE_TELEMETRY, outgoing);

  // Free memory
  yield();
  free(outgoing);
}
