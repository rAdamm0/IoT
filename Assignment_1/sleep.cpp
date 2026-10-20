#include <TimerOne.h>
#include <avr/sleep.h>

volatile int seconds = 0;

/**
  Counts the seconds allowing the timer to keep track of more than the 8.83s allowed for TimerOne
*/
void countSeconds(){
  seconds++;
}

/**
  Initialize the system to go into a phase to sleep
*/
void initializeTimer(){
  seconds = 0;
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(countSeconds);

}

/**
  Sets the system into sleep mode
*/
void sleep(){
  
}

/**
  Function used to solely wake the system
*/
void wakeUp(){}

/**
  Checks if it's time to sleep, and sleeps if it is
  @param time seconds to check if have elapsed
*/
bool hasTimeElapsed(int time){
  int tempSeconds;
  noInterrupts();
  tempSeconds = seconds;
  interrupts();
  return tempSeconds >= time;
}

/**
  Functions to reset the timer in case of state change
*/
void timerStop(){
  Timer1.detachInterrupt();
}