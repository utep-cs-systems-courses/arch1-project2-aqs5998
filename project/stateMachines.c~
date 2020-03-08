#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
char state = 0;

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

void play_song() {
  int[] notes = {900, 0, 810, 740, 0, 810, 830, 845, 840, 845, 0, 0, 910, 890, 870, 850, 830, 0, 790, 0, 800, 780, 0, 790, 770, 0, 0, NULL};
  for(int i = 0; notes[i]!=NULL;i++){
    buzzer_set_period(notes[i]);
    break;
  }
  
}
