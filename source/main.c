#include "uart.h"
#include "tmod.h"

int main()
{
    init_uart();

    const int bufferSize = 80;
    char buffer [bufferSize];

    while (1) {
        size_t charsGot = get_string(buffer, bufferSize);

        translate(buffer, charsGot);
    }
    
    return 0;
}