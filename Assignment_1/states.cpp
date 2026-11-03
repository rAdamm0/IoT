#include <Arduino.h>
#include <avr/sleep.h>

#include"config.h"
#include "states.h"
#include "buttons.h"
#include "timer.h"
#include "lcd.h"
#include "player.h"
#include "leds.h"
#include "difficulty.h"

State state = -1;
int roundCount;
int factor;
volatile bool timeToSleep = false;
volatile bool game = false;
volatile bool backToWait = false;
volatile bool restartGame = false;
volatile bool endGameBool = false;
bool errorPress;
bool startGame;
bool endRoundBool;

void sleep(){
 Serial.flush();
 delay(1000);
 set_sleep_mode(SLEEP_MODE_PWR_DOWN);
 sleep_enable();
 sleep_mode();
 sleep_disable();
 restartGame = true;
}

State getState(){
  return state;
}

void changeState(State input){
  if(state != input){
    state = input;

    switch(state){
      case INITIAL:{
        attachStartGame();
        changeMessage(WELCOME, true);
        timerInitialize("Sleep Timer", &timeToSleep, 1000, 10);
        roundCount = 0;
        break;
      }
      case SLEEP:{
        timeToSleep = false;
        attachWakeUp();
        processLeds();
        lcdOff();
        /*TODO*/
        //Function to send the device to sleep
        sleep();
        break;
      }
      case WAITING:{
        attachGame();
        changeMessage(GO, false);
        timerInitialize("Pregame wait time", &game, random(1000, MAX_WAIT), 3);
        break;
      }
      case GAME:{
        /*TODO*/
        // call processButtons before calling the changeState to GAME
        startRound();
        /*TODO*/
        //make sure that before getting into the Waiting phase the difficulty is set
        timerInitialize("In game timer", &endRoundBool, (MAX_T1-roundCount*factor), 0);
        roundCount++;
        int val = random(1,4);
        setRoundValue(val);
        changeMessage(String(val), false);
        break;
      }
      case SCORE_LOST:{
        Serial.println("Someone made an error");
        disableButtons();
        changeMessage("Error made", false);
        timerInitialize("Someone lost a point timer", &backToWait, 1000, 2);
        break;
      }
      case SHOW_SCORE:{
        Serial.println("Entered show_score phase");
        roundCount = roundCount + 1;
        int* points = endPlayerRound();
        String string = "P1:"+String(points[0])+"......"+"P2:"+String(points[1]);
        changeMessage(string, false);
        timerInitialize("A round ended", &backToWait, 1000, 2);
        break;
      }
      case GAME_OVER:{
        Serial.println("Entered game over phase");
        int winner = endGame();
        String message;
        if(winner==-1){
          message = TIE;
        } else{
          String player =winner == 0 ? "P1" : "P2";
          message = WINNER + player;
        }
        changeMessage(message, true);
        timerInitialize("Restarting Game", &restartGame, 1000, 10);
        break;
      }
    }
  }
}

void checkStates(){
  if(timeToSleep){
    timeToSleep = false;
    changeState(SLEEP);
  }else if(startGame){
    startGame = false;
    factor = getDifficulty() * FACTOR;
    changeState(WAITING);
  }else if(backToWait){
    backToWait = false;
    changeState(WAITING);
  }else if(game){
    game = false;
    processButtons();
    changeState(GAME);
  }else if(errorPress){
    errorPress = false;
    changeState(SCORE_LOST);
  }else if(endRoundBool){
    endRoundBool = false;
    if(endRound()){
      changeState(GAME_OVER);
    }else{
      changeState(SHOW_SCORE);
    }
  }else if(restartGame){
    restartGame = false;
    changeState(INITIAL);
  }
}


