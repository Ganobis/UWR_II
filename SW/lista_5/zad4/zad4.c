#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

// inicjalizacja UART
void uart_init()
{
  	// ustaw baudrate
  	UBRR0 = UBRR_VALUE;
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

void timer_init() {
	TCCR1B = _BV(CS12) | _BV(CS10); //preskaler 1024
	TIMSK1 = _BV(ICIE1); //włączenie przerwań
}

volatile int czy_pobrano = 0;
volatile int war;

ISR(TIMER1_CAPT_vect) {
	if (czy_pobrano) {
    war = ICR1; //pobiera z Input Capture Register
    czy_pobrano = 0;
    war = 15625/war;
	} else {
    TCNT1 = 0; //Time counter
    czy_pobrano = 1;
	}
}

FILE uart_file;

int main()
{
  // zainicjalizuj UART
  uart_init();
  // skonfiguruj strumienie wejścia/wyjścia
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  timer_init();
  int temp;
  sei();
	set_sleep_mode(SLEEP_MODE_IDLE);
	while (1) {
    cli();
    temp = war;
    sei();
    printf("%d \r\n", temp);
		sleep_mode();
	}
}

