#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <avr/pgmspace.h>
#include "nuty.h"

#define CS PB2
#define CS_PORT PORTB

// inicjalizacja SPI
void spi_init()
{
    // ustaw piny MOSI, SCK i ~SS jako wyjścia
    DDRB |= _BV(DDB3) | _BV(DDB5) | _BV(DDB2);
    // włącz SPI w trybie master z zegarem 250 kHz
    SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPR1); //SPE odpala spi, MSTR ustawia master/slave, 
}

// transfer jednego bajtu
void spi_transfer(uint8_t data)
{
    // rozpocznij transmisję
    SPDR = data; //SPDR rejestr przesówny
    // czekaj na ukończenie transmisji
    while (!(SPSR & _BV(SPIF)));  //SPIF informuje o zakończeniu transmisji
    // wyczyść flagę przerwania
    SPSR |= _BV(SPIF);
    //usuwamy return bo nic nie musimy odbierać
}

void timer1_init(){
    TCCR1B = _BV(CS10); //timer1 z preskalerem 1
}

int main() 
{
  spi_init(); // zainicjalizuj SPI
  timer1_init(); // zainicjalizuj timer
  int8_t dzwiek;
  while(1) {
    for (int i = 0; i < 2916; ++i){
      while(TCNT1 < 2000); //bo tyle cykli odpowiada do 8kHz
      TCNT1 = 0;
      CS_PORT &= ~_BV(CS);
      dzwiek = pgm_read_byte(&arr[i]);
      spi_transfer(0b00110000 | (dzwiek >> 4));
      spi_transfer(dzwiek << 4);
      CS_PORT |= _BV(CS);
    }
  }
}
