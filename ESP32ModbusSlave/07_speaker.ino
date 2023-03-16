// Speaker
// https://github.com/m5stack/M5Stack/blob/master/examples/Basics/Speaker/Speaker.ino
#define NOTE_DH2 661
void setupSpeaker() {
  #if defined(BOARD_M5)
  // beepSpeaker();
  M5.Speaker.setBeep(100, 100);
  #endif
}

void beepSpeaker() {
  #if defined(BOARD_M5)
  M5.Speaker.beep(); //beep
  // M5.Speaker.tone(NOTE_DH2, 100); //frequency 3000, with a duration of 100ms
  // M5.update();
  #endif
}
