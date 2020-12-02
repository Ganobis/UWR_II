#include <avr/interrupt.h>
#include <avr/sleep.h>

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

// inicjalizacja UART
void uart_init()
{
  UBRR0 = UBRR_VALUE; //ustaw zegar
  UCSR0B = 0; //wyczyść UCRS0B
  // włącz odbiornik(RXEN0), nadajnik (TXEN0) i przerwania (TXCIE0) oraz (RXCIE0)
  UCSR0B = _BV(RXEN0) | _BV(TXEN0) | _BV(TXCIE0) | _BV(RXCIE0);
  // ustaw format 8n1
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}


volatile int data;

// transmisja
ISR(USART_TX_vect){
  //UCSR0B &= ~_BV(TXCIE0); //wyłącza przerwanie transmisji
  //UCSR0B |= _BV(RXCIE0); //włącza przerwanie odczytu
}

// odczyt
ISR(USART_RX_vect){
  //UCSR0B &= ~_BV(RXCIE0); //wyłącza przerwanie czytania
  //UCSR0B |= _BV(TXCIE0); //włącza przerwanie transmisje 
  data=UDR0; //UDR0 = USART I/O Data Register
  UDR0=data;
}

int main(){
  uart_init();
  sei(); //obsługga przerwań
  set_sleep_mode(SLEEP_MODE_IDLE); //sleep mode idle
  while(1) {
    sleep_mode();
  }
}
