#include <LiquidCrystal_I2C.h>
#include <string.h>
#include <Arduino.h>

#include "config.h"

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4);
int lcdWidth = 20;
int start = 0;
int end = 0;
size_t messageLength = 0;
const char* messageShown;
bool scroll;
long lastChange;

/**
  Functions to change the message to be displayed on the LCD
*/
void changeMessage(const char* message, bool scrolling){
  Serial.println("Changing message");
  lcd.init();
  lcd.backlight();
  lcd.clear();
  messageShown = WELCOME;
  messageLength = strlen(messageShown);
  start = 0;
  end = messageLength < lcdWidth ? messageLength : lcdWidth;
  lcd.noBlink();
  scroll = true;
  lastChange = 0;
}
 
/**
  Function to update the screen every loop
*/
void updateScreen(){
  unsigned long now = millis();
    if (now - lastChange < DELAY_SCREEN) {
        return;
    }
    lastChange = now;
    char sub[60];
    strncpy(sub, messageShown + start, end);
    sub[lcdWidth] = '\0';
    lcd.setCursor(0,0);
    lcd.print(String(sub));
    if(scroll){
      end = (end + 1) % messageLength;
      start = start +1;
      if(end < start){
        start = 0;
        end = messageLength<lcdWidth ? messageLength : lcdWidth;
      } 
    }
}

/**
  Turns off the screen
*/
void lcdOff(){
  lcd.noBacklight();
  lcd.clear();
  lcd.off();
}