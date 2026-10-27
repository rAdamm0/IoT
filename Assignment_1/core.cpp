#include "kernel.h"
#include "config.h"

#include <Arduino.h>

/**
  Code to run during the startPhase
*/
void startPhase(){
  int randomWait = random(MAX_WAIT);
}

/**
  Code to run for the game phase
*/
void gamePhase(){

}

/**
  Code to run for the end phase
*/
void endPhase(){
  changeState(END);
}

/**
  Returns true if the number is being shown, false otherwise
*/
bool isNumberShown(){
  
}