#include "FreeRTOS.h"
#include "task.h"
#include <avr/io.h>
#include <stdio.h>
#include "uart.h"
#include "queue.h"
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#ifndef BAUD
#define BAUD 9600
#endif
#include <util/setbaud.h>

int uart_transmit(char c, FILE *stream);
int uart_receive(FILE *stream);

FILE uart_file = FDEV_SETUP_STREAM(uart_transmit, uart_receive, _FDEV_SETUP_RW);

void uart_init() {
  bufor_in = xQueueCreate(100, sizeof(char));
  bufor_out = xQueueCreate(100, sizeof(char));

  UBRR0H = UBRRH_VALUE;
  UBRR0L = UBRRL_VALUE;
#if USE_2X
  UCSR0A |= _BV(U2X0);
#else
  UCSR0A &= ~(_BV(U2X0));
#endif
  UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */
  UCSR0B = _BV(RXEN0) | _BV(TXEN0) | _BV(RXCIE0) | _BV(UDRIE0); /* Enable RX and TX odpala również przerwania RX i UDRIE*/
}

int uart_transmit(char c, FILE *stream) {
  if (uxQueueSpacesAvailable(bufor_out) == 0) {
      while (!(UCSR0A & _BV(UDRE0)));
  }
  xQueueSendFromISR(bufor_out, (void*)&c, NULL);
  return 0;
}

int uart_receive(FILE *stream) {
  uint8_t value = 0;
  while (xQueueReceiveFromISR(bufor_in, (void*)&value, NULL) == pdFALSE){
    vTaskDelay(5 / portTICK_PERIOD_MS);
  }
  return value;

}