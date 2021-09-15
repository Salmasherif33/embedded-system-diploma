/*
 * Atmega32.c
 *
 * Created: 9/15/2021 12:37:05 AM
 * Author : Salma Sherif
 */ 

#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>


//Interrupt registers
#define  INT_MCUCR		*((volatile unsigned int *)(0x55))
#define  INT_MCUSCR		*((volatile unsigned int *)(0x54))
#define  INT_GICR		*((volatile unsigned int *)(0x5B))
#define  INT_GIFR		*((volatile unsigned int *)(0x5A))
//#define  INT_SREG		*((volatile unsigned int *)(0x5F))

//Port D registers
#define  PORT_D		*((volatile unsigned int *)( 0x32))
#define  DDR_D		*((volatile unsigned int *)(0x31))
#define  PIN_D		*((volatile unsigned int *)(0x30))


//configuration for interrupt 0, 1 ,2
void EXT_INT_Init()
{
	/*
	set for INT 0 : for any logical change
	ISC00 => 1
	ISC01 => 0
	set for INT 1 : for rising edge
	ISC10 => 1
	ISC11 => 1
	*/
	INT_MCUCR |= (0b1101 << 0);
	
	//set for INT 2 : clear bit 6 for falling edge
	INT_MCUSCR &= ~(1 << 6); 	
	
	//recommended: disable INT2 on GICR
	INT_GICR &= ~(1 << 5);
	
	//enable INT0, INT1, INT2
	INT_GICR |= (0b111 << 5);	
	
	//enable global interrupt
	//INT_SREG |= 1 << 6;
	sei();
}


//configuration for Port D
void PORTD_Init()
{
	//enable LEDS pins as outputs
	DDR_D |= 0b111 << 5;	
	
}



int main(void)
{
	EXT_INT_Init();
	PORTD_Init();
    /* Replace with your application code */
    while (1) 
    {
		//all LEDs OFF
		PORT_D &= ~(1 << 5);
		PORT_D &= ~(1 << 6);
		PORT_D &= ~(1 << 7);
    }
}


/*	INTERRUPT HANDLERS	*/
 ISR(INT0_vect)
 {
	PORT_D |= (1 << 5); //PD5 is ON
	_delay_ms(1000);
	
 }
 
  ISR(INT1_vect)
  {
	 PORT_D |= (1 << 6);//PD6 is ON
	 _delay_ms(1000);
	
  }
  
   ISR(INT2_vect)
   {
	 PORT_D |= (1 << 7); //PD7 is ON
	 _delay_ms(1000);
	
   }


