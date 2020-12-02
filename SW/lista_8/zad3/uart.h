#ifndef _UART_H
#define _UART_H

#include "queue.h"

void uart_init(void);

FILE uart_file;

QueueHandle_t bufor_in;
QueueHandle_t bufor_out;

#endif
