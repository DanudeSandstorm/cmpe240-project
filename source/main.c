#include "uart.h"
#include "tmod.h"
#include "ledmod.h"
#include "printf.h"

void print_translation(Array* code);

int main()
{
    init_uart();

    const int bufferSize = 80;
    char buffer [bufferSize];

    while (1) {
        size_t charsGot = get_string(buffer, bufferSize);
        Array mcode;
	    initArray(&mcode, 8);

        if (translate(&mcode, buffer, charsGot) == 0) {
            print_translation(&mcode);
            output(&mcode);
        }

        freeArray(&mcode);
    }
    
    return 0;
}

/**
Takes a translated code and prints it to uart
*/
void print_translation(Array* code) {
	for(size_t i = 0; i < code.used; i++) {
        sprintf("%s", code.array[i]);
	}
}