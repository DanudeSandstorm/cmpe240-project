#include "uart.h"
#include "printf.h"
#include "tmod.h"

int main()
{
    while (1) {
        size_t charsGot = get_string(buffer, bufferSize);
    }
    
    return 0;
}