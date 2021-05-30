void setupMobile()
{
  // Set configuration
  Blynk.config(mobileNetClient, MOB_AUTH);

  // Reconnect mobile
  reconnectMobile();
}

void reconnectMobile()
{
  // Stop first
  mobileNetClient.stop();
  // Blynk.disconnect(); // Unneccessary as Blynk.connect() will call Blynk.disconnect()
  mobile_connected = false; // To stop syncMobile()
  
  if(mobileNetClient.connect(BLYNK_DEFAULT_DOMAIN, BLYNK_DEFAULT_PORT))
  {    
    mobileNetClient.setNoDelay(true); // Enable TCP_NODELAY
  }
  else
  {
    Serial.println("[MOB] Connecting to Mobile FAILED.");
  }  

  // Try to connect to Blynk with timeout 2000ms
  Serial.println("[MOB] Connecting to mobile...");
  Blynk.connect(2000);
}

void syncMobileStatus()
{
  Blynk.run();
  mobile_connected = Blynk.connected();
}

BLYNK_CONNECTED() 
{
  // Set flag
  // This is the most reliable way to set mobile_connected to true
  mobile_connected = true;

  Serial.println("[MOB] Mobile is connected");
  
  // Send notification to mobile app
  Blynk.notify("Mobile app is online");
}
