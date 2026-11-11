#include <Arduino.h>

#include "config.h"
#include "states.h"
#include "leds.h"
#include "timer.h"

int redLeds[] = {LR1, LR2};
int greenLeds[] = {LG1, LG2};

int brightness[] = {255, 0};
int fadeAmount = 1;

int winner = -1;
int loser = -1;

/**
  Fading leds for the pre-game phase
*/
void fading(){
  for(int i = 0; i < NUM_PLAYERS; i++){
    analogWrite(redLeds[i], brightness[i]);
    brightness[i] = brightness[i] + (pow(-1,i+1)*fadeAmount);
  }
  if(brightness[0] == 255 || brightness[0] == 0){
    fadeAmount = -fadeAmount;
  }
}

void onLoser(){
  digitalWrite(redLeds[loser], HIGH);
}

void onWinner(){
  digitalWrite(greenLeds[winner], HIGH);
}

void setLoser(int player){
  loser = player;
}

void setWinner(int player){
  winner = player;
}

void off(){
  for(int i = 0; i<NUM_PLAYERS;i++){
    digitalWrite(redLeds[i], LOW);
    digitalWrite(greenLeds[i], LOW);
  }
}

void processLeds(){
  State state = getState();
  switch(state){
    case INITIAL:
      fading();
      break;
    case SCORE_LOST:
        onLoser();
      break;
    case SHOW_SCORE:
        onWinner();
      break;
    default: 
      loser = -1;
      winner = -1;
      off(); 
      break;
  }
}
