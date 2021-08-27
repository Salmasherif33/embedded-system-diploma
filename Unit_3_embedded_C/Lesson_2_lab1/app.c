#include "uart.h"

unsigned char String_To_Send[100] = "learn-in-depth:<Salma>";
unsigned char const String_To_Send2[100] = "learn-in-depth:<Salma>";

void main(void){

        Uart0_Send_String(String_To_Send);

}