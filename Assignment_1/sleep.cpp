#include <TimerOne.h>
#include <avr/sleep.h>
#include <EnableInterrupt.h>

volatile int seconds = 0;

/**
  Counts the seconds allowing the timer to keep track of more than the 8.83s allowed for TimerOne
*/
void countSeconds(){
  seconds++;
  if(seconds == 10 ){
    interrupts();
    sleep();
  }
}

/**
  Initialize the system to go into a phase to sleep
*/
void initializeSleep(){
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(countSeconds);

}

/**
  Sets the system into sleep mode
*/
void sleep();

/**
  Function used to solely wake the system
*/
void wakeUp(){}

/**
  Checks if it's time to sleep, and sleeps if it is
*/
void timeToSleep(){
  int tempSeconds;
  noInterrupts();
  tempSeconds = seconds;
  interrupts();
  if(tempSeconds == 10){
    sleep();
  }
}

/**
  Functions to reset the timer in case of state change
*/
void sleepTimerStop(){
  Timer1.detachInterrupt();
}