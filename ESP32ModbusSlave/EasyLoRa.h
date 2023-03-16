// ===================================================
// For ESP32 + Modbus RS485
// Put all pin mappings and library here
// ===================================================
// Board type
#define BOARD_M5 1 // To comment if not using M5Stack board

#if defined(BOARD_M5)
   #include <M5Stack.h>
   // Docs: https://docs.m5stack.com/en/base/plc_m12
   // API: https://docs.makerfactory.io/m5stack/api/overview/
   // Specs: https://docs.m5stack.com/#/en/core/basic
#endif

// =====================
// Serial
// =====================
#define BAUD_RATE 9600

// ==============================
// Customization - Serial for Modbus
// ==============================
// Serial 1 but GPIO16 and 17
// https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/HardwareSerial.h
#include <HardwareSerial.h>
#define MODBUS_BAUDRATE 9600
#define MODBUS_RXD  16
#define MODBUS_TXD  17

// Serial to connect to RS485 module
HardwareSerial ModbusSerial(1);

// Modbus slave
#define MODBUS_SLAVEID 1

// Modbus library: https://github.com/sfera-labs/arduino-modbus-rtu-slave
#include <ModbusRtuSlave.h>
#define TXEN_PIN   23  // In use, to switch between TX and RX
