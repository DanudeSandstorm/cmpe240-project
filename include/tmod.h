#ifndef TMOD_H
#define TMOD_H

//TODO struct morse code dictionary include numbers
const char* lookuptable[36] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----" };

int print_translation(const char* string);

int translate(char* string, size_t charsGot);

char* lookup(char ch);

#endif //TMOD_H