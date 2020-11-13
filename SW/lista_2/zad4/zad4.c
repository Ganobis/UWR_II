#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

#define LED_DDR DDRD
#define LED_PORT PORTD

#define TRN1 PC0
#define	TRN2 PC1
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
  TRN_DDR = 0b11111111;

  while(1){
  	for (uint8_t i = 0; i < 60; i++)
  	{
  		for (uint8_t j = 0; j <= 250; ++j)
  		{
  			TRN_PORT = _BV(TRN1);
  			LED_PORT = ~(numb[i%10]);

  			_delay_ms(2);

  			TRN_PORT = _BV(TRN2);
  			LED_PORT = ~(numb[i/10]);
  			_delay_ms(2);
  		}
  	}
  }
}