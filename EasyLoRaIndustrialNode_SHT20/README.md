# Easy LoRa Industrial Node - RS485 SHT20
Easy LoRa Industrial Node captures electric meter from RS485 electric meter and send to LoRa gateway. LoRa gateway formard the information to MQTT server.
* Homepage: http://iotthinks.com/easy-lora-industrial-node/
* Full WiKi: https://github.com/IoTThinks/EasyLoRaNode_Industrial/wiki

![image](https://user-images.githubusercontent.com/29994971/74079271-8021b100-4a67-11ea-83f8-0a546501f1f8.png)

## 1. Setup
* Easy LoRa Gateway: http://iotthinks.com/easy-lora-gateway/
* Easy LoRa Industrial Node: http://iotthinks.com/easy-lora-industrial-node/
* RS485 SHT20: https://htpro.vn/Nhiet-do-do-am/cam-bien-sht-nhiet-do-do-am-giao-tiep-rs485-modbus.html


## 2. Modbus Configuration
## 2.1 Modbus parameters in data sheet
* Serial: 9600-8-1-N
* Default slave id 1. In this project, the slave id is 32
* Temperature: Input Register id=0x0001, Word=1
* Humid: Input Register id=0x0002, Word=1

## 2.2 Modbus parameters in program
![image](https://user-images.githubusercontent.com/29994971/74079326-3a191d00-4a68-11ea-8f00-42a5d7d49164.png)

## 3. In action
### 3.1 Reading temperature from LoRa node
![image](https://user-images.githubusercontent.com/29994971/59153655-9d8e1d80-8a89-11e9-8f16-54df20a09c68.png)

### 3.2 Reading voltage
![image](https://user-images.githubusercontent.com/29994971/59153656-a67eef00-8a89-11e9-83a4-7685ca73fb09.png)

### 3.3 Reading from electrict meter
![image](https://user-images.githubusercontent.com/29994971/59153657-af6fc080-8a89-11e9-862c-2d864111f55f.png)
