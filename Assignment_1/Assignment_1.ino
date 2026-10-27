#include "kernel.h"
#include "sleep.h"
#include "buttons.h"
#include "config.h"
#include "leds.h"
#include "lcd.h"
#include "core.h"


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
      fading();
      updateScreen();
      if(startingGame()){
        changeState(ROUND);
      }
      if(hasTimeElapsed(SLEEP_TIME)){
        sleep();
      }
    break;
    case ROUND:
      gamePhase();
    break;
    case END:
    break;
  }
}
