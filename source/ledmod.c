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
    }
    //TODO wait
}

void shortBlink() {
    /*TODO
    turn on
    short wait
    turn off
    */
}

void longBlink() {
    //TODO
    //long wait
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