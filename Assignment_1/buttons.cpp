#include "config.h"
#include "sleep.h"
#include "player.h"

#include <EnableInterrupt.h>
#include <Arduino.h>

int buttons[] = {BT1, BT2};
volatile bool buttonPressed[2] = {false, false};
int startGameCounters[] = {0, 0};
volatile unsigned long lastPressed[] = {0,0};

void detachInterrupts(){
  for(int i = 0; i < NUM_PLAYERS; i++){
    disableInterrupt(buttons[i]);
  }
}

/**
  Attaches to the buttons the function to wake up the system after it goes to sleep
*/
void attachWakeUp(){
  detachInterrupts();
  for (int i = 0; i < NUM_PLAYERS; i++){
      pinMode(buttons[i], INPUT_PULLUP);
      enableInterrupt(buttons[i], wakeUp, FALLING);
  }
  memset(startGameCounters, 0, sizeof(startGameCounters));
  
  
}

void button1ISR() {
  buttonPressed[0] = true;
}

void button2ISR() {
  buttonPressed[1] = true;
}

/**
  Attachest to the buttons the function to start the game, changing its state.
*/
void attachGameStart(){
  detachInterrupts();
  for (int i = 0; i < NUM_PLAYERS; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
  enableInterrupt(buttons[0], button1ISR, FALLING);
  enableInterrupt(buttons[1], button2ISR, FALLING);
}

void processButtonPresses() {
  noInterrupts();
  bool pressed1 = buttonPressed[0];
  bool pressed2 = buttonPressed[1];
  buttonPressed[0] = false;
  buttonPressed[1] = false;
  interrupts();
  if (pressed1 && startGameCounters[0] == 0) {
    startGameCounters[0] = 1;
    initializeTimer();
  }
  if (pressed2 && startGameCounters[1] == 0) {
    startGameCounters[1] = 1;
    initializeTimer();
  }
}

bool startingGame(){
  int sum = 0;
    for(int i = 0; i < NUM_PLAYERS; i++) {
        sum += startGameCounters[i];
    }
    return sum == NUM_PLAYERS;
}

/**
  Returns 1 if the buttons is pressed (or has been in a certain interval), 0 otherwise.
*/
bool isButtonPressed(int numButton){
  return (millis() - lastPressed[numButton]) < BOUNCING_TIME;
}

/**
  Counter function that determines if a button press is to be counted and do so if needed.
  One function for each player.
*/
void pressCountP1(){
    if(!isButtonPressed(0)){
        lastPressed[0] = millis();
        addCount(0);
    }
}

void pressCountP2(){
    if(!isButtonPressed(1)){
        lastPressed[1] = millis();
        addCount(1);
    }
}

/**
  Attaches to the buttons the function to count the button presses.
*/
void attachCounter(){
  detachInterrupts();
  for (int i = 0; i < NUM_PLAYERS; i++){
    pinMode(buttons[i], INPUT_PULLUP);
  }
  enableInterrupt(buttons[0], pressCountP1, FALLING);
  enableInterrupt(buttons[1], pressCountP2, FALLING);
  memset(lastPressed, 0, sizeof(lastPressed));
}

/**
  Function that starts the game changing the State of the system
*/
void startGame();