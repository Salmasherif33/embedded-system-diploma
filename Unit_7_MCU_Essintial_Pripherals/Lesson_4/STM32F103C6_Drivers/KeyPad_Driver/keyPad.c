/*
 * keyPad.c
 *
 * Created: 9/20/2021 3:48:32 AM
 *  Author: lenovo
 */ 

#include "keyPad.h"

int KeyPad_R[] = {R0,R1,R2,R3};
int KeyPad_C[] = {C0,C1,C2,C3};	

GPIO_PinConfig_t pinConfig;

void KEYPAD_INIT(void){
	//DateDir_KEYPAD_PORT &= ~((1<<R0)|(1<<R1) | (1<<R2) | (1<<R3));

	pinConfig.GPIO_PinNumber = R0;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	pinConfig.GPIO_PinNumber = R1;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	pinConfig.GPIO_PinNumber = R2;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	pinConfig.GPIO_PinNumber =R3;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	//DateDir_KEYPAD_PORT |= ((1<<C0)|(1<<C1) | (1<<C2) | (1<<C3));
	pinConfig.GPIO_PinNumber = C0;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	pinConfig.GPIO_PinNumber = C1;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	pinConfig.GPIO_PinNumber = C2;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	pinConfig.GPIO_PinNumber = C3;
	pinConfig.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	pinConfig.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(KEYPAD_PORT, &pinConfig);

	//KEYPAD_PORT = 0xff;
	MCAL_GPIO_WritePort(KEYPAD_PORT, 0xFF);

}

char KEYPAD_GET_CHAR(void){
	int i,j;
	for(i = 0; i < 4 ; i++){
		//KEYPAD_PORT |= ((1<<KeyPad_C[0]) | (1<<KeyPad_C[1]) | (1<<KeyPad_C[2]) | (1<<KeyPad_C[3])); //initially, all 1(not ptressed)

		MCAL_GPIO_WritePin(KEYPAD_PORT, KeyPad_C[0], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KeyPad_C[1], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KeyPad_C[2], GPIO_PIN_SET);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KeyPad_C[3], GPIO_PIN_SET);

		//KEYPAD_PORT &= ~(1<<KeyPad_C[i]);
		MCAL_GPIO_WritePin(KEYPAD_PORT, KeyPad_C[i], GPIO_PIN_RESET);

		for(j = 0; j < 4; j++){

			if(MCAL_GPIO_ReadPin(KEYPAD_PORT, KeyPad_R[j]) == 0){	//check if press
				while(MCAL_GPIO_ReadPin(KEYPAD_PORT, KeyPad_R[j]) == 0); //single pressing
				switch(i){
				case 0:
					if(j == 0)	return '7';
					else if(j == 1) return '4';
					else if(j == 2) return '1';
					else if(j == 3) return '!';
					break;

				case 1:
					if(j == 0)	return '8';
					else if(j == 1) return '5';
					else if(j == 2) return '2';
					else if(j == 3) return '0';
					break;

				case 2:
					if(j == 0)	return '9';
					else if(j == 1) return '6';
					else if(j == 2) return '3';
					else if(j == 3) return '=';
					break;

				case 3:
					if(j == 0)	return '/';
					else if(j == 1) return '*';
					else if(j == 2) return '-';
					else if(j == 3) return '+';
					break;
				}
			}
		}
	}
	return 'N';	//if nothing pressed
}

