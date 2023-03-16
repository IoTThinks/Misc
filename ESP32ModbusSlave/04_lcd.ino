// Display LCD screen
// https://github.com/m5stack/m5-docs/blob/master/docs/en/api/lcd.md
void setupDisplayLCD() {
  #if defined(BOARD_M5)
  // Do nothing
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(2);
  #endif
}

void turnOffLCD() {
  #if defined(BOARD_M5)
  M5.Lcd.setBrightness(0);
  M5.Lcd.sleep();
  #endif
}

void turnOnLCD(){
  #if defined(BOARD_M5)
  M5.Lcd.begin();
  M5.Lcd.wakeup();
  M5.Lcd.setBrightness(50);
  #endif
}

void clearLCD() {
  #if defined(BOARD_M5)
  M5.Lcd.setCursor(0, 10);
  M5.Lcd.clear(BLACK);
  #endif  
}
void printLCD(String text){  
  #if defined(BOARD_M5)
  M5.Lcd.print(text);
  #endif
}

void printlnLCD(String text){  
  #if defined(BOARD_M5)
  M5.Lcd.println(text);
  #endif
}

void displayFullLCD(String text1, String text2, String text3, String text4, 
  String text5, String text6, String text7){
  #if defined(BOARD_M5)
  // LCD display
  // M5.Lcd.fillScreen(BLACK);
  // M5.Lcd.setTextColor(WHITE);
  // M5.Lcd.setTextSize(3);
  M5.Lcd.clear(BLACK);

  if(text1 != "")
  {
    M5.Lcd.setCursor(0, 10);
    M5.Lcd.println(text1);
  }

  if(text2 != "")
  {
    M5.Lcd.setCursor(0, 40);
    M5.Lcd.println(text2);
  }

  if(text3 != "")
  {
    M5.Lcd.setCursor(0, 70);
    M5.Lcd.println(text3);
  }

  if(text4 != "")
  {
    M5.Lcd.setCursor(0, 100);
    M5.Lcd.println(text4);
  }

  if(text5 != "")
  {
    M5.Lcd.setCursor(0, 130);  
    M5.Lcd.println(text5);
  }

  if(text6 != "")
  {
    M5.Lcd.setCursor(0, 160);
    M5.Lcd.println(text6);
  }

  if(text7 != "")
  {
    M5.Lcd.setCursor(0, 190);
    M5.Lcd.println(text7);
  }
  #endif
}
