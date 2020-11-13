#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <util/delay.h>

#define LED PB1

//inicjalizacja ADC
void adc_init()
{
	ADMUX = _BV(REFS0); //referencja AVcc, wejście ADC0
	DIDR0 = _BV(ADC0D); //wyłącz wejście cyfrowe na ADC0
	//częstotliwość zegara ADC 125kHz (16MHz / 128)
	ADCSRA = _BV(ADPS0) | _BV(ADPS1) | _BV(ADPS2); //presklaer 128
	ADCSRA |= _BV(ADEN); //wyłącz ADC
}

void timer1_init()
{
  // ustaw tryb licznika
  // COM1A = 10   -- non-inverting mode
  // WGM1  = 1110 -- fast PWM top=ICR1
  // CS10   = 101  -- prescaler 1
  // ICR1  = 15624   15369/256
  // częstotliwość 16e6/(1024*(1+15624)) = 1 Hz
  // wzór: datasheet 20.12.3 str. 164
  ICR1 = 1023;
  TCCR1A = _BV(COM1A1) | _BV(WGM11);
  TCCR1B = _BV(WGM12) | _BV(WGM13) | _BV(CS10);
  // ustaw pin OC1A (PB1) jako wyjście
  DDRB |= _BV(LED);
}

int main()
{
	adc_init();
	timer1_init();
	int znaczace_bity = 0;
	while(1){
		ADCSRA |= _BV(ADSC); //wykonaj konwersję
		while(ADCSRA & _BV(ADSC));
		znaczace_bity = ADC >> 6;
		znaczace_bity = 0b1 << znaczace_bity;
	    OCR1A = znaczace_bity;
	}  
}