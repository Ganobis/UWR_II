#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>
#include <stdio.h>

#define LED PB5
#define LED_DDR DDRD
#define LED_PORT PORTB

#define BTN PD2
#define BTN_PIN PIND
#define BTN_PORT PORTD


void timer2_init()
{
  TCCR2B = _BV(CS20) | _BV(CS21) | _BV(CS22);
  TIMSK2 |= _BV(TOIE2); //overflow interup enable
  OCR2B = 156;
  TCNT2 = 0;
}

volatile int bufor[101];
volatile int licznik;

// procedura obsługi przerwania przepełnienia licznika
ISR(TIMER2_OVF_vect) {
    if (bufor[licznik])
    LED_PORT |= _BV(LED);
  else
    LED_PORT &= ~_BV(LED);

  if (BTN_PIN & _BV(BTN)){
    bufor[licznik] = 0;
  }
  else
    bufor[licznik] = 1;

  licznik = ((licznik + 1) % 100);
}

int main()
{
  for (int i = 0; i < 101; ++i)
  bufor[i] = 0;
  licznik = 0;
  BTN_PORT |= _BV(BTN);
  LED_DDR |= _BV(LED);
  timer2_init();
  set_sleep_mode(SLEEP_MODE_PWR_SAVE);
  sei();
  while(1) {
    sleep_mode();
  }
}
