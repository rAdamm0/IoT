#include "states.h"

long enterStateTime;
long bootTime;
State state;

/**
  Functions that initializes the time management system and state
*/
void initialize(){
  state = INITIAL;
  enterStateTime = millis();
  bootTime = millis();
}

/**
  Function that returns the time elapsed from the accension of the device
*/
long getActualTime(){
  return millis() - bootTime;
}

/**
  Function that returns the time elapsed since the last state change
*/
long getStateTime(){
  return millis() - enterStateTime;
}

/**
  Function that returns the actual state
*/
State getState(){
  return state;
}

/**
  Function that changes the state
*/
void changeState(State newState){
  if(newState != state){
    state = newState
  }
}