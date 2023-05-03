/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: EL CONSUL
 */
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "Global_Interface.h"


#define DDRA   (*(volatile u8*)0x3A)
#define PORTA  (*(volatile u8*)0x3B)
#define TCNT0  (*(volatile u8*)0x52)
#define OCR0   (*(volatile u8*)0x5C)
#define TCCR0  (*(volatile u8*)0x53)

#define TIMSK  (*(volatile u8*)0x59)

void TimerCTC_Init(void);
void LED_Toggle(void);

void (*callback_ptr)(void) = LED_Toggle;
//void callBackfn(void);

int main(void)
{
	SET_BIT(DDRA,0);
	TimerCTC_Init();
	GLobalInterruptEnable();
	while(1)
	{

	}

	return (int)0;
}

void TimerCTC_Init(void){
	// Timer0 on CTC mode
	SET_BIT(TCCR0,3);
	CLR_BIT(TCCR0,6);

	// prescaler divided by 64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);

	// Enable interrupt
	SET_BIT(TIMSK,1);

	/* Set OCR make a 2 sec */
	OCR0 = 250;
	//TCNT0 = 0;
}
void __vector_10(void)  __attribute__((signal));
void __vector_10(void){
	static u8 counter =0;
	counter++;
	if(counter == 250)
	{
		callback_ptr();
		counter =0;
	}
	else
	{
		// do nothing
	}

}
void LED_Toggle(void)
{
	PORTA ^= 1;
}
/*void callBackfn(void)
{
	callback_ptr = LED_Toggle;
}*/

