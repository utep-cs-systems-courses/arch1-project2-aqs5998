#include <msp430.h>
#include <msp430g2553.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"

void main(void) 
{  
  configureClocks();
  switch_init();
  //led_init();
  // WDTCTL = WDTPW + WDTHOLD;
  //P1DIR |= BIT6;
  //P1SEL |= BIT6;
  //CCR0 = 499;//dim light
  //CCTL1 = OUTMOD_7;
  //CCR1 = 2;
  //TACTL = TASSEL_2 + MC_1;
  //_BIS_SR(LPM0_bits);
  
  led_init();
  
  
  or_sr(0x18);  // CPU off, GIE on
} 
