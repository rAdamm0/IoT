

/**
  Initialize the system to go into a phase to sleep
*/
void initializeSleep();

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
bool timeToSleep();

/**
  Functions to reset the timer in case of state change
*/
void sleepTimerStop();