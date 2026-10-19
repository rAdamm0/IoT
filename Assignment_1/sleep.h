

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
  Functions to start the sleep timer in the initial phase
*/
void sleepTimerStart();

/**
  Functions to reset the timer in case of state change
*/
void sleepTimerStop();