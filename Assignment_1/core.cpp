#include "kernel.h"
#include "config.h"
#include "buttons.h"
#include "difficulty.h"
#include "player.h"
#include "lcd.h"

#include <Arduino.h>

int difficulty;
int randomWait;
int gameWait;
int factor;
long stateEntrance;
int rounds;
long roundStart;
bool numberShown;

bool isEndTime(){
  return millis()-roundStart > gameWait;
}

/**
  Returns true if the number is being shown, false otherwise
*/
bool isNumberShown(){
  return numberShown;
}

void initializeCore(){
  difficulty = getDifficulty();
  if(difficulty > 4){
    Serial.print("Difficulty cannot be ");
    Serial.println(difficulty);
    difficulty = 4;
  }
  factor = FACTOR * difficulty;
  rounds = 0;
  attachCounter();
}


/**
  Code to run during the startPhase
*/
void startPhase(){
  startRound();
  randomWait = random((MAX_WAIT));
  stateEntrance = millis();
  numberShown = false;
  gameWait = MAX_T1 - (rounds * factor);
  Serial.print("GameWait is ");
  Serial.println(gameWait);
  while(millis()-stateEntrance < randomWait){}
  changeMessage(String(random(3)).c_str(), false);
  numberShown = true;
  roundStart = millis();
}

/**
  Code to run for the end phase
*/
void endPhase(){
  rounds++;
  int winner = endRound();
  Serial.print(winner);
  Serial.println(" Won the round");
  delay(20000);
  startPhase();
}

/**
  Code to run for the game phase
*/
void gamePhase(){
  Serial.println(millis());
  if(isEndTime()){
    countRoundCheck();
    endPhase();
  }
}



