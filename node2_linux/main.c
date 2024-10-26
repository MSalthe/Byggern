#include <stdio.h>
#include <stdarg.h>
#include "sam.h"
#include "include/uart.h"

#define CPU_FREQ 84000000
#define UART_BAUD 9600

/*
 * Remember to update the Makefile with the (relative) path to the uart.c file.
 * This starter code will not compile until the UART file has been included in the Makefile. 
 * If you get somewhat cryptic errors referencing functions such as _sbrk, 
 * _close_r, _write_r, _fstat etc, you have most likely not done that correctly.

 * If you get errors such as "arm-none-eabi-gcc: no such file", you may need to reinstall the arm gcc packages using
 * apt or your favorite package manager.
 */
//#include "../path_to/uart.h"

int main()
{
    SystemInit();

    WDT->WDT_MR = WDT_MR_WDDIS; //Disable Watchdog Timer
    
    uart_init(CPU_FREQ, UART_BAUD);
    printf("Hello World\n\r");

    while (1)
    {
        /* code */
    }
    
}