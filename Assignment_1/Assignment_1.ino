#include "config.h"
#include "states.h"
#include "leds.h"
#include "buttons.h"
#include "lcd.h"

long scoreLostStart;

void setPinModes(){
  // Setting all the pinModes
  pinMode(LR1,OUTPUT);
  pinMode(LR2,OUTPUT);
  pinMode(LG1,OUTPUT);
  pinMode(LG2,OUTPUT);
  pinMode(BT1,INPUT_PULLUP);
  pinMode(BT2,INPUT_PULLUP);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setPinModes();
  changeState(INITIAL);
}

void loop() {
  processLeds();
  updateScreen();
  processButtons();
  checkStates();
}
