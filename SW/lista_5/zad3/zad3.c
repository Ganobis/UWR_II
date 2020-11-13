#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <util/delay.h>

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

void io_init()
{
  // ustaw pull-up na PD2 i PD3 (INT0 i INT1)
  PORTD |= _BV(PORTD2);
  // ustaw wyzwalanie przerwania na INT0 zboczem narastającym
  EICRA |= _BV(ISC00) | _BV(ISC10) ;
  // odmaskuj przerwania dla INT0 i INT1
  EIMSK |= _BV(INT0);
}

float pomiar1[32];
volatile float pomiar2[32];
uint8_t licznik;

void wariancja() {
  float srednia = 0;
  float sum = 0;
  float tmp;
  for (uint8_t i = 0; i < 32; ++i)
  {
    srednia += pomiar1[i];
  }
  srednia /= 32.0;
  for (uint8_t i = 0; i < 32; i++) {
    tmp = pomiar1[i] - srednia;
    sum += (tmp * tmp);
  }

  printf("Wariancja bez sleep: %f\r\n", sum/32.0);
  srednia = 0;
  sum = 0;
  for (int i = 0; i < 32; ++i)
  {
    srednia += pomiar2[i];
  }
  srednia /= 32;
  for (uint8_t i = 0; i < 32; i++) {
    tmp = pomiar2[i] - srednia;
    sum += (tmp * tmp);
  }
  printf("Wariancja: %f\r\n", sum/32.0);
}

ISR(ADC_vect) {
  ADCSRA |=_BV(ADIF);
  pomiar2[licznik] = 112.53/ADC;
  licznik++;
}

int main()
{
  uart_init();
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  adc_init();
  licznik = 0;
  io_init();
  //cli();
  for (int i = 0; i < 32; ++i)
  {
    ADCSRA |= _BV(ADSC); //wykonaj konwersję
    while(ADCSRA & _BV(ADSC));
    pomiar1[i] = 112.53/ADC;
  }
  ADCSRA |=_BV(ADIE); // ADC przerwania włącz
  SMCR |= _BV(SM0) | _BV(SE); //tryb ADC można użyć set_sleep_mode
  sei();
  for (int i = 0; i < 32; ++i)
    sleep_mode();
  wariancja();
}
