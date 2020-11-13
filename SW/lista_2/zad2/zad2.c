#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h> 
#include <util/delay.h>

#define BTN PB4
#define BTN_PIN PINB
#define BTN_PORT PORTB

#define LED1 PB5
#define LED2 PB3
#define LED3 PB2

#define LED_DDR DDRB
#define LED_PORT PORTB

#define BAUD 9600                          
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   

char *mors[] = {
    "0122",  
    "0111",
    "1010",
    "1002", 
    "0222",   
    "0010",
    "1102", 
    "0000",
    "0022",  
    "0111",
    "1012", 
    "0100",
    "1122",  
    "1022",  
    "1112", 
    "0110",
    "1101",
    "0102", 
    "0002", 
    "1222",   
    "0012", 
    "0001",
    "0112", 
    "1001",
    "1011",
    "1100",
};

void uart_init()
{
  UBRR0 = UBRR_VALUE;
  UCSR0A = 0;
  UCSR0B = _BV(RXEN0) | _BV(TXEN0);
  UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

int uart_transmit(char data, FILE *stream)
{
  while(!(UCSR0A & _BV(UDRE0)));
  UDR0 = data;
  return 0;
}

int uart_receive(FILE *stream)
{
  // czekaj aż znak dostępny
  while (!(UCSR0A & _BV(RXC0)));
  return UDR0;
}

FILE uart_file;

void decode(char x[]);

int main()
{
  uart_init();
  fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
  stdin = stdout = stderr = &uart_file;

  BTN_PORT |= _BV(BTN);
  LED_DDR |= _BV(LED1);
  LED_DDR |= _BV(LED2);
  LED_DDR |= _BV(LED3);

  int counter = 0;
  int val = 0;
  int space = 0;
  int pos = 0;

  char x[] = "2222";

  while(1) {
    _delay_ms(10);

    if(val > 15){
      LED_PORT |= _BV(LED1);
      if (counter == 0){
        x[pos] = '1';
        val = 0;
        pos++;
      }
    }

    if (val > 1){
      LED_PORT |= _BV(LED2);
      if (counter == 0)
      {
        x[pos] = '0';
        val = 0;
        pos++;
      }
    }

    if (BTN_PIN & _BV(BTN)){
      space++;
      if (space == 30)
      {      
        LED_PORT |= _BV(LED3);
        if (pos <= 1)
          x[1] = '2';
        if (pos <= 2)
          x[2] = '2';
        if (pos <= 3)
          x[3] = '2';
        decode(x);

      }
      counter = 0;
      LED_PORT &= ~_BV(LED1);
      LED_PORT &= ~_BV(LED2);
    }
    else{
      if(space > 30){
        pos = 0;
      }
      LED_PORT &= ~_BV(LED3);
      space = 0;
      counter++;
    if (counter % 2 == 0)
      val++;
    }
  }
}

void decode(char l[]){

  //printf("%s\n", l);
  for (int i = 0; i < 25; ++i)
  {
    if (strcmp(l, mors[i]) == 0)
    {
      //printf("%s\n", mors[i]);
      printf("%c", i+97);
    }
  }
}

/*void decode(int x[]){
  if (x[0] == 0)
  {
    if (x[1] == 0)
    {
      if (x[2] == 0)
      {
        if (x[3] == 0)
          printf("h");
        else if (x[3] == 1)
          printf("!");
        else if (x[3] == 2)
          printf("s");
      }
      else if (x[2] == 1)
      {
        if (x[3] == 0)
          printf("f");
        else if (x[3] == 1)
          printf("!");
        else if (x[3] == 2)
          printf("u");
      }
      else if(x[2] == 2)
        printf("i");
    }
    else if (x[1] == 1) 
    {
      if (x[2] == 0)
      {
        if (x[3] == 0)
          printf("l");
        else if (x[3] == 1)
          printf("!");
        else if (x[3] == 2)
          printf("r");
      }
      else if(x[2] == 1)
      {
        if (x[3] == 0)
          printf("p");
        else if (x[3] == 1)
          printf("j");
        else if (x[3] == 2)
          printf("w");
      }
      else if(x[2] == 2)
        printf("a");
    }
    else if(x[1] == 2)
      printf("e");
  }
else if (x[0] == 1)
{
  if (x[1] == 0)
    {
      if (x[2] == 0)
      {
        if (x[3] == 0)
          printf("b");
        else if (x[3] == 1)
          printf("x");
        else if (x[3] == 2)
          printf("d");
      }
      else if (x[2] == 1)
      {
        if (x[3] == 0)
          printf("c");
        else if (x[3] == 1)
          printf("y");
        else if (x[3] == 2)
          printf("k");
      }
      else if(x[2] == 2)
        printf("n");
    }
    else if (x[1] == 1) 
    {
      if (x[2] == 0)
      {
        if (x[3] == 0)
          printf("z");
        else if (x[3] == 1)
          printf("q");
        else if (x[3] == 2)
          printf("g");
      }
      else if(x[2] == 1)
      {
        if (x[3] == 0)
          printf("!");
        else if (x[3] == 1)
          printf("!");
        else if (x[3] == 2)
          printf("o");
      }
      else if(x[2] == 2)
        printf("m");
    }
    else if(x[1] == 2)
      printf("t");
  }
}
*/