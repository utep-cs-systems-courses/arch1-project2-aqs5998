#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h" 

void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  if (++blink_count == 2) {
    // state_advance();
    // buzzer_set_period(1000);
    playSong();
    blink_count = 0;
  }
}
