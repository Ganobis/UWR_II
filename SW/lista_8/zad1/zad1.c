/******************************************************************************
 * Header file inclusions.
 ******************************************************************************/

#include "FreeRTOS.h"
#include "task.h"

#include <avr/io.h>


#include <stdio.h>
#include "uart.h"

#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB

#define BTN PB4
#define BTN_PIN PINB
#define BTN_PORT PORTB

#define LED_DDR_D DDRD
#define LED_PORT_D PORTD

/******************************************************************************
 * Private macro definitions.
 ******************************************************************************/

#define mainSEKUNDA_TASK_PRIORITY   2

#define mainDRABINKA_TASK_PRIORITY 1

/******************************************************************************
 * Private function prototypes.
 ******************************************************************************/

static void vSekunda(void* pvParameters);

static void vDrabinka(void* pvParameters);

int press_memory[101];
int counter;

/******************************************************************************
 * Public function definitions.
 ******************************************************************************/

/**************************************************************************//**
 * \fn int main(void)
 *
 * \brief Main function.
 *
 * \return
 ******************************************************************************/
int main(void)
{
	for (int i = 0; i < 101; ++i)
	{
			press_memory[i] = 0;
	}
	// Create task.
	xTaskHandle sekunda_handle;
	xTaskHandle drabinka_handle;
		xTaskCreate
			(
			 vSekunda,
			 "sekunda",
			 configMINIMAL_STACK_SIZE,
			 NULL,
			 mainSEKUNDA_TASK_PRIORITY,
			 &sekunda_handle
			);
		xTaskCreate
			(
			 vDrabinka,
			 "drabinka",
			 configMINIMAL_STACK_SIZE,
			 NULL,
			 mainDRABINKA_TASK_PRIORITY,
			 &drabinka_handle
			);
		// Start scheduler.
	vTaskStartScheduler();
		return 0;
}

/**************************************************************************//**
 * \fn static vApplicationIdleHook(void)
 *
 * \brief
 ******************************************************************************/
void vApplicationIdleHook(void)
{

}

/******************************************************************************
 * Private function definitions.
 ******************************************************************************/

static void vSekunda(void* pvParameters)
{
	BTN_PORT |= _BV(BTN);
	LED_DDR |= _BV(LED);
	while(1)
	{
		if (BTN_PIN & _BV(BTN))
			press_memory[counter] = 1;
		else
			press_memory[counter] = 0;
		if (press_memory[(counter + 1) % 101])
			LED_PORT &= ~_BV(LED);
		else
			LED_PORT |= _BV(LED);
		vTaskDelay(10 / portTICK_PERIOD_MS);
		counter++;
		if (counter >= 101)
		 counter = 0;
			vTaskDelay(10 / portTICK_PERIOD_MS);
	}
}


static void vDrabinka(void* pvParameters)
{
	UCSR0B &= ~_BV(RXEN0) & ~_BV(TXEN0);
	LED_DDR_D |= 0b11111111;
	while(1){
		LED_PORT_D = 0b00000001;
		for (int i = 0; i < 7; ++i)
		{
			LED_PORT_D = (LED_PORT_D << 1);
			vTaskDelay(50 / portTICK_PERIOD_MS);
		}
		for (int i = 0; i < 7; ++i)
		{
			LED_PORT_D = (LED_PORT_D >> 1);
			vTaskDelay(50 / portTICK_PERIOD_MS);
		}
	}
}
