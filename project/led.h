#ifndef led_included
#define led_included

#include <msp430.h>

#define LED_RED BIT0
#define LED_GREEN BIT6
#define LEDS (BIT0 | BIT6)

void led_init();
void led_update();
void button_press(char c);
void state_change();

extern unsigned char red_on, green_on, leds_changed, green_led_state, red_led_state;

#endif