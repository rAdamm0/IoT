#ifndef ___SLEEP___
#define ___SLEEP___

/**
  Initialize the system to go into a phase to sleep
*/
void initializeTimer();

/**
  Sets the system into sleep mode
*/
void sleep();

/**
  Function used to solely wake the system
*/
void wakeUp();

/**
  Returns true if its time for the system to go to sleep, false otherwise
*/
bool hasTimeElapsed(int time);

/**
  Functions to reset the timer in case of state change
*/
void timerStop();
#endif