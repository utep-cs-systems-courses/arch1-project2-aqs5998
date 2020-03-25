# Lab 2: Functionality added by Alex Sanchez

The MSP430 Microcontroller, Each MSP430 board is equipped with buttons, LED's, a speaker, and an LED screen. 

# Instructions on how to run

1. Clone this repository to your machine windows, or mac is fine
2. Enter the timerLib folder directory
3. Install the h files by entering make install in the command line
4. Make sure that you see the h folder in your directory
4. Enter the src folder
5. Connect the MSP430 Microcontroller
6. Enter "make load" on the command line
7. The program is now loaded onto your MSP430

This toy should at minimum:

* generate sounds,
* dynamically change the LEDs that are illuminated, both brighly and dimmly,
* implement a state machine to maintain the state of the toy,
* and use the four buttons on the expansion board (P2.0-3) to transition the state machine.

# Button 1 (1 0 0 0)

Press this button to toggle between a bright red light, or a dim green light. If you leave the dim light on and play the song then the light will flicker with the music. If you leave the red light on then the light will just stay on

# Button 2 (0 1 0 0 )

Press this button to play Sandstorm. Sandstorm is an instrumental spong by Finnish DJ and record producer Darude. The song was released in 1999. Pressing the button again will play the song starting over. 

# Button 3 (0 0 1 0 )

Getting tired of the song? Press button 3 to turn off the song to a deep buzz sound

# Button 4 (0 0 0 1)

Getting tired of the song? Tired of the lights???? Press button 4 to stop the music, and lights

## Getting Started 

Inside this repository you will find two directories:
1. The 'demos' directory contains sample programs for you to review and learn from. These example programs are a great starting point in understanding how to program the MSP430 microcontroller. See the readme in the demo directory on how to compile and run the demo programs.
2. The 'project' directory should contain the source code for your toy.

