#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#define DEBOUNCE_TIME 300

#define BTN1 PC0
#define BTN2 PC1
#define BTN3 PC2
#define BTN_PIN PINC
#define BTN_PORT PORTC


#define LED_DDR DDRD
#define LED_PORT PORTD

void  debonce(){
  _delay_ms(DEBOUNCE_TIME);
}

void show_grey(int x){
  LED_PORT = x^(x/2);
}

int main()
{
  BTN_PORT |= _BV(BTN1);
  BTN_PORT |= _BV(BTN2);
  BTN_PORT |= _BV(BTN3);

  UCSR0B &= ~_BV(RXEN0) & ~_BV(TXEN0);
  LED_DDR |= 0b11111111;

  int acc = 0;

  show_grey(0);
  while(1){
  	if (!(BTN_PIN & _BV(BTN1))){
      debonce();
  	  acc = (acc + 1) % 256;
  	  show_grey(acc);
  	}
  	if (!(BTN_PIN & _BV(BTN2))){
      debonce();
  		acc--;
  		if (acc < 0)
    		acc = 255;
    	show_grey(acc);
  	}
  	if (!(BTN_PIN & _BV(BTN3))){
        debonce();
    		acc = 0;
    		show_grey(0);
  	}	
  }
}