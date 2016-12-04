#ifndef LEDMOD_H
#define LEDMOD_H

int outputLED(char* code[]);

int parseCharacter(char* code);

void shortBlink();

void longBlink();

unsigned int length(char const* s);

#endif //LEDMOD_H
