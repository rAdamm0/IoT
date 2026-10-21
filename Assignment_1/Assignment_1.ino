#include "kernel.h"
#include "sleep.h"
#include "buttons.h"
#include "config.h"
#include "leds.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  initializeKernel();
}

void loop() {
  // put your main code here, to run repeatedly:
  State state = getState();
  switch(state){
    case INITIAL:
    if(startingGame()){
      changeState(ROUND);
    }
    if(hasTimeElapsed(SLEEP_TIME)){
      sleep();
    }
    fading();
    break;
    case ROUND:
    break;
    case END:
    break;
  }
}
