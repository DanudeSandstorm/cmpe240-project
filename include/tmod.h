#ifndef TMOD_H
#define TMOD_H

#include <stddef.h>

//Morse code
static const char* lookuptable[36] = { ".-", "-...", "-.-.", "-..", ".", 
	"..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", 
	".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", 
	"--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", 
	"---..", "----.", "-----" };

int translate(char** mcode, char* string, size_t charsGot);

const char* lookup(char ch);

#endif //TMOD_H
