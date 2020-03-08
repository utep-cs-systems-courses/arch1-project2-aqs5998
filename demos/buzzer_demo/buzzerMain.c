#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "stateMachines.h"

int main() {
    configureClocks();
 
    buzzer_init();
    playSong();
    // buzzer_set_period(2000);
    enableWDTInterrupts();
    or_sr(0x18);          // CPU off, GIE on
}
