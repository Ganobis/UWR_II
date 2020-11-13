#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h> 

#define LED PB5
#define LED_DDR DDRB
#define LED_PORT PORTB

#define BTN PB4
#define BTN_PIN PINB
#define BTN_PORT PORTB

int main() {
  BTN_PORT |= _BV(BTN);
  LED_DDR |= _BV(LED);

  bool press_memory[101];
  int counter = 0;

  for (int i = 0; i < 101; ++i)
  {
  	press_memory[i] = false;
  }

  while (1) {
    if (BTN_PIN & _BV(BTN))
    	press_memory[counter] = true;
    else
    	press_memory[counter] = false;
    if (press_memory[(counter + 1) % 101])
      LED_PORT &= ~_BV(LED);
    else
      LED_PORT |= _BV(LED);
    _delay_ms(10);
  	counter++;
    if (counter >= 101)
	   counter = 0;
  }
}

