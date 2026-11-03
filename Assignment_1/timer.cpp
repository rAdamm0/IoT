#include <Arduino.h>
#include <TimerOne.h>

#include "timer.h"

#define MAX_MESSAGE_LEN 80

volatile bool* temp = nullptr;
volatile int count = 0;
int counter = 0;
int actualCount;
String description = "Error: No Timer Set - This description should not be visible";

void functionISR(){
  if (temp == nullptr) {
        return;
    }
    count++;
    if (count >= counter) {
        *temp = true;
        Timer1.stop();
    }
}

void timerInitialize(String inDescription, bool* boolVal, unsigned long timerValue, unsigned long inCount){
  Serial.println("Inizializing new timer: " + inDescription);
  Timer1.detachInterrupt();
  Timer1.stop();
  noInterrupts();
  temp = boolVal;
  count = 0;
  counter = inCount;
  if (temp != nullptr) {
      *temp = false;
  }
  interrupts();
  description = inDescription;
  Timer1.initialize(timerValue*1000);
  Timer1.attachInterrupt(functionISR);
}

void timerStop(){
  counter = 0;
}

void timerReset(){
  noInterrupts();
  count = 0;
  interrupts();
}