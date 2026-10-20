#include "states.h"

/**
  Functions that initializes the time management system and state
*/
void initialize();

/**
  Function that returns the time elapsed from the accension of the device
*/
long getActualTime();

/**
  Function that returns the time elapsed since the last state change
*/
long getStateTime();

/**
  Function that returns the actual state
*/
State getState();

/**
  Function that changes the state
*/
void changeState(State newState);

/**
  Function to count the time in seconds
*/
void countSeconds();

/**

*/
void getSeconds();