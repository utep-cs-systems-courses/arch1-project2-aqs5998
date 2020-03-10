#include <msp430.h>
#include "stateMachines.h"
#include <stddef.h>
#include "buzzer.h"
#include "libTimer.h"
#include <stdio.h>
#include <stdlib.h>

char state = 0;
extern char stateSong = 0;

//Plays Darude Sandstorm
void playSong(){
  int notes[] = {506,506,506,0,506,506,0,506,0,506,506,0,379,0,379,379,0,379, 425,0,425,425,0,425,0,562,0, 506,506,0,506,506,0,506,0,506,0,379,379,506,506,0,506,0,506,506,0, 379,379, 506,506,0,506,0,506,506,0,379,0,379,379,0,379,0,425,0,425,425,0,425,425,0,568,568,0, 506,506,0,506,506,0,506,0,506,506,0,506,506,0,379,379,0,506,506,0,506,506,0,506,0,506,506,0,506,0,379,379,0,506,0,506,0,506,0,506,0,506,0,506,0,506,506,0,506,506,0,379,0,379,379,0,379,379,0,425,0,425,425,0,425,425,0,568,568,0,506,0,506,0,506,0,506,0,506,0,506,506,0,506,506,0,506,506,0,379,379,0,506,0,506,0,506,0,506,0,506,0,379,0,506,506,506,0,506,506,506,506,506,0};//,379,0,379,0,379,0,379,0,425,425,425,0,568,568,0,506,506,0,379,379,0,506,506,506,0,379,0,506,506};
  buzzer_set_period(notes[stateSong]);
  stateSong++;	 
}

void playSongSwitch() {
  //buzzer_set_period(1000);
  //int notes[] = {1000, 0, 810, 740, 0, 810, 830, 845, 840, 845, 0, 0, 0, 790, 770, 0, 2000};
  // for(int i = 0; notes[i]!=790;i++){
  // buzzer_set_period(notes[i]);
  // }

  static char state = 0;
  switch(state){
  case 0:
    state = 1;
    buzzer_set_period(523);//C
    break;
  case 1:
    state = 2;
    buzzer_set_period(523);//C
    break;
  case 2:
    state = 3;
    buzzer_set_period(500);//D
    break;
  case 3:
    state = 4;
    buzzer_set_period(450);//E
    break;
  case 4:
    state = 5;
    buzzer_set_period(450);//E
    break;
  case 5:
    state = 6;
    buzzer_set_period(500);//D
    break;
  case 6:
    state = 7;
    buzzer_set_period(523);//C
    break;
  case 7:
    state = 8;
    buzzer_set_period(600);//B
    break;
  case 8:
    state = 9;
    buzzer_set_period(650);//A
    break;
  case 9:
    state = 10;
    buzzer_set_period(650);//A
    break;
  case 10:
    state = 11;
    buzzer_set_period(600);//B
    break;
  case 11:
    state = 12;
    buzzer_set_period(523);//c
    break;
  case 12:
    state = 13;
    buzzer_set_period(600);//B
    break;
  case 13:
    state = 14;
    buzzer_set_period(600);
    break;
  case 14:
    state = 15;
    buzzer_set_period(0);
    break;
  }
}
