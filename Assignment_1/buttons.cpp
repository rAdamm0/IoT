#include <EnableInterrupt.h>
#include <Arduino.h>

#include "buttons.h"
#include "states.h"
#include "player.h"
#include "config.h"
#include "timer.h"

Button *b1 = new Button{};
Button *b2 = new Button{};

int buttons[] = {BT1, BT2};
bool lastCycle;
int value = -1;

void disableButtons(){
  for(int i = 0; i < NUM_PLAYERS; i++){
    disableInterrupt(buttons[i]);
  }
}

void wakeUp(){}

void attachWakeUp(){
  disableButtons();
  for(int i = 0; i < NUM_PLAYERS; i++){
    enableInterrupt(buttons[i], wakeUp, CHANGE);
  }
}

void bt1StartGame(){
  b1->pressed = true;
}

void bt2StartGame(){
  b2->pressed = true;
}

void attachStartGame(){
  disableButtons();
  enableInterrupt(BT1, bt1StartGame, FALLING);
  enableInterrupt(BT2, bt2StartGame, FALLING);
}

void b1Game(){
  if(millis() - b1->lastPressed > BOUNCING){
    b1->lastPressed = millis();
    b1->counts = b1->counts + 1;
  }
}

void b2Game(){
  if(millis() - b2->lastPressed > BOUNCING){
    b2->lastPressed = millis();
    b2->counts = b2->counts + 1;
  }
}

void attachGame(){
  disableButtons();
  enableInterrupt(BT1, b1Game, FALLING);
  enableInterrupt(BT2, b2Game, FALLING);
}

void resetCounts(){
  noInterrupts();
  b1->counts = 0;
  b2->counts = 0;
  interrupts();
}

void processButtons(){
  State state = getState();
  switch(state){
    case INITIAL:{
      noInterrupts();
      bool pressed1 = b1->pressed;
      bool pressed2 = b2->pressed;
      interrupts();
      if(pressed1 && pressed2){
        /*TODO*/
        //Change State to Waiting
        startGame = true;
      } else if(lastCycle != (pressed1 || pressed2)){
        timerReset();
        lastCycle = pressed1 || pressed2;
      }
      break;
    }
    case WAITING:{
      noInterrupts();
      int count1 = b1->counts;
      int count2 = b2->counts;
      long lastpress1 = b1->lastPressed;
      long lastpress2 = b2->lastPressed;
      interrupts();
      switch(count1 + count2){
        case 0:return; break;
        case 1:
          resetCounts();
          if(count1==1){
            removeScore(0);
          } else {
            removeScore(1);
          }
          break;
        case 2:
          resetCounts();
          if(lastpress1 < lastpress2){
            removeScore(0);
          } else {
            removeScore(1);
          }
      }
      break;
    }
    case GAME:{
      noInterrupts();
      int countGame1 = b1->counts;
      int countGame2 = b2->counts;
      long lastpressGame1 = b1->lastPressed;
      long lastpressGame2 = b2->lastPressed;
      interrupts();
      if(value == -1) return;
      if(countGame1+countGame2 >= 1) {
        timerStop();
      }
      if(countGame1 > value && countGame2 > value){
        resetCounts();
        if(lastpressGame1 < lastpressGame2){
          removeScore(0);
          return;
        }else{
          removeScore(1);
          return;
        }
      }
      if(countGame1 > value) {
        resetCounts();
        removeScore(0);
      }
      if(countGame2 > value){
        resetCounts();
        removeScore(1);
      }
      b1->allowedCounts = countGame1;
      b2->allowedCounts = countGame2;
      break;
    }
  }
}

bool endRound(){
  /*TODO*/
  //Make sure this is called before changing the state from GAME
  processButtons();
  int points1 = b1->allowedCounts;
  int points2 = b2->allowedCounts;
  setPoints(0, b1->allowedCounts);
  setPoints(1, b2->allowedCounts);
  disableButtons();
  delete b1;
  delete b2;
  b1 = new Button{};
  b2 = new Button{};
  value = -1;
  return points1 == 0 && points2 == 0;
}

void setRoundValue(int inValue){
  value = inValue;
}