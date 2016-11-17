#ifndef TMOD_H
#define TMOD_H

//Morse code
const char* lookuptable[36] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----" };

int translate(Array* mcode, char* string, size_t charsGot);

char* lookup(char ch);

#endif //TMOD_H