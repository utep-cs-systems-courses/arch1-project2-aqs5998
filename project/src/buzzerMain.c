#include <msp430.h>
#include <msp430g2553.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

int main()
{
    configureClocks(); //Sets up the clocks
    buzzer_init();     //Initializes the buzzer
    led_init();        //Initializes the leds
    switch_init();     //Initializes the buttons
    //playSong();
    // buzzer_set_period(2000);
    enableWDTInterrupts(); //Allows to recognize a button press
    or_sr(0x18);           // CPU off, GIE on
}
