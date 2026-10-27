#include "config.h"

#include <Arduino.h>

/**
  Returns the gameDifficulty based on the Potentiometer rotation
*/
int getDifficulty(){
  int potValue = analogRead(POT);
  int difficulty = map(potValue, 0, 1023, 1, 4);
  Serial.print("Difficulty is ");
  Serial.println(difficulty);
  Serial.print("The pot value is ");
  Serial.println(potValue);
  return difficulty;
}