# Easy LoRa Industrial Node - RS485 SHT20
Easy LoRa Industrial Node captures temperature and humidity from RS485 SHT20 sensor and send to LoRa gateway. LoRa gateway formards the information to server. The server converts data and display them.
* Homepage: http://iotthinks.com/easy-lora-industrial-node/
* Full WiKi: https://github.com/IoTThinks/EasyLoRaNode_Industrial/wiki

![image](https://user-images.githubusercontent.com/29994971/74079393-68e3c300-4a69-11ea-8f1b-abe004e8444e.png)

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
### 3.1 Reading temperature and humid from RS485 Sensor and sending to LoRa gateway
![image](https://user-images.githubusercontent.com/29994971/74079364-f96dd380-4a68-11ea-995a-a8d30d9ce594.png)

### 3.2 LoRa gateway to receive sensor data from LoRa node and send to ThingsBoard Server
![image](https://user-images.githubusercontent.com/29994971/74079426-ed364600-4a69-11ea-806f-8befef32d48d.png)

### 3.3 ThingsBoard server to convert data 
![image](https://user-images.githubusercontent.com/29994971/74079445-38e8ef80-4a6a-11ea-8b63-4ed7da6c828f.png)

### 3.4 ThingsBoard server to display data
![image](https://user-images.githubusercontent.com/29994971/74079461-67ff6100-4a6a-11ea-9bc8-b7e3aaa280d1.png)
