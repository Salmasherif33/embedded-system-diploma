/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Salma Sherif
 * @brief          : Toggle Led on STMF103C6
 ******************************************************************************
 
 */


typedef volatile unsigned int vuint32_t;

#include "stdint.h"

//register adresses
#define RCC_BASE   0x40021000
#define PortA_BASE 0x40010800

#define RCC_APB2ENR  *(volatile uint32_t *) (RCC_BASE + 0x18)
#define GPIOA_CRH    *(volatile uint32_t *) (PortA_BASE + 0x04)
#define GPIOA_ODR    *(volatile uint32_t *) (PortA_BASE + 0x0C)

//bit fileds
unsigned char arr[3] = {1,2,3};
unsigned char const arr2[3] = {2,4,3};

typedef union{
	vuint32_t all_fields; //32bits
	struct{
		vuint32_t reserved: 13;
		vuint32_t P_13: 1;
	}Pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(PortA_BASE + 0x0C);


int main(void)
{
	RCC_APB2ENR |= 1<<2; //set bit 13
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1){

		R_ODR->Pin.P_13 = 1;
		for(int j = 0; j < 5000; j++); //delay
		R_ODR->Pin.P_13 = 0;
		//GPIOA_ODR ^= (1<<13);
		for(int j = 0; j< 5000; j++);

	}

}
