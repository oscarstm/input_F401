/*
 * gpio_output.c
 *
 *  Created on: Sep 17, 2023
 *      Author: oscar
 */

#include "gpio_output.h"

void GPIOC_Output_Init(void) {
	RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOCEN);

	GPIOC->MODER &= ~(GPIO_MODER_MODER13);
	GPIOC->MODER |= (GPIO_MODER_MODER13_0);
	GPIOC->MODER &= ~(GPIO_MODER_MODER13_1);
	GPIOC->OTYPER &= ~(GPIO_OTYPER_OT13);
	GPIOC->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR13);
	GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPDR13);
}

