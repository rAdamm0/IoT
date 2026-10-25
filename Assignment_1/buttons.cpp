#include "config.h"
#include "sleep.h"
#include "player.h"

#include <EnableInterrupt.h>
#include <Arduino.h>

int buttons[] = {B1, B2};
int startGameCounters[] = {0, 0};
unsigned long lastPressed[] = {0,0};

/**
  Attaches to the buttons the function to wake up the system after it goes to sleep
*/
void attachWakeUp(){
  for (int i = 0; i < NUM_PLAYERS; i++){
      pinMode(buttons[i], INPUT_PULLUP);
      enableInterrupt(buttons[i], wakeUp, FALLING);
    }
}

void startGameCounter(){
  if(digitalRead(buttons[0]) == HIGH && startGameCounters[0] == 0){
    startGameCounters[0] = 1;
  } else if(digitalRead(buttons[1]) == HIGH && startGameCounters[1] == 0){
    startGameCounters[1] = 1;
  }
}
/**
  Attachest to the buttons the function to start the game, changing its state.
*/
void attachGameStart(){
  for (int i = 0; i < NUM_PLAYERS; i++){
    pinMode(buttons[i], INPUT_PULLUP);
    //enableInterrupt(buttons[i], startGameCounter, RISING);
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
void pressCounts(){
  for(int i = 0; i < NUM_PLAYERS; i++){
    if(digitalRead(buttons[i]) == HIGH && !isButtonPressed(i)){
        lastPressed[i] = millis();
        addCount(i);
    }
  }
}

/**
  Attaches to the buttons the function to count the button presses.
*/
void attachCounter(){
  for (int i = 0; i < NUM_PLAYERS; i++){
    pinMode(buttons[i], INPUT_PULLUP);
    enableInterrupt(buttons[i], pressCounts, FALLING);
  }
  memset(lastPressed, 0, sizeof(lastPressed));
}

/**
  Function that starts the game changing the State of the system
*/
void startGame();