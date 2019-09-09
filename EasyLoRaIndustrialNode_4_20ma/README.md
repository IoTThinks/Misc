# Easy LoRa Industrial Node for 4-20ma

## 1. Converter
### 1.1 Module 4-20ma to RS485 converter
Hardware information: 
* https://www.aliexpress.com/item/32736594725.html
* https://www.lazada.vn/products/0-20ma-4-20ma-analog-input-module-rs485-modbus-rtu-communications-wp3082adam-8ai-i304434332-s486888341.html

![image](https://user-images.githubusercontent.com/29994971/64505016-90890080-d2fc-11e9-83a0-dcb3bcd4e04e.png)

![image](https://user-images.githubusercontent.com/29994971/64504498-12c3f580-d2fa-11e9-97cc-9775da124da0.png)

#### Send and receive from RS485
![image](https://user-images.githubusercontent.com/29994971/64511877-6725a000-d30f-11e9-8700-bedf2763ae49.png)
The recieved command means the data of the first analog input is “09CE”,and it is equal to 2510 in decimal,then substitute into the fomula: I=(DATA*20)/4095=(2510*20)/4095≈12.26mA.The current in the other channel is 0mA

### 1.2 Module Current to voltage converter
Hardware information: http://www.dientuachau.com/current-to-voltage-module-0-4-20ma-to-0-3-3v5v
![image](https://user-images.githubusercontent.com/29994971/64226457-ad42c400-cf09-11e9-8199-b91d53c3b105.png)

![image](https://user-images.githubusercontent.com/29994971/64226509-d9f6db80-cf09-11e9-8279-5d1831e3a89e.png)

![image](https://user-images.githubusercontent.com/29994971/64226563-19252c80-cf0a-11e9-9c66-d68068f57ac2.png)




