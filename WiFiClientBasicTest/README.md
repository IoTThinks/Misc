# WiFiClientBasicTest
This is to test if an ESP32 board has wifi issue.

## Steps:
* Change WIFI_NAME and WIFI_PASSWORD of the sketch.
* The WiFi Access point should have DHCP.
* Upload the sketch to ESP32 board.


## Pass case
* Able to get IP
* Able to ping IP of the board.
![image](https://user-images.githubusercontent.com/29994971/60953844-223db700-a328-11e9-8c6a-3a93d73a332c.png)


## Failed case
* Hit "brownout detector" issue and keep restarting the board
![image](https://user-images.githubusercontent.com/29994971/60953970-60d37180-a328-11e9-9c90-76c69e584f40.png)
