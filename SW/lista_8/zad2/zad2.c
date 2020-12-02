#include "FreeRTOS.h"
#include "task.h"

#include <avr/io.h>
#include "queue.h"

#include <stdio.h>
#include "uart.h"

/******************************************************************************
 * Private macro definitions.
 ******************************************************************************/

#define mainLED_TASK_PRIORITY   2

#define mainSERIAL_TASK_PRIORITY 1

/******************************************************************************
 * Private function prototypes.
 ******************************************************************************/

static void vBlinkLed(void* pvParameters);

static void vSerial(void* pvParameters);

/******************************************************************************
 * Public function definitions.
 ******************************************************************************/
nt main(void)
{
	// Create task.
	xTaskHandle blink_handle;
	xTaskHandle serial_handle;

	QueueHandle_t xQueue = xQueueCreate(100, sizeof(uint16_t));

	xTaskCreate
		(
		 vBlinkLed,
		 "blink",
		 configMINIMAL_STACK_SIZE,
		 (void *)xQueue,
		 mainLED_TASK_PRIORITY,
		 &blink_handle
		);

	xTaskCreate
		(
		 vSerial,
		 "serial",
		 configMINIMAL_STACK_SIZE,
		 (void *)xQueue,
		 mainSERIAL_TASK_PRIORITY,
		 &serial_handle
		);

	// Start scheduler.
	vTaskStartScheduler();

	return 0;
}

void vApplicationIdleHook(void)
{

}

/******************************************************************************
 * Private function definitions.
 ******************************************************************************/
static void vBlinkLed(void* pvParameters)
{
	QueueHandle_t xQueue = (QueueHandle_t)pvParameters;
	DDRB |= _BV(PB5);
	uint16_t value; 

	PORTB &= ~_BV(PB5);
	while(1)
	{
		if (xQueueReceive(xQueue, &value, (TickType_t)10) == pdPASS) {
			printf("Receive:%d\r\n", value);
			PORTB |= _BV(PB5);
			vTaskDelay(value / portTICK_PERIOD_MS);
			PORTB &= ~_BV(PB5);
			vTaskDelay(500 / portTICK_PERIOD_MS);
		}
	}
}

static void vSerial(void* pvParameters)
{
	uart_init();
	stdin = stdout = stderr = &uart_file;
	QueueHandle_t xQueue = (QueueHandle_t)pvParameters;
	uint16_t value;
	char input;

	while(1)
	{
		value = 0;
		input = getchar();
		while (input >= 48 && input <= 57) 
		{
			value = value * 10 + (input - 48);
			input = getchar();
		}
        xQueueSend(xQueue, (void*)&value, (TickType_t)0);
	}
}
