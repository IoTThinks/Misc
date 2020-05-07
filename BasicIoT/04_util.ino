// ====================================
// Chip ID
// ====================================
// To get chip ID, ESP32 will return mac address
void setChipID()
{
  // ========
  // Chip ID
  // ========
  // Get default mac address
  uint8_t chipid[6];
  esp_efuse_mac_get_default (chipid);

  // Format into uppercase mac address without :
  // Eg: BCDDC2C31684
  snprintf(SYS_ChipID, 15, "%02X%02X%02X%02X%02X%02X",chipid[0], chipid[1], chipid[2], 
            chipid[3], chipid[4], chipid[5]);
}

// Get random number from 0 to range
long getRandomNumber(int maxNum)
{
  randomSeed(millis() % 4095);
  return random(maxNum);  
}

// ====================================
// Converter
// ====================================
char* string2Char(String str){
    if(str.length()!=0){
        char *p = const_cast<char*>(str.c_str());
        return p;
    }
}

// Char to string
String char2String(char* ch)
{
  return String(ch);
}
