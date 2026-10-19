#include "config.h"
#include <iostream>
#include <cmath>

int redLeds[] = {LR1, LR2};
int greenLeds[] = {LG1, LG2};

int brightness[] = {255, 0};
int fadeAmount = 5;
/**
  Fading leds for the pre-game phase
*/
void fading(){
  for(int i = 0; i < NUM_PLAYERS, i++){
    pinMode(redLeds[i],brightness[i]);
    brightness[i] = brightness[i] + (pow(-1,i)*fadeAmount);
  }
  if(brigh1 == 255){
    fadeAmount = -fadeAmount;
  }
}

/**
  Turns on the green winning led
  @param winner The index of the winner (0 for the first player, ecc...)
*/
void roundWon(int winner){
  digitalWrite(greenLedsp[winner], HIGH);
  delay(2000);
  digitalWrite(greenLedsp[winner], LOW);
}

/**
  Turns off all the leds
*/
void off(){
  for(int i = 0; i < NUM_PLAYERS, i++){
    digitalWrite(redLeds[i], LOW);
    digitalWrite(greenLeds[i], LOW);
  }
}