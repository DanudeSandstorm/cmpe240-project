#include "uart.h"
#include "tmod.h"
#include "ledmod.h"

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

int print_translation(Array* code) {
    //TODO format output
	for(size_t i = 0; i < code.used; i++) {
        if () {
		}
	}
    return 0;
}