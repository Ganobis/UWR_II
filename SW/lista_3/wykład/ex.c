#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)

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

int main()
{
	//zainicjalizuj UART
	uart_init();
	//sonfiguruj strumienie wejścia/wyjścia
	fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
	stdin = stdout = stderr = &uart_file;
	//zainicjalizuj ADC
	adc_init();
	//mierz napięcie
	while(1){
		ADCSRA |= _BV(ADSC); //wykonaj konwersję
		// 1 //while(!(ADCSRA & _BV(ADIF))); //czekaj na wynik
		// 1 //ADCSRA |= _BV(ADIF); //wyczyść bit ADIF (pisząc 1!)
		while(ADCSRA & _BV(ADSC));
		uint16_t v = ADC; //weź zmierzoną wartość (0..1023)
		printf("Odczytano: %"PRIu16"\r\n", v);
	}
}