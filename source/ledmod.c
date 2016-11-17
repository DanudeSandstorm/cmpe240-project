#include "ledmod.h"
#include "gpio.h"
#include "system_timer.h"

int output(char* code[], unsigned int size) {
    for(int i = 0; i < size; i++) {
        if (parseCharacter(code[i]) == 1) {
            return 1;
        }
    }
    return 0;
}

/**
Takes a string repensenting a morse code character
Parses and calls the corresponding blink
Delays between each blink;
Longer delay after character is printed
*/
int parseCharacter(const char* character){
    unsigned int size = length(input);
    for (unsigned int i = 0; i < size; i++) {
        switch(character[i])
        {
            case '.':
                shortBlink();
                break;
            case '-':
                longBlink();
                break;
            default:
                break;
        }
        timer_delay_ms(200);
    }
   timer_delay_ms(1000);
}

/*
To represent a dot:
turns on selected LED, 
waits a shorter period of time,
turns off LED
*/
void shortBlink() {
    gpio[GPSET0] |= 1 << 16;

    timer_delay_ms(200);

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

    timer_delay_ms(400);

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