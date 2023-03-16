// Simulated word value
// 0x1234 => 16 bit
bool myCoil = false;

// https://www.arduino.cc/reference/en/language/variables/data-types/word/
// A word can store an unsigned number of at least 16 bits (from 0 to 65535).
// 1 word = 1 register = 2 bytes
word registerValue1 = 0x1234;
  
void setupModbusSlave() {
  // Modbus settings
  Serial.println("[MODBUS_SLAVE] Setup Modbus");

  // To set hardware serial
  Serial.println("[MODBUS_SLAVE] Set ModbusSerial");
  ModbusSerial.begin(MODBUS_BAUDRATE, SERIAL_8N1, MODBUS_RXD, MODBUS_TXD);

  // To set Modbus Slave
  Serial.println("[MODBUS_SLAVE] Set mbSlave");
  ModbusRtuSlave.setCallback(&onRequest);
  ModbusRtuSlave.begin(MODBUS_SLAVEID, &ModbusSerial, MODBUS_BAUDRATE, TXEN_PIN);
}

void runModbusSlave() {
  ModbusRtuSlave.process();
}

// slaveId is hardcoded by MODBUS_SLAVEID in EasyLoRa.h
byte onRequest(byte slaveId, byte function, word regAddr, word numOfWords, byte *data) {
  // ================================
  // Print MB request information
  beepSpeaker();
  clearLCD();
  printlnUtil("[Request received]");
  printlnUtil("SlaveId: 0x" + String(slaveId, HEX));
  printlnUtil("Function: 0x" + String(function, HEX));
  printlnUtil("RegAddr: 0x" + String(regAddr, HEX));
  printlnUtil("#Words: " + String(numOfWords));
  // printlnUtil("Data: " + String(data)); // For write operation, to convert to String

  // ================================
  // To create Modbus response
  return sendResponse(slaveId, function, regAddr, numOfWords, data);
}

byte sendResponse(byte slaveId, byte function, word regAddr, word numOfWords, byte *data) {
    // To create Modbus response
  switch (function) {
    // =====================================
    // FREQUENTLY USED - HOLDING REGISTERS
    // =====================================
    case MB_FC_READ_HOLDING_REGISTERS:      
      // Return register address as dummy register value
      printlnUtil("[Response sent (HEX)]");
      printUtil(String(slaveId, HEX) + " " + String(numOfWords*2, HEX) + " ");
      for(int i=0; i<numOfWords; i++){
        ModbusRtuSlave.responseAddRegister(regAddr+i);
        printUtil(String(regAddr+i, HEX) + " ");
      }

      // CRC
      printlnUtil("xx xx");
      return MB_RESP_OK;          
      
      // If not in list, return error
      // printlnUtil("Illegal data address!");
      // return MB_EX_ILLEGAL_DATA_ADDRESS;
    // =====================================
    case MB_FC_READ_COILS:
      /*
      // TODO: To rewrite when there is a need.
      if (regAddr == 1 && numOfWords == 1) {
        ModbusRtuSlave.responseAddBit(myCoil);
        return MB_RESP_OK;
      }
      */
      return MB_EX_ILLEGAL_DATA_ADDRESS;

    case MB_FC_WRITE_SINGLE_COIL:
      /*
      // TODO: To rewrite when there is a need.
      if (regAddr == 1) {
        myCoil = ModbusRtuSlave.getDataCoil(function, data, 0);
        return MB_RESP_OK;
      }
      */
      return MB_EX_ILLEGAL_DATA_ADDRESS;

    case MB_FC_WRITE_SINGLE_REGISTER:
      /*
      // TODO: To rewrite when there is a need.
      if (regAddr == 101) {
        word value = ModbusRtuSlave.getDataRegister(function, data, 0);
        if (value < 0 || value > 10000) {
          return MB_EX_ILLEGAL_DATA_VALUE;
        }
        registerValue1 = value;
        return MB_RESP_OK;
      }
      */
      return MB_EX_ILLEGAL_DATA_ADDRESS;

    default:
      return MB_EX_ILLEGAL_FUNCTION;
  }
}
