#include <msp430.h>
#include "stateMachines.h"
#include <stddef.h>
#include "buzzer.h"
#include "./timerLib/libTimer.h"
#include <stdio.h>
#include <stdlib.h>
#include "led.h"

char state = 0;
extern char stateSong = 0;

//Plays Darude Sandstorm
void playSong(){
  int notes[] = {506,506,506,0,506,506,0,506,0,506,506,0,379,0,379,379,0,379, 425,0,425,425,0,425,0,562,0, 506,506,0,506,506,0,506,0,506,0,379,379,506,506,0,506,0,506,506,0, 379,379, 506,506,0,506,0,506,506,0,379,0,379,379,0,379,0,425,0,425,425,0,425,425,0,568,568,0, 506,506,0,506,506,0,506,0,506,506,0,506,506,0,379,379,0,506,506,0,506,506,0,506,0,506,506,0,506,0,379,379,0,506,0,506,0,506,0,506,0,506,0,506,0,506,506,0,506,506,0,379,0,379,379,0,379,379,0,425,0,425,425,0,425,425,0,568,568,0,506,0,506,0,506,0,506,0,506,0,506,506,0,506,506,0,506,506,0,379,379,0,506,0,506,0,506,0,506,0,506,0,379,0,506,506,506,0,506,506,506,506,506,0};//,379,0,379,0,379,0,379,0,425,425,425,0,568,568,0,506,506,0,379,379,0,506,506,506,0,379,0,506,506};
  buzzer_set_period(notes[stateSong]);
  stateSong++;	 
}


char toggle_red()		/* always toggle! */
{
  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;			/* always changes an led */
}

char toggle_green()	/* only toggle green if red is on!  */
{
  char changed = 0;
  if(green_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
  if (red_on) {
   green_on ^= 1;
    changed = 1;
  }
  return changed;
}

char toggle_both(){
  char changed = 0;
  if(state == 1) {
    green_on ^= 1;
    red_on ^= 1;
    changed = 1;
    state = 0;
  }
  else if(!green_on && state == '0'){
    green_on ^=0;
    red_on ^=0;
    changed = 0;
    state = 1;
  }
  return changed;
}


void state_advance()		/* alternate between toggling red & green */
{
  char changed = 0;  
  
  static enum {R=0, G=1} color = G;
  switch (color) {
    case R: changed = toggle_red(); color = G; break;
    case G: changed = toggle_green(); color = R; break;
   changed = toggle_both();
  }
}
  

