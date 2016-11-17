#ifndef LEDMOD_H
#define LEDMOD_H

#import "gpio.h"

// Init GPIO select for external LED
gpio[GPFSEL1] = 0x040000; // Selected pin 16

int output(char* code[], unsigned int size);

int parseCharacter(char* code);

void shortBlink();

void longBlink();

unsigned int length(char const* s);

#endif //LEDMOD_H