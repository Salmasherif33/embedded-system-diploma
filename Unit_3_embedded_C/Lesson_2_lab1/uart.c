#include "uart.h"



#define UART0DR  *( (volatile unsigned int* const) ( (unsigned int* ) 0x101f1000) )


void Uart0_Send_String(unsigned char* String){
    while (*String != '\0')
    {
        UART0DR = (unsigned int) (*String); //FIFO sends
        String++;
    }
    
}