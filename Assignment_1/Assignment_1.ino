#include "kernel.h"
#include "sleep.h"
#include "buttons.h"
#include "config.h"

void setup() {
  // put your setup code here, to run once:
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
    break;
    case ROUND:
    break;
    case END:
    break;
  }
}
