#include <avr/interrupt.h>
#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

#define LA PB1
#define LA_PORT PORTB

void spi_init(){
    // ustaw piny MOSI, SCK i ~SS jako wyjścia
    DDRB |= _BV(DDB3) | _BV(DDB5) | _BV(DDB2);
    // włącz SPI w trybie master z zegarem 250 kHz
    SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPR1);  //SPE odpala spi, MSTR ustawia master/slave, 
}

// transfer jednego bajtu
void spi_transfer(uint8_t data){
    // rozpocznij transmisję
    SPDR = data;
    // czekaj na ukończenie transmisji
    while (!(SPSR & _BV(SPIF)));
    // wyczyść flagę przerwania
    SPSR |= _BV(SPIF);
}

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
  0b01101111
};


int main(){
  spi_init();
  uint8_t i=0;
  while(1) {
    LA_PORT |= _BV(LA);
    spi_transfer(numb[i]);
    LA_PORT &= ~_BV(LA);
    i = (i + 1)%10;
    _delay_ms(1000);
  }
}