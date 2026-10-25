#include "kernel.h"
#include "sleep.h"
#include "buttons.h"
#include "config.h"
#include "leds.h"
#include "lcd.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  initializeKernel();
}

void loop() {
  State state = getState();
  switch(state){
    case INITIAL:
      processButtonPresses();
      if(startingGame()){
        changeState(ROUND);
      }
      if(hasTimeElapsed(SLEEP_TIME)){
        sleep();
      }
      fading();
      updateScreen();
    break;
    case ROUND:
    break;
    case END:
    break;
  }
}
