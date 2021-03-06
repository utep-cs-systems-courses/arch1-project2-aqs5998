#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachines.h"
#include "assemblySongSwitch.h"

/* Configures the buttons instructions are in the readme file */
int state = 0;
char button2_state_down, button3_state_down, button4_state_down, switch_state_down, switch_state_changed; /* effectively boolean */

static char
switch_update_interrupt_sense()
{
  char p1val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p1val & SWITCHES);  /* if switch up, sense down */
  P2IES &= (p1val | ~SWITCHES); /* if switch down, sense up */
  return p1val;
}

void switch_init() /* setup switch */
{
  P2REN |= SWITCHES;  /* enables resistors for switches */
  P2IE = SWITCHES;    /* enable interrupts from switches */
  P2OUT |= SWITCHES;  /* pull-ups for switches */
  P2DIR &= ~SWITCHES; /* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler()
{
  char p1val = switch_update_interrupt_sense();
  switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  button2_state_down = (p1val & SW2) ? 0 : 1;
  button3_state_down = (p1val & SW3) ? 0 : 1;
  button4_state_down = (p1val & SW4) ? 0 : 1;

  if (button2_state_down == 1)
  {
    button3_state_down = 0;
    songState = 1;
  }
  if (button3_state_down == 1)
  {
    songState = 3;
    led_update();
  }
  if (button4_state_down == 1)
  {
    state_adv();
    //songState = 0;
    //ledOff();
    //playSongSwitch();
    //buzzer_init();  
  }

  /*
  if(button3_state_down = 1){
    button2_state_down = 0;
    songState = 0; //Turns off the song
  }
  */

  switch_state_changed = 1;
  led_update();
}
