/******************************************************************************
 * Header file inclusions.
 ******************************************************************************/

#include "FreeRTOS.h"
#include "task.h"

#include <avr/io.h>
#include "queue.h"
#include <avr/interrupt.h>
#include <stdio.h>
#include "uart.h"

/******************************************************************************
 * Private macro definitions.
 ******************************************************************************/

#define mainLED_TASK_PRIORITY   1

#define mainSERIAL_TASK_PRIORITY 2

/******************************************************************************
 * Private function prototypes.
 ******************************************************************************/

static void vBlinkLed(void* pvParameters);

static void vSerial(void* pvParameters);


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
    // Create task.
    xTaskHandle blink_handle;
    xTaskHandle serial_handle;

    xTaskCreate
        (
         vBlinkLed,
         "blink",
         configMINIMAL_STACK_SIZE,
         NULL,
         mainLED_TASK_PRIORITY,
         &blink_handle
        );

    xTaskCreate
        (
         vSerial,
         "serial",
         configMINIMAL_STACK_SIZE,
         NULL,
         mainSERIAL_TASK_PRIORITY,
         &serial_handle
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

/**************************************************************************//**
 * \fn static void vBlinkLed(void* pvParameters)
 *
 * \brief
 *
 * \param[in]   pvParameters
 ******************************************************************************/
static void vBlinkLed(void* pvParameters)
{
    DDRB |= _BV(PB5);

    while(1)
    {
        PORTB ^= _BV(PB5);
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}


/**************************************************************************//**
 * \fn static void vSerial(void* pvParameters)
 *
 * \brief
 *
 * \param[in]   pvParameters
 ******************************************************************************/
static void vSerial(void* pvParameters)
{
    uart_init();
    stdin = stdout = stderr = &uart_file;

    char input;

    while(1)
    {
        puts("Hello World\r\n");
        input = getchar();
        printf("You wrote %c\r\n", input); 
    }
}

ISR(USART_UDRE_vect) {
    if (xQueueIsQueueEmptyFromISR(bufor_out) == pdFALSE)
        xQueueReceiveFromISR(bufor_out, (void*)&UDR0, NULL);
}

ISR(USART_RX_vect) {
    uint8_t value = UDR0;
    xQueueSendFromISR(bufor_in, (void*)&value, NULL);
}