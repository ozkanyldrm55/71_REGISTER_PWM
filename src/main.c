
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

void RCC_Config()
{
	RCC ->CR |= 0x00010000; 		// HSEON enable
	while(!(RCC ->CR & 0x00020000));//HSEON Ready Flag wait
	RCC ->CR |= 0x00080000;  		//CSS Enable
	RCC ->CR |= 0x01000000;			//PLL ON
	RCC ->PLLCFGR |= 0x00400000; 	//PLL e HSE sectik
	RCC ->PLLCFGR |= 0x00000004; 	//PLL M = 4
	RCC ->PLLCFGR |= 0x00005A00;	//PLL N = 168
	RCC ->PLLCFGR |= 0x00000000; 	//PLL P = 2
	RCC ->CFGR |= 0x00000000;		//AHB Prescaler = 1
	RCC ->CFGR |= 0x00080000;		//APB2 Prescaler = 2
	RCC ->CFGR |= 0x00001400;		//APB1 Prescaler = 4
	RCC ->CIR |= 0x00080000;		//HSERDY Flah Clear
	RCC ->CIR |= 0x00800000;		//CSS Flag Clear

	RCC ->AHB1ENR = 0x00000009; //GPIOA ve GPIOD Aktif

	GPIOD ->MODER = 0x55000000; // 12 13, 14 ,15 yani ledlerin bulundugu pinler dijital outputs
	GPIOD ->OTYPER = 0x00000000; // 12 , 13 , 14 , 15 pins Push Pull
	GPIOD ->OSPEEDR = 0xFF000000; // 12 , 13 , 14 , 15 pins 100MHz
	GPIOD ->PUPDR = 0x00000000; //12 , 13 , 14 , 15 pins NO PULL

}

void GPIO_Config()
{
	RCC->AHB1ENR |= 1 <<3;

	GPIOD -> MODER |= 2 << 24 | 2 << 26 | 2 << 28 | 2 << 30; // PORTD -> Pin 12 | 13 | 14 | 15 AF olarak tanimladik
	GPIOD ->AFR[1] |= 2 << 16 | 2 << 20 | 2 << 24 | 2 << 28; // PORTD -> Pin 12 | 13 | 14 | 15 TIM4 olarak tanimladik
}

void TIM_Config()
{
	RCC -> APB1ENR |= 1 << 2;	// Tim4 clock enable

	TIM4 ->CR1 |= 0 << 4;		// Timer counter mode upcounter
 	TIM4 ->CR1 |= 0 << 4;		// Timer center-aligned mode edge-aligned mode
	TIM4 ->CR1 |= 0 << 8;		// Timer clock div 1
	TIM4 ->CCMR1 |= 0 << 0 | 6 << 4 | 0 << 8 | 6 << 12;
	/*
	 * Capture/Compare 1 & 2 output selected
	 * Capture/Compare 1 & 2 PWM1 selected
	 */
	TIM4 ->CCMR2 |= 0 << 0 | 6 << 4 | 0 << 8 | 6 << 12;
	/*
	 * Capture/Compare 3 & 4 output selected
	 * Capture/Compare 3 & 4 PWM1 selected
	 */

}

int main(void)
{
  while (1)
  {

  }
}





void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
