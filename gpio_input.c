/*
 * gpio_input.c
 *
 *  Created on: Sep 17, 2023
 *      Author: oscar
 */

#include "gpio_input.h"

void GPIOB_Input_Init(void) {
	// clock
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOBEN);

	// Settings GPIO
	GPIOB->MODER &= ~(GPIO_MODER_MODER2_0);
	GPIOB->MODER &= ~(GPIO_MODER_MODER2_1);

	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR2_0);
	GPIOB->PUPDR |= (GPIO_PUPDR_PUPDR2_1);
}
