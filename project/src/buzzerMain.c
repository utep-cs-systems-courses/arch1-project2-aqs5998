#include <msp430.h>
#include <msp430g2553.h>
#include "libTimer.h"
//#include "led.h"
#include "buzzer.h"
#include "switches.h"

int main() {
    configureClocks();
    buzzer_init();
    switch_init();
    //playSong();
    // buzzer_set_period(2000);
    enableWDTInterrupts();
    or_sr(0x18);          // CPU off, GIE on
}
