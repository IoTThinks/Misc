# WiFiClientBasicTest
This is to test if an ESP32 board has wifi issue.

## 1. Steps:
* Change WIFI_NAME and WIFI_PASSWORD of the sketch.
* The WiFi Access point should have DHCP.
* Upload the sketch to ESP32 board.
* Baud rate of the serial in the sketch is 9600.


## 2. Pass case
* Able to get IP
* Able to ping IP of the board.
![image](https://user-images.githubusercontent.com/29994971/60953844-223db700-a328-11e9-8c6a-3a93d73a332c.png)


## 3. Failed cases
* For ESP32-WROOM, hit "brownout detector" issue and keep restarting the board
![image](https://user-images.githubusercontent.com/29994971/60953970-60d37180-a328-11e9-9c90-76c69e584f40.png)

* For ESP32-Pico-D4
![image](https://user-images.githubusercontent.com/29994971/97771900-3b4d2580-1b74-11eb-92cb-d948eb140deb.png)

## 4. Suggested fix and references
* Seems to be capacitor issue. "I have now strapped a 220uF cap across 3.3v and Gnd" https://www.esp32.com/viewtopic.php?t=2784
* Power issue. https://github.com/nkolban/esp32-snippets/issues/168
