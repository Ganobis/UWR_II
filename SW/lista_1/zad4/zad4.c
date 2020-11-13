#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define LED_DDR DDRD
#define LED_PORT PORTD

#define TRN PC0
#define TRN_DDR DDRC
#define TRN_PORT PORTC

uint8_t numb[]={
	0b00111111,
	0b00000110,
	0b01011011,
	0b01001111,
	0b01100110,
	0b01101101,
	0b01111101,
	0b00000111,
	0b01111111,
	0b01101111,
	0b00000000,
};

int main() {
  UCSR0B &= ~_BV(RXEN0) & ~_BV(TXEN0);
  LED_DDR |= 0b11111111;
  TRN_DDR = _BV(TRN);

  while(1){
  	for (int i = 0; i < 10; ++i)
  	{
	  	TRN_PORT = _BV(TRN);
	  	LED_PORT = ~(numb[i%10]);
	  	TRN_PORT &= ~_BV(TRN);
		_delay_ms(1000);
  	}
  }
}

