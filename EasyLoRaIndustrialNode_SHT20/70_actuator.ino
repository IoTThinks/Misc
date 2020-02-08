void setupActuator() {
  log("[ACTUATOR] Setup Actuator");
  
  // Pin P1
  digitalWrite(FREE_PIN1, LOW);
  pinMode(FREE_PIN1, OUTPUT);  
  
  // Pin P2
  digitalWrite(FREE_PIN2, LOW);
  pinMode(FREE_PIN2, OUTPUT);  

  // Restore saved state for P1
  String savedActuatorStateP1 = getPreference("PREFS_P1_STATE");
  if(savedActuatorStateP1 == "true")
  {
    log("[ACTUATOR] Restored actuator P1 to ON.");
    onActuatorP1();
  }
  else
  {
    // State is false or not saved
    log("[ACTUATOR] Saved actuator P1 to OFF. Do nothing.");
  }
  
  // Restore saved state for P2
  String savedActuatorStateP2 = getPreference("PREFS_P2_STATE");
  if(savedActuatorStateP2 == "true")
  {
    log("[ACTUATOR] Restored actuator P2 to ON.");
    onActuatorP2();
  }
  else
  {
    // State is false or not saved
    log("[ACTUATOR] Saved actuator P2 to OFF. Do nothing.");
  }
}

void onActuatorP1(){
  // Save to FLASH
  setPreference("PREFS_P1_STATE", "true");

  // On LED 1
  onLED1();
  
  // Already ON, to skip
  if(digitalRead(FREE_PIN1) == HIGH)
    return;
    
  log("[ACTUATOR] On actuator P1");
  digitalWrite(FREE_PIN1, HIGH);  
}

void offActuatorP1(){
  // Save to FLASH
  setPreference("PREFS_P1_STATE", "false");

  // Off LED 1
  offLED1();
  
  // Already ON, to skip
  if(digitalRead(FREE_PIN1) == LOW)
    return;
    
  log("[ACTUATOR] Off actuator P1");
  digitalWrite(FREE_PIN1, LOW);
}

void onActuatorP2(){
  // Save to FLASH
  setPreference("PREFS_P2_STATE", "true");

  // On LED 2
  onLED2();
  
  // Already ON, to skip
  if(digitalRead(FREE_PIN2) == HIGH)
    return;
    
  log("[ACTUATOR] On actuator P2");
  digitalWrite(FREE_PIN2, HIGH);
}

void offActuatorP2(){
  // Save to FLASH
  setPreference("PREFS_P2_STATE", "false");

  // Off LED 2
  offLED2();
  
  // Already ON, to skip
  if(digitalRead(FREE_PIN2) == LOW)
    return;
    
  log("[ACTUATOR] Off actuator P2");
  digitalWrite(FREE_PIN2, LOW);
}
