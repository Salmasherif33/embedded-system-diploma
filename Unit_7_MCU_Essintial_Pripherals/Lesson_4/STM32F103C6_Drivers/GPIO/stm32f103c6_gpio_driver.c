/*
 *
 * Created on: 20/9/2021
 * Author: Salma Sherif
 *
 *
 * */

#include "stm32f103c6_gpio_driver.h"


/**================================================================
 * @Fn			-MCAL_GPIO_Init
 * @brief 		-Intializes GPIOx PINy according to the specified parameters in pinConfig
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 	-pinconfig : a pointer to GPIO_Pinconfig_t structure that contains
 				 the configuration information for the specified GPIO pin
 * @retval	 	-none
 * Note			-STM32f103c6 MCU has GPIO A,B,B,D,E modules
                 but LQFP48 Package has only A,B, Part of C,D
 */

uint8_t GET_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;

	case GPIO_PIN_1:
		return 4;
		break;

	case GPIO_PIN_2:
		return 8;
		break;

	case GPIO_PIN_3:
		return 12;
		break;

	case GPIO_PIN_4:
		return 16;
		break;

	case GPIO_PIN_5:
		return 20;
		break;

	case GPIO_PIN_6:
		return 24;
		break;

	case GPIO_PIN_7:
		return 28;
		break;

	case GPIO_PIN_8:
		return 0;
		break;

	case GPIO_PIN_9:
		return 4;
		break;

	case GPIO_PIN_10:
		return 8;
		break;

	case GPIO_PIN_11:
		return 12;
		break;

	case GPIO_PIN_12:
		return 16;
		break;

	case GPIO_PIN_13:
		return 20;
		break;

	case GPIO_PIN_14:
		return 24;
		break;

	case GPIO_PIN_15:
		return 28;
		break;
	}

	return 0;
}


void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_PinConfig_t *PinConfig)
{
	volatile uint32_t *ConfigRegister = NULL;
	uint32_t Pin = 0;
	ConfigRegister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ? &GPIOx->CRL: &GPIOx->CRH;

	//clear CNF[1:0], MODE[1:0]
	(*ConfigRegister) &= ~(0x0F << GET_CRLH_Position(PinConfig->GPIO_PinNumber));

	//if Pin is output
	if(PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD || PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP
			|| PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD || PinConfig->GPIO_MODE == GPIO_MODE_OUPUT_PP)
	{
		Pin = (( ( (PinConfig->GPIO_MODE - 4) << 2 ) | (PinConfig->GPIO_output_speed) ) &0x0F );
	}
	//input, Reset value for MODE
	else {
		if( PinConfig->GPIO_MODE == GPIO_MODE_ANALOG || PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO )
		{
			//set CNF, MODE
			Pin = ((PinConfig->GPIO_MODE << 2) | 0x0) & (0x0F);
		}
		else if( PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT)	//as input floating
		{
			Pin = (GPIO_MODE_INPUT_FLO << 2 ) & (0x0F);
		}
		else{ //pull up, or pull down

			Pin = (PinConfig->GPIO_MODE << 2) & (0x0F);

			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				GPIOx->ODR  |= (PinConfig->GPIO_PinNumber);
			}
			else
			{
				GPIOx->ODR  &= ~(PinConfig->GPIO_PinNumber);
			}
		}
	}

	//write on the CRL or CRH
	*(ConfigRegister) |= ((Pin) << GET_CRLH_Position(PinConfig->GPIO_PinNumber));
}

/**================================================================
 * @Fn			-MCAL_GPIO_DeInit
 * @brief 		-Reset all the GPIO registers
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select GPIO peripheral
 * @retval	 	-none
 * Note			-none
 */

void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx)
{
	//GPIOx->BRR = 0x00000000;
	//GPIOx->BSRR = 0x00000000;
	//GPIOx->CRH = 0x44444444;
	//GPIOx->CRL = 0x44444444;
	//GPIOx->IDR = ; (READ ONLY);
	//GPIOx->LCKR = 0x00000000;
	//GPIOx->ODR = 0x00000000;

	//or you can use reset Controller
	//ApB2 peripheral reset register (RCC_APB2RSTR)
	//set and cleared by software

	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);

	}
	else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if (GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if (GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}

}


/**================================================================
 * @Fn			-MCAL_GPIO_ReadPin
 * @brief 		-Read specific GPIOx Pin value
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 	-PinNumber : set pin number to read
 * @retval	 	-The Reading value of the input pin
 * Note			-none
 */

uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{
	uint8_t pinStatus;
	if((GPIOx->IDR & PinNumber) != (uint32_t)GPIO_PIN_RESET)
	{
		pinStatus = GPIO_PIN_SET;
	}
	else
	{
		pinStatus = GPIO_PIN_RESET;

	}
	return pinStatus;
}

/**================================================================
 * @Fn			-MCAL_GPIO_ReadPort
 * @brief 		-Read the input GPIOx port value
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select GPIO peripheral
 * @retval	 	-The input port value
 * Note			-none
 */

uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef* GPIOx)
{
	uint16_t portStatus;
	portStatus = (uint16_t)(GPIOx->IDR);
	return portStatus;
}


/**================================================================
 * @Fn			-MCAL_GPIO_WritePin
 * @brief 		-Write a value on specific GPIOx Pin
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 	-PinNumber : specifies pin number
 * @param [in] 	-value : Set the write value
 * @retval	 	-none
 * Note			-none
 */

void MCAL_GPIO_WritePin(GPIO_TypeDef* GPIOx,uint16_t PinNumber,uint8_t Value)
{
	if(Value != GPIO_PIN_RESET)
	{
	//GPIOx->ODR |= PinNumber;
	//or
	/*	Bits 31:16 BRy: Port x Reset bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Reset the corresponding ODRx bit
		Note: If both BSx and BRx are set, BSx has priorit	*/
	GPIOx->BSRR = (uint32_t)PinNumber;
	}
	else
	{
	/*	Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Reset the corresponding ODRx bit */
		GPIOx->BRR = (uint32_t)PinNumber;
	}
}

/**================================================================
 * @Fn			-MCAL_GPIO_WritePort
 * @brief 		-Write a value for GPIOx Port
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 	-value : Set the write value
 * @retval	 	-none
 * Note			-none
 */

void MCAL_GPIO_WritePort(GPIO_TypeDef* GPIOx,uint16_t Value)
{
	GPIOx->ODR = (uint32_t)Value;

}


/**================================================================
 * @Fn			-MCAL_GPIO_TogglePin
 * @brief 		-Write a value for GPIOx Port
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 	-PinNumber : specifies pin number
 * @retval	 	-none
 * Note			-none
 */


void MCAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx,uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;
}


/**================================================================
 * @Fn			-MCAL_GPIO_LockPin
 * @brief 		-Locking specific pin make pin to be frozen
 * @param [in] 	-GPIOx : where x can be (A..E depending on device used) to select GPIO peripheral
 * @param [in] 	-PinNumber : specifies pin number
 * @retval	 	-Return (OK) if pin config is locked (ERROR) if not locked @ref GPIO_RETURN_LOCK
 * Note			-When the LOCK sequence has been applied on a port bit it is no longer possible to modify
				 the value of the port bit until the next reset.
 */

uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef* GPIOx,uint8_t PinNumber)
{
	//set LCKK[16]
	volatile uint32_t tmp = 1<<16;

	//Set the Lcky
	tmp |= PinNumber;

	//Write 1
	GPIOx->LCKR |= tmp;

	//Write 0
	GPIOx->LCKR = PinNumber;

	//Write 1;
	GPIOx->LCKR = tmp;

	//read 0

	tmp = GPIOx->LCKR;

	//read 1
	if((uint32_t)(GPIOx->LCKR  & 1<< 16))
	{
		return GPIO_RETURN_LOCK_ENABLED;
	}
	else
	{
		return GPIO_RETURN_LOCK_ERROR;
	}

}



