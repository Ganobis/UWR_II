#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

// inicjalizacja UART
void uart_init()
{
  // ustaw baudrate
  UBRR0 = UBRR_VALUE;
  // wyczyść rejestr UCSR0A
  UCSR0A = 0;
  // włącz odbiornik i nadajnik
  UCSR0B = _BV(RXEN0) | _BV(TXEN0);
  // ustaw format 8n1
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

// transmisja jednego znaku
int uart_transmit(char data, FILE *stream)
{
  // czekaj aż transmiter gotowy
  while(!(UCSR0A & _BV(UDRE0)));
  UDR0 = data;
  return 0;
}

// odczyt jednego znaku
int uart_receive(FILE *stream)
{
  // czekaj aż znak dostępny
  while (!(UCSR0A & _BV(RXC0)));
  return UDR0;
}

FILE uart_file;


int main() {
	uart_init();
	// skonfiguruj strumienie wejścia/wyjścia
	fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  	stdin = stdout = stderr = &uart_file;

	int8_t int8_1, int8_2;
	int16_t int16_1, int16_2;
	int32_t int32_1, int32_2;
	int64_t int64_1, int64_2;
	float float_1, float_2;

	scanf("%"SCNd64, &int64_1);
	scanf("%"SCNd64, &int64_2);
	scanf("%"SCNd8, &int8_1);
	scanf("%"SCNd8, &int8_2);
	scanf("%"SCNd16, &int16_1);
	scanf("%"SCNd16, &int16_2);	
	scanf("%"SCNd32, &int32_1);
	scanf("%"SCNd32, &int32_2);
	scanf("%f", &float_1);
	scanf("%f", &float_2);

	printf("\n %"PRId8", %"PRId8", %"PRId8"", int8_1+int8_2, int8_1*int8_2, int8_1/int8_2);
	printf("\n %"PRId16", %"PRId16", %"PRId16"", int16_1+int16_2, int16_1*int16_2, int16_1/int16_2);
	printf("\n %"PRId32", %"PRId32", %"PRId32"", int32_1+int32_2, int32_1*int32_2, int32_1/int32_2);
	printf("\n %"PRId64", %"PRId64", %"PRId64"", int64_1+int64_2, int64_1*int64_2, int64_1/int64_2);
	printf("\n %f, %f, %f", float_1+float_2, float_1*float_2, float_1/float_2);
}