#include <LiquidCrystal_I2C.h>
#include <string.h>
#include <Arduino.h>

#include "config.h"

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4);
int lcdWidth = 20;
int start = 0;
int end = 0;
size_t messageLenght = 0;
const char* messageShown;
bool scroll;
long lastChange;

/**
  Functions to change the message to be displayed on the LCD
*/
void changeMessage(const char* message, bool scrolling){
  lcd.init();
  lcd.backlight();
  messageShown = message;
  messageLenght = strlen(messageShown);
  start = 0;
  end = messageLenght<lcdWidth ? messageLenght : lcdWidth;
  lcd.print(message);
  lcd.noBlink();
  scroll = scrolling;
  lastChange = 0;
}
 
/**
  Function to update the screen every loop
*/
void updateScreen(){
  if((millis()- lastChange) > DELAY_SCREEN){
    Serial.println(String(end-start));
    lastChange = millis();;
    char sub[60];
    strncpy(sub, messageShown + start, end);
    sub[lcdWidth] = '\0';
    lcd.setCursor(0,0);
    lcd.print(String(sub));
    Serial.println(String(sub));
    if(scroll){
      end = (end + 1) % messageLenght;
      start = start +1;
      if(end < start){
        start = 0;
        end = messageLenght<lcdWidth ? messageLenght : lcdWidth;
      } 
    }
  }
}