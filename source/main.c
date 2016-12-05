#include "uart.h"
#include "gpio.h"
#include "printf.h"

#include "global.h"
#include "tmod.h"
#include "ledmod.h"

int returnSize = 0;

void print_translation(char** code);

int main()
{
    const int bufferSize = 1024;

    // Init GPIO select for external LED
    gpio[GPFSEL1] = 0x040000; // Selected pin 16

    init_uart();
    char buffer [bufferSize];
    
    char* mcode[bufferSize + 1];
    while (1) {
        returnSize = 0;
        size_t charsGot = get_string(buffer, bufferSize);

        if (translate(mcode, buffer, charsGot) == 0) {
            print_translation(mcode);
            outputLED(mcode);
        }

    }
    return 0;
}

/**
Takes a translated code and prints it to uart
*/
void print_translation(char** mcode) {
	for(int i = 0; i < returnSize; i++) {
        printf("%s", mcode[i]);
	}
}