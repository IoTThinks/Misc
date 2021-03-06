// ===================================================
// Put all pin mappings and library here
// ===================================================
// Serial
#define BAUD_RATE 115200 //9600

// LED
#define LED1 14       
#define LED2 13
#define LED3 19
#define LED4 21

// Button
#define BTN       34

// LoRa
#include <SPI.h>
#include <LoRa.h>

#define LORA_SS       23
#define LORA_SCK      18
#define LORA_MOSI      5
#define LORA_MISO     36
#define LORA_DIO012   39
#define LORA_RESET    25

#define LORA_SF 12 // 7 is the fastest. 12 is is farthest
#define LORA_CR 5
#define LORA_BW 41.7E3 //125E3
#define LORA_PREAMBLE_LENGTH  8

// Free PIN
#define FREE_PIN1    2
#define FREE_PIN2    4

// Modbus
// Serial 1 but GPIO16 and 17
#include "ModbusMaster.h"
#include <HardwareSerial.h>
#define MODBUS_RXD  16
#define MODBUS_TXD  17

// For Temperature
#define MODBUS_TEMP_REGISTERID 0x00
#define MODBUS_TEMP_REGISTERWORD 1

// For Humid
#define MODBUS_HUMID_REGISTERID 0x01
#define MODBUS_HUMID_REGISTERWORD 1

// instantiate ModbusMaster object
ModbusMaster modbus;

// Serial to connect to RS485 module
HardwareSerial ModbusSerial(1);

// Slave ID 1 for Modbus device
#define Slave_ID 1

// WiFi
#include <WiFi.h>
const char* ssid     = "Easy LoRa";
const char* password = "Password";

// OTA
#include <ArduinoOTA.h>
