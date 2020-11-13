#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <util/delay.h>

#define LED PD3
#define LED_PORT PORTD

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

void my_delay_us(int us)
{
  while (0 < us)
  {  
    _delay_us(1);
    --us;
  }
}

int main()
{
	DDRD |= _BV(LED);
	adc_init();

	uint16_t znaczace_bity;
	uint16_t mniejsze_bity;
	uint16_t wynik;
	uint16_t czas;
	while(1){
		LED_PORT &= ~_BV(LED);
		my_delay_us(300);
		ADCSRA |= _BV(ADSC); //wykonaj konwersję
		while(ADCSRA & _BV(ADSC));
		wynik = ADC; //weź zmierzoną wartość (0..1023)
		mniejsze_bity = wynik >> 2;
		mniejsze_bity &= 0b1111;
		znaczace_bity = wynik >> 6; 
		czas = 0b1 << znaczace_bity;
		czas += mniejsze_bity/16;
		if (czas > 30000)
			czas = 30000;
		LED_PORT |= _BV(LED);
		my_delay_us(czas);
	}
}
