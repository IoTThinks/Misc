# Instruction
Sponsored by http://iotthinks.com

## Goals
* To use available hardware ESP32 and TTL RS485 module
* To connect to RS485 Temperature Meter

## Hardware
### ESP32 Dev board
![image](https://user-images.githubusercontent.com/29994971/58235355-db413580-7d6a-11e9-85f2-02f91db1f091.png)

### TTL RS485 board
Buy one at http://www.dientuachau.com/ttl-to-rs485-module-1

![image](https://user-images.githubusercontent.com/29994971/58235482-193e5980-7d6b-11e9-8d8d-83ddc1183a3b.png)

### RS485 Temperature Meter
![image](https://user-images.githubusercontent.com/29994971/58235754-9ff33680-7d6b-11e9-841d-b725c81ccc00.png)

## Connect everything together
* (ESP32) TXD2 - (TTL RS485) TX
* (ESP32) RXD2 - (TTL RS485) RX
* (TTL RS485) A - (Temperature Meter) A
* (TTL RS485) B - (Temperature Meter) B

## Library
ModbusMaster at https://github.com/4-20ma/ModbusMaster

## Questions?
Join us at https://www.facebook.com/groups/iotthinks
