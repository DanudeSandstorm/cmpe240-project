#include "uart.h"
#include "printf.h"
#include "tmod.h"

int main()
{

    init_uart();

    const int bufferSize = 80;

    char buffer [bufferSize];

    while (1) {
        size_t charsGot = get_string(buffer, bufferSize);

        for (size_t i = 0; i < charsGot; ++i) {
            translate(buffer[i]);
        }
    }
    
    return 0;
}