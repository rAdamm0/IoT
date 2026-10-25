#include "config.h"

#include <Arduino.h>

int redLeds[] = {LR1, LR2};
int greenLeds[] = {LG1, LG2};

int brightness[] = {255, 0};
int fadeAmount = 1;

bool initiated = false;
/**
  Fading leds for the pre-game phase
*/
void fading(){
  if(!initiated){
    for(int i = 0; i < NUM_PLAYERS; i++){
      pinMode(redLeds[i],OUTPUT);
    }
    initiated = true;
  }
  for(int i = 0; i < NUM_PLAYERS; i++){
    analogWrite(redLeds[i], brightness[i]);
    brightness[i] = brightness[i] + (pow(-1,i+1)*fadeAmount);
  }
  if(brightness[0] == 255 || brightness[0] == 0){
    fadeAmount = -fadeAmount;
  }
}

/**
  Turns on the green winning led
  @param winner The index of the winner (0 for the first player, ecc...)
*/
void roundWon(int winner){
  digitalWrite(greenLeds[winner], HIGH);
  delay(2000);
  digitalWrite(greenLeds[winner], LOW);
}

/**
  Turns off all the leds
*/
void off(){
  for(int i = 0; i < NUM_PLAYERS; i++){
    digitalWrite(redLeds[i], LOW);
    digitalWrite(greenLeds[i], LOW);
  }
}