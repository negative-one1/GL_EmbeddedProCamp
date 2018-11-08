/*
Program lights two diagonal LEDs of same color on STM32F303 Discovery kit than lights next pair in clockwise direction.
*/
#include <stm32f303xc.h>
#include <stdint.h>

unsigned int i;

void delay()
{
	for (i=0;i<100000;i++) ;
}

int main(void)
{
	//init Port E
	RCC -> AHBENR |= (1<< 21); //Port E clock enable
	GPIOE -> MODER |= 0x55550000; //Configure PE8-PE15 as general purpose outputs
	uint8_t shift = 8;
	
	while(1)
	{
		GPIOE->ODR |= (1<< (shift+4)) | (1<< shift);
		delay();
		GPIOE->ODR &=~ ((1<< (shift+4)) | (1<< shift));
		shift = (shift+1) % 4+8;
	}
}