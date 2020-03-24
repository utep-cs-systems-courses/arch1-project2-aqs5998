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


/* #include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
void
__interrupt_vec(WDT_VECTOR) WDT(){
  static char blink_count = 0;
  if (++blink_count == 125){
    if (button1_state_down == 1){
      playSong();
    }
    if (button2_state_down == 1){ // Dim led
      state_advance();
    }
    if (button3_state_down == 1){
      state_advance();
    }
    state_advance();
    blink_count = 0;
  }
}
*/