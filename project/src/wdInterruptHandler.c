#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h" 
#include "switches.h" 

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  playSong();
  if (++blink_count == 40) {
    // state_advance();
    // buzzer_set_period(1000);
    if(button2_state_down == 1){//Play music and blink with first button.
      playSong();
    }
    blink_count = 0;
  }
}
