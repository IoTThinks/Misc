// Load libraries
#include "BluetoothSerial.h"

// Check if Bluetooth configs are enabled
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Bluetooth Serial object
BluetoothSerial SerialBT;

// GPIO where LED is connected to
const int ledPin =  14; // Led  1

// Handle received and sent messages
String message = "";
char incomingChar;

// Timer: auxiliar variables
unsigned long previousMillis = 0;    // Stores last time temperature was published
const long interval = 2000;         // interval at which to publish sensor readings

void setup() {
  pinMode(ledPin, OUTPUT);  
  Serial.begin(115200);
  // Bluetooth device name
  SerialBT.begin("EasyLoRaNode");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

int count=0;
void loop() {
   unsigned long currentMillis = millis();
   if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    SerialBT.println("LoRa message " + String (++count)); 
   }

  // Read received messages (LED control command)
  if (SerialBT.available()){
    char incomingChar = SerialBT.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
    }
    else{
      message = "";
    }
    Serial.write(incomingChar);  
  }
  
  // Check received message and control output accordingly
  if (message =="led_on"){
    digitalWrite(ledPin, HIGH);
  }
  else if (message =="led_off"){
    digitalWrite(ledPin, LOW);
  }
  delay(20);
}
