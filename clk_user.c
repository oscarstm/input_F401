/*
 * clk_user.c
 *
 *  Created on: Sep 17, 2023
 *      Author: oscar
 */

#include "clk_user.h"

void clk_user(void) {
	/*
	 * System parameters
	 */
	FLASH->ACR |= (FLASH_ACR_ICEN);
	FLASH->ACR |= (FLASH_ACR_PRFTEN);
	FLASH->ACR |= (FLASH_ACR_DCEN);
	FLASH->ACR |= (FLASH_ACR_LATENCY_2WS);
	/*
	 * RCC parameters
	 */
	RCC->CR |= (RCC_CR_HSEON);
	while ((RCC->CR & (RCC_CR_HSERDY)) == (RCC_CR_HSERDY)) {
		//
	}

	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLSRC_HSE);

	// dividido PLL entre 25
	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLM_0);
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM_1);
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLM_2);
	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLM_3);
	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLM_4);

	// multiplicado por 168
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN_0);
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN_1);
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN_2);
	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLN_3);
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN_4);
	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLN_5);
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN_6);
	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLN_7);
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLN_8);

	// dividido entre 2
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLP_0);
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLP_1);

	// dividido entre 4
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLQ_0);
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLQ_1);
	RCC->PLLCFGR |= (RCC_PLLCFGR_PLLQ_2);
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLQ_3);

	RCC->CR |= (RCC_CR_PLLON);
	while ((RCC->CR & (RCC_CR_PLLRDY)) == (RCC_CR_PLLRDY)) {
		//
	}

	// AHB prescaler no se divide == 84 MHz
	RCC->CFGR |= (RCC_CFGR_HPRE_DIV1);

	// APB1 == 42 MHz
	RCC->CFGR &= ~(RCC_CFGR_PPRE1_0);
	RCC->CFGR &= ~(RCC_CFGR_PPRE1_1);
	RCC->CFGR |= (RCC_CFGR_PPRE1_2);

	// APB2 == 84 MHz
	RCC->CFGR |= (RCC_CFGR_PPRE2_DIV1);

	// activar PLL system clock
	RCC->CFGR &= ~(RCC_CFGR_SW_0);
	RCC->CFGR |= (RCC_CFGR_SW_1);
}

