#include "gpio.h"
#include "system_timer.h"

#include "ledmod.h"
#include "global.h"


/**
Takes an array of strings
*/
int outputLED(char** mcode) {
    for(int i = 0; i < returnSize; i++) {
        if (parseCharacter(mcode[i]) == 1) {
            return 1;
        }
    }
    return 0;
}

/**
Takes a string representing a morse code character
Parses and calls the corresponding blink
Delays between each blink;
Longer delay after character is printed
*/
int parseCharacter(char* mcharacter){
    unsigned int size = length(mcharacter);
    for (unsigned int i = 0; i < size; i++) {
        switch(mcharacter[i])
        {
            case '.':
                shortBlink();
                break;
            case '-':
                longBlink();
                break;
            case ' ':
                timer_delay_ms(400); //Delay for spaces
            default:
                return 1;
        }
        timer_delay_ms(200); //Delay between blinks in a character
    }
   timer_delay_ms(400); //Delays between characters
   return 0;
}

/*
To represent a dot:
turns on selected LED, 
waits a shorter period of time,
turns off LED
*/
void shortBlink() {
    gpio[GPSET0] |= 1 << 16;

    timer_delay_ms(300);

    gpio[GPCLR0] |= 1 << 16;
}

/*
To represent a dash:
turns on selected LED, 
waits a longer period of time,
turns off LED
*/
void longBlink() {

    gpio[GPSET0] |= 1 << 16;

    timer_delay_ms(500);

    gpio[GPCLR0] |= 1 << 16;

}

/*
Returns the length (amount of characters) in a char array
*/
unsigned int length(char const* s) {
    unsigned int i = 0;
    while (*s++ != '\0')
        ++i;

    return i;
}
