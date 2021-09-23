/*
 * lcd.c
 *
 * Created: 4/22/2021 3:01:11 PM
 *  Author: Marco
 */

#include "lcd.h"
GPIO_PinConfig_t PinCfg ;
void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++)
			;
}



void LCD_clear_screen() {
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_KICK() {
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_SET);
	asm volatile ("nop");
	asm volatile ("nop");
	delay_ms(50);
	MCAL_GPIO_WritePin(LCD_CTRL, EN_SWITCH, GPIO_PIN_RESET);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position) {
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

void LCD_INIT() {

	delay_ms(20);


	// SET THE FIRST 3 PINS AS OUPUT

	PinCfg.GPIO_PinNumber = RS_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = RW_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = EN_SWITCH;
	PinCfg.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	LCD_IS_BUSY();
	//	LCD_CTRL &= ~(1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
	//	DataDir_LCD_PORT = 0xFF;
	delay_ms(15);

	LCD_clear_screen();
	delay_ms(50);

#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	delay_ms(1);
#endif

	/*#ifdef FOUR_BIT_MODE
	//define  that we use the MSBs in 4 bits mode
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	_delay_us(50);
	#endif*/

	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
	delay_ms(1);
}

void LCD_IS_BUSY() {
	//DataDir_LCD_PORT &= ~(0xFF << DATA_SHIFT);
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	//	LCD_CTRL |= (1 << RW_SWITCH);
	//	LCD_CTRL &= ~(1 << RS_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);

	while((MCAL_GPIO_ReadPort(LCD_CTRL) & ((uint16_t)(0x80)) ) << 7 == 1)	//pin 7 on => is busy
		LCD_KICK();

	//	DataDir_LCD_PORT |= (0xFF << DATA_shift);
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_OUPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_OUTPUT_10;
	MCAL_GPIO_Init(LCD_CTRL, &PinCfg);

	//	LCD_CTRL &= ~(1 << RW_SWITCH);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);


}

void LCD_WRITE_COMMAND(unsigned char command) {
	//LCD_IS_BUSY();
#ifdef EIGHT_BIT_MODE
	MCAL_GPIO_WritePort(LCD_CTRL, command);
	//	LCD_CTRL->BRR = (LCD_CTRL->BRR & 0x00FF) | (command);
	//	LCD_CTRL->CRL ^= (LCD_CTRL->CRL ^ command) & 0x00ff;
	//	LCD_CTRL->CRL = command;
	//	LCD_CTRL ^= (LCD_CTRL-> ^ command) & 0x00ff;
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	//	LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH));
	delay_ms(1);
	LCD_KICK();
#endif

	/*#ifdef FOUR_BIT_MODE

	LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
	LCD_CTRL &= ~((1<<RW_SWITCH | 1<<RS_SWITCH));	//r/w off(write mode), (RS)Command mode
	LCD_KICK();	//flash the above info to lcd
	_delay_ms(1);

	LCD_PORT = (LCD_PORT & 0x0F) | (command << DATA_SHIFT);
	LCD_CTRL &= ~((1<<RW_SWITCH | 1<<RS_SWITCH));	//r/w off(write mode), (RS)Command mode
	LCD_KICK();	//flash the above info to lcd
	_delay_ms(1);
#endif*/
}

void LCD_WRITE_CHAR(unsigned char character) {
	//LCD_IS_BUSY();
	//	LCD_CTRL->CRL = character;
#ifdef EIGHT_BIT_MODE
	MCAL_GPIO_WritePort(LCD_CTRL, character);
	//	LCD_CTRL ^= (LCD_CTRL ^ character) & 0x00ff;
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_SET);
	//	LCD_CTRL &= ~(1 << RW_SWITCH);
	//	LCD_CTRL |= (1 << RS_SWITCH);
	delay_ms(1);
	LCD_KICK();
#endif

/*#ifdef FOUR_BIT_MODE
	LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);	//write data
	LCD_CTRL &= ~(1<<RW_SWITCH);	//write mode
	LCD_CTRL |= 1<<RS_SWITCH;		//data mode
	LCD_KICK();	//flash the above info to lcd
	_delay_ms(1);
	LCD_PORT = (LCD_PORT & 0x0F) | (data << DATA_SHIFT);	//write data
	LCD_CTRL &= ~(1<<RW_SWITCH);	//write mode
	LCD_CTRL |= 1<<RS_SWITCH;		//data mode
	LCD_KICK();	//flash the above info to lcd
	_delay_ms(1);
#endif*/

}

void LCD_WRITE_STRING(char *string) {
	int count = 0;
	while (*string > 0) {
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16) {
			LCD_GOTO_XY(2, 0);
		} else if (count == 32) {
			LCD_clear_screen();
			LCD_GOTO_XY(1, 0);
			count = 0;
		}
	}
}
