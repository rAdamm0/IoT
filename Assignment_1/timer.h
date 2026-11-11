#ifndef __TIMER__
#define __TIMER__

/**
  Initializes the timer.
  Prints the description of the previous timer if it did not end.
  @param description String that describes what is the purpose of the timer
  @param boolVal Pointer to the value to change value of 
  @param timerValue Value for Timer1 to initialize
  @param count How many times Timer1 must call the ISR to change the value 
*/
void timerInitialize(String inDescription, bool* boolVal, unsigned long timerValue, unsigned long inCount);

/**
  Stops the timer. (It doesnt stop the Timer1 ISR calls)
*/
void timerStop();

/**
  Resets the counter value, resetting the timer
*/
void timerReset();

#endif