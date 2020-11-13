#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include <inttypes.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU) / 16 / (BAUD)-1)

#define BUZZ PB5
#define BUZZ_DDR DDRB
#define BUZZ_PORT PORTB

#define c 955  
#define d 851
#define e 758  
#define f 715
#define g 638
#define a 568
#define h 506
#define c2 478 
#define x 31000

#define cala 2400
#define pol 1200
#define cwiartka 600
#define osemka 300
#define szesnaska 150

void uart_init()
{
    UBRR0 = UBRR_VALUE;
    UCSR0A = 0;
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);
    UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

int uart_transmit(char data, FILE *stream)
{
    while (!(UCSR0A & _BV(UDRE0)));
    UDR0 = data;
    return 0;
}

int uart_receive(FILE *stream)
{
    while (!(UCSR0A & _BV(RXC0)));
    return UDR0;
}

FILE uart_file;

static const int muzyka_nuty[] PROGMEM={
e, x, d, e, f, e, d, c, c, x, d, e, f, f, f, f, f, e, d,d, x, d, c, d, 
e, e, x, e, f, d, c, c, x, c, a, a, x, a, h, c, h, a, g, g, x, f, e, 
f, f, x, f, g, a, g, f, e, e, c, c, a, a, x, a, h, c, h, a, g, g, f, e, 
f, f, x, d, e, f, e, d, c};

static const int muzyka_dlugosc[] PROGMEM={
pol, osemka, szesnaska, szesnaska, osemka, osemka, osemka, cwiartka, cwiartka, cwiartka, osemka, osemka, osemka, cwiartka, cwiartka, cwiartka, szesnaska, szesnaska, szesnaska, szesnaska, cwiartka, pol, cwiartka, cwiartka, cwiartka,
cwiartka, cwiartka, cwiartka, osemka, cwiartka, osemka, cwiartka, cwiartka, cwiartka, cwiartka, cwiartka, cwiartka, szesnaska, szesnaska, osemka, szesnaska, szesnaska, osemka, cwiartka, cwiartka, cwiartka, osemka, cwiartka, cwiartka,
cwiartka, cwiartka, osemka, osemka, osemka, osemka, szesnaska, szesnaska, cwiartka, cwiartka, cwiartka, cwiartka, osemka, cwiartka, cwiartka, osemka, osemka, osemka, osemka, osemka, osemka, cwiartka, pol, osemka, osemka, osemka,
cwiartka, cwiartka, osemka, osemka, osemka, osemka, osemka, osemka, pol, pol};

void my_delay_us(int us)
{
  while (0 < us)
  {  
    _delay_us(1);
    --us;
  }
}

int main() {
  uart_init();
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;
  BUZZ_DDR |= _BV(BUZZ);
  uint16_t nuta = 0;
  uint16_t dlugosc = 0;
  while (1) {
    for(int i = 0; i < 80; i++){
      nuta = pgm_read_word(&muzyka_nuty[i]);
      dlugosc = pgm_read_word(&muzyka_dlugosc[i]);
      for (uint16_t j = 0; j < (uint32_t)1000 * (dlugosc) / (nuta) / 2; j++) {
        BUZZ_PORT |= _BV(BUZZ);
        my_delay_us(nuta);
        BUZZ_PORT &= ~_BV(BUZZ);
        my_delay_us(nuta);
      }
    }
  }
}
