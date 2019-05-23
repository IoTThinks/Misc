# Modbus Master for ESP32
* Sponsored by http://iotthinks.com/
* Join us at https://www.facebook.com/groups/iotthinks

## 1. Goals
* To do it YOURSELF
* To use available hardware ESP32 and TTL RS485 module
* To connect to RS485 Temperature Meter
* To use Arduino programming style

## 2. Hardware
### 2.1 ESP32 Dev board
![image](https://user-images.githubusercontent.com/29994971/58236140-6d960900-7d6c-11e9-932f-4aece644083d.png)

### 2.2 TTL RS485 board
Buy one at http://www.dientuachau.com/ttl-to-rs485-module-1

![image](https://user-images.githubusercontent.com/29994971/58235482-193e5980-7d6b-11e9-8d8d-83ddc1183a3b.png)

### 2.3 RS485 Temperature Meter
![image](https://user-images.githubusercontent.com/29994971/58235754-9ff33680-7d6b-11e9-841d-b725c81ccc00.png)

## 3. Connect everything together
* (ESP32) TXD2 - (TTL RS485) TX
* (ESP32) RXD2 - (TTL RS485) RX
* (TTL RS485) A - (Temperature Meter) A
* (TTL RS485) B - (Temperature Meter) B

## 4. Library
ModbusMaster at https://github.com/4-20ma/ModbusMaster

## 5. Sample result
![image](https://user-images.githubusercontent.com/29994971/58236530-47bd3400-7d6d-11e9-904d-096fe65bc33e.png)

## 6. Commercial product
* Get commercial product at http://iotthinks.com/easy-lora-industrial-node
![image](https://user-images.githubusercontent.com/29994971/58236758-c914c680-7d6d-11e9-82ea-e150abde410e.png)

