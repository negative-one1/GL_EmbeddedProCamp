/*
Lecture5 Ex1: Develop application that communicates with PC trough UART 
Application should send just echo. 
You should use only CMSIS library.
UART driver should contains following functions:
init();
open();
read();
write();
close();
deinit();
*/

#include <stm32f303xc.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>


#define BUF_CAPACITY (50u)

char buf[50];

void close();

void init()
{
	RCC -> CFGR3 &= ~(RCC_CFGR3_UART4SW_Msk); //((1<<20)|(1<<21)); //Configure UART4 clock: 
	RCC -> APB1ENR |= RCC_APB1ENR_UART4EN;  //Enable UART4 clock
	 
	
	//Configure port
	RCC -> AHBENR |= RCC_AHBENR_GPIOCEN;//Port C clock enable
	//Set GPIOC.10 to alternate function
	GPIOC->MODER &= ~(GPIO_MODER_MODER10_Msk);
	GPIOC -> MODER |= GPIO_MODER_MODER10_1;
	GPIOC -> MODER &= ~(GPIO_MODER_MODER10_0);
	//Set GPIOC.11 to alternate function
	GPIOC -> MODER |= GPIO_MODER_MODER11_1;
	GPIOC -> MODER &= ~(GPIO_MODER_MODER11_0);
	
	GPIOC ->AFR[1] |= (0x0 << GPIO_AFRH_AFRH2_Pos); //Init alternate function register for GPIOC.10
	GPIOC ->AFR[1] |= (0x5 << GPIO_AFRH_AFRH2_Pos);	//Switch GPIOC.10 to AF5 (UART Tx)
	GPIOC ->AFR[1] |= (0x0 << GPIO_AFRH_AFRH3_Pos); //Init alternate function register for GPIOC.11
	GPIOC ->AFR[1] |= (0x5 << GPIO_AFRH_AFRH3_Pos);	//Switch GPIOC.11 to AF5 (UART Rx)
	
	//Set output type
	GPIOC ->OTYPER |= GPIO_OTYPER_OT_10 | GPIO_OTYPER_OT_11; //Set output type to push pull
	GPIOC ->PUPDR &= ~(GPIO_PUPDR_PUPDR10 | GPIO_PUPDR_PUPDR11);
	
	
	//Disable uart
	UART4 ->CR1 &= ~(USART_CR1_UE);
	//Set baud rate   @8Mhz fraction 0x271 to have baud rate = 9600 baud/sec
	UART4 ->BRR &= ~(USART_BRR_DIV_FRACTION_Msk); //
	UART4 ->BRR &= ~(USART_BRR_DIV_MANTISSA_Msk); // 
	UART4 ->BRR |= 0x0341 & (USART_BRR_DIV_FRACTION_Msk | USART_BRR_DIV_MANTISSA_Msk); //Write value

	// Set 8-bit word (0x00) 
	UART4->CR1 &= ~(USART_CR1_M_Msk);
	
	//Set oversampling by 16
	UART4->CR1 &= ~(USART_CR1_OVER8_Msk);
	
	//Set stop bits (1 stop bit)
	UART4->CR2 &= ~(USART_CR2_STOP);
	
}

void deinit()
{
	close();
	RCC -> APB1ENR &= ~RCC_APB1ENR_UART4EN;  //Disable UART4 clock
	
	//Configure port
	RCC -> AHBENR &= ~RCC_AHBENR_GPIOCEN;//Port C clock enable
	//Reset GPIOC.10 alternate function
	GPIOC->MODER &= ~(GPIO_MODER_MODER10_Msk);

	//Reset GPIOC.11 alternate function
	GPIOC->MODER &= ~(GPIO_MODER_MODER11_Msk);
	

	//Reset baud rate settings
	UART4 ->BRR &= ~(USART_BRR_DIV_FRACTION_Msk); //
	UART4 ->BRR &= ~(USART_BRR_DIV_MANTISSA_Msk); // 
	
}

void open()
{
	//Enable UART
	UART4 ->CR1 |= USART_CR1_UE;
	//enable Transmitter & Receiver
	UART4->CR1 |= USART_CR1_RE;
	UART4->CR1 |= USART_CR1_TE;
}

void close()
{
	//disable Transmitter & Receiver
	UART4->CR1 &= ~(USART_CR1_RE);
	UART4->CR1 &= ~(USART_CR1_TE);
	
	//disable UART
	UART4 ->CR1 &= ~(USART_CR1_UE);
}

void write(char* character)
{
	UART4->TDR = *character;
	*character = '\0';
	while (USART_ISR_TXE != (UART4->ISR & USART_ISR_TXE_Msk)); //wait while TXE == 1; 
}
	


void read(char* buffer, uint8_t* pIndex, bool* newLine)
{
	uint8_t i = *(pIndex);
	*(buffer+i) =  UART4->RDR;
	i++;
	
	if ( i == BUF_CAPACITY)
	{
		UART4->CR1 &= ~(USART_CR1_RE);
	}
	if (0u != (UART4->ISR & USART_ISR_ORE_Msk) )
	{
		i = i;
	}
	*(pIndex) = i;
	*newLine = (char)*(buffer+i-1)== '\n';
}


void write_all(char* buf, uint8_t* index)
{
	char value;
	UART4->CR1 &= ~USART_CR1_RE; //Turn receiver off
	*(index) = 0;
	for (int i = 0; i<BUF_CAPACITY; i++)
	{
		value = *(buf+i);
		write(buf+i);
		if (value == '\n')
			break;
	}
	UART4->CR1 |= USART_CR1_RE; //Turn receiver back on
	
}

void delay()
{
	for (int i=0;i<100000;i++) ;
}

int main(void)
{
	memset(&buf, '\0', BUF_CAPACITY);
	//Init UART
	init();
	open();
	uint8_t index=0;
	bool isNewLineDetected = false;
	
	while(1)
	{
		if (USART_ISR_RXNE == (UART4->ISR & USART_ISR_RXNE_Msk))
		{
			read(buf, &index, &isNewLineDetected);
		}
		if (isNewLineDetected || index == BUF_CAPACITY)
		{//Send respond if new line detected or buffer is full
			  write_all(buf, &index);
				isNewLineDetected = false;
		}

	}
}