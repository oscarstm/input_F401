#include "stm32f4xx.h"

#include "clk_user.h"
#include "gpio_input.h"
#include "gpio_output.h"

uint8_t BUTTON;

int main(void) {
	clk_user();
	GPIOB_Input_Init();
	GPIOC_Output_Init();

	while (1) {
		BUTTON = (GPIOB->IDR) & (GPIO_IDR_IDR_2);

		if (BUTTON == 0x0) {
			GPIOC->ODR &= ~(GPIO_ODR_ODR_13);
		} else {
			GPIOC->ODR |= (GPIO_ODR_ODR_13);
		}
	}

}

