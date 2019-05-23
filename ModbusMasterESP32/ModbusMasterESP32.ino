#include "ModbusMaster.h"
#include <HardwareSerial.h>

// Slave ID 1 for Modbus device
#define Slave_ID 1

// instantiate ModbusMaster object
ModbusMaster modbus;

// Serial to connect to RS485 module
HardwareSerial ModbusSerial(1);

// Pin to connect to RS485 module
#define RXD2 16 //RXX2 pin
#define TXD2 17 //TX2 pin

void setup() 
{ 
  // Serial for debugging
  Serial.begin(9600, SERIAL_8N1);
  Serial.println("Start setup");

  // Modbus communication runs at 9600 baud
  ModbusSerial.begin(9600, SERIAL_8N1, RXD2, TXD2);
  
  // Modbus slave ID 1
  modbus.begin(Slave_ID, ModbusSerial);  
  modbus.idle(yield);

  Serial.println("Done setup");
}

long lastMillis = 0;
void loop() 
{
  long currentMillis = millis();
  // Polling Modbus device every 5 seconds
  if (currentMillis - lastMillis > 5000) 
  {    
    // Getting result from register 0x2010 with 1 word only
    uint8_t result = modbus.readHoldingRegisters(0x2010, 1);
    if (getResultMsg(&modbus, result)) 
    {
      Serial.println();
      double res_dbl = modbus.getResponseBuffer(0) / 10.0;
      String res = "Temperature2: " + String(res_dbl) + " C\r\n";
      //res_dbl = modbus1.getResponseBuffer(1) / 10;
      //res += "Humidity2: " + String(res_dbl) + " %";
      Serial.println(res);
    }
    
    lastMillis = currentMillis;
  }
}

// Get Modbus message
bool getResultMsg(ModbusMaster *node, uint8_t result) 
{ 
  String tmpstr2 = "\r\n";
  switch (result) 
  {
  case node->ku8MBSuccess:
    return true;
    break;
  case node->ku8MBIllegalFunction:
    tmpstr2 += "Illegal Function";
    break;
  case node->ku8MBIllegalDataAddress:
    tmpstr2 += "Illegal Data Address";
    break;
  case node->ku8MBIllegalDataValue:
    tmpstr2 += "Illegal Data Value";
    break;
  case node->ku8MBSlaveDeviceFailure:
    tmpstr2 += "Slave Device Failure";
    break;
  case node->ku8MBInvalidSlaveID:
    tmpstr2 += "Invalid Slave ID";
    break;
  case node->ku8MBInvalidFunction:
    tmpstr2 += "Invalid Function";
    break;
  case node->ku8MBResponseTimedOut:
    tmpstr2 += "Response Timed Out";
    break;
  case node->ku8MBInvalidCRC:
    tmpstr2 += "Invalid CRC";
    break;
  default:
    tmpstr2 += "Unknown error: " + String(result);
    break;
  }

  // Print Modbus returned message
  Serial.println(tmpstr2);
  return false;
}
