#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)

#define BUT PD2

//inicializacja UART
void uart_init()
{
	//ustaw baudrate
	UBRR0 = UBRR_VALUE;
	//włącz odbiornik i nadajnik
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);
	//ustaw format 8n1
	UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

//transmisja jednego znaku
int uart_transmit(char data, FILE *stream)
{
	//czekaj aż transmiter gotowy
	while(!(UCSR0A & _BV(UDRE0)));
	UDR0 = data;
	return 0;
}

//odczyt jednego znaku
int uart_receive(FILE *stream)
{
	//czekaj aż znak dostępny
	while(!(UCSR0A & _BV(RXC0)));
	return UDR0;
}

//inicjalizacja ADC
void adc_init()
{
	ADMUX = _BV(REFS0); //referencja AVcc, wejście ADC0
	DIDR0 = _BV(ADC0D); //wyłącz wejście cyfrowe na ADC0
	//częstotliwość zegara ADC 125kHz (16MHz / 128)
	ADCSRA = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); //presklaer 128
	ADCSRA |= _BV(ADEN); //wyłącz ADC
}

FILE uart_file;

volatile float opor;

void io_init()
{
	// ustaw pull-up na PD2 (INT0)
	PORTD |= _BV(BUT);
	// ustaw wyzwalanie przerwania na INT0 zboczem narastającym
	EICRA |= _BV(ISC00) | _BV(ISC01);
	// odmaskuj przerwania dla INT0
	EIMSK |= _BV(INT0);
}

ISR(INT0_vect){
	ADCSRA |= _BV(ADSC); //wykonaj konwersję
	while(ADCSRA & _BV(ADSC));
	opor = ((5.0*ADC)/(1024.0) * 10000.0)/(5-(5.0*ADC)/(1024.0));
}

int main()
{
	//zainicjalizuj UART
	uart_init();
	//sonfiguruj strumienie wejścia/wyjścia
	fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
	stdin = stdout = stderr = &uart_file;
	adc_init();
	io_init();
	float temp;
	sei();
	while(1){
		cli();
		temp = opor;
		sei();
		printf("Opor: %f\r\n",  temp);
		_delay_ms(4000);
	}
}
