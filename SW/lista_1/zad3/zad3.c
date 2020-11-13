#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR DDRD
#define LED_PORT PORTD

int main()
{
	UCSR0B &= ~_BV(RXEN0) & ~_BV(TXEN0);
	LED_DDR |= 0b11111111;
	while(1){
		LED_PORT = 0b00000001;
		for (int i = 0; i < 7; ++i)
		{
			LED_PORT = (LED_PORT << 1);
			_delay_ms(50);
		}
		for (int i = 0; i < 7; ++i)
		{
			LED_PORT = (LED_PORT >> 1);
			_delay_ms(50);
		}
	}
}