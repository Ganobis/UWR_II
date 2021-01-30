#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "semphr.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#include <stdio.h>
#include "uart.h"

#define mainSERIAL_TASK_PRIORITY 1


static void vSerial(void* pvParameters);


SemaphoreHandle_t adc_mutex, vserial_mutex;

void adc_init();

uint16_t readADC(uint8_t mux);

int main(void)
{
    adc_init();
    sei();
    uart_init();
    stdin = stdout = stderr = &uart_file;

    xTaskHandle adc0_handle;
    xTaskHandle adc1_handle;
    xTaskHandle adc2_handle;
    adc_mutex = xSemaphoreCreateMutex();
    vserial_mutex = xSemaphoreCreateMutex();


    xTaskCreate
        (
         vSerial,
         "adc0",
         configMINIMAL_STACK_SIZE,
         0,
         mainSERIAL_TASK_PRIORITY,
         &adc0_handle
        );

    xTaskCreate
        (
         vSerial,
         "adc1",
         configMINIMAL_STACK_SIZE,
         1,
         mainSERIAL_TASK_PRIORITY,
         &adc1_handle
        );

    xTaskCreate
        (
         vSerial,
         "adc2",
         configMINIMAL_STACK_SIZE,
         2,
         mainSERIAL_TASK_PRIORITY,
         &adc2_handle
        );

    // Start scheduler.
    vTaskStartScheduler();

    return 0;
}

void vApplicationIdleHook(void)
{

}


static void vSerial(void* pvParameters)
{
    uint8_t id = (uint8_t)pvParameters;
    vTaskDelay((1000*id) / portTICK_PERIOD_MS);

    while (1) {
        xSemaphoreTake(vserial_mutex, portMAX_DELAY);
        printf("Urzadzenie nr %"PRIu8":%d\r\n", id, readADC(id));   
        xSemaphoreGive(vserial_mutex);
        vTaskDelay(2500 / portTICK_PERIOD_MS);
    }
}

void adc_init() {
    ADMUX = _BV(REFS0);  //referencja AVcc, wejście ADC0
    DIDR0 = _BV(ADC0D) | _BV(ADC1D) | _BV(ADC2D); //wyłącz wejście cyfrowe na ADC0-ADC2
    ADCSRA = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); //presklaer 128
    ADCSRA |= _BV(ADEN) | _BV(ADIE); //ADIE - odpala przerwania, ADEN włącza adc
}

uint16_t readADC(uint8_t mux) {
    ADMUX = _BV(REFS0) | mux;
    ADCSRA |= _BV(ADSC);
    xSemaphoreTake(adc_mutex, portMAX_DELAY); //zamiast while
    uint16_t result = ADC;
    return result;
}

ISR(ADC_vect) {
    xSemaphoreGiveFromISR(adc_mutex, NULL);
}

ISR(USART_UDRE_vect) {
    if (xQueueIsQueueEmptyFromISR(bufor_out) == pdFALSE)
        xQueueReceiveFromISR(bufor_out, (void*)&UDR0, NULL);
}

ISR(USART_RX_vect) {
    uint8_t value = UDR0;
    xQueueSendFromISR(bufor_in, (void*)&value, NULL);
}