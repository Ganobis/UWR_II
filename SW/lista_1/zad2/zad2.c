#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define LED PB3
#define LED_DDR DDRB
#define LED_PORT PORTB

#define BAUD 9600
#define UBRR_VALUE ((F_CPU) / 16 / (BAUD)-1)


char *mors[] = {
    "01",  
    "0111",
    "1010",
    "100", 
    "0",   
    "0010",
    "110", 
    "0000",
    "00",  
    "0111",
    "101", 
    "0100",
    "11",  
    "10",  
    "111", 
    "0110",
    "1101",
    "010", 
    "000", 
    "1",   
    "001", 
    "0001",
    "011", 
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
    while (!(UCSR0A & _BV(UDRE0)))
        ;
    UDR0 = data;
    return 0;
}

int uart_receive(FILE *stream)
{
    while (!(UCSR0A & _BV(RXC0)))
        ;
    return UDR0;
}

FILE uart_file;


void display_char(char l)
{
    char *morse_sig = mors[l - 97];
    for (int i = 0; morse_sig[i] != '\0'; ++i)
    {
        _delay_ms(400);
        if (morse_sig[i] == '0'){
            LED_PORT |= _BV(LED);
            _delay_ms(400);
            LED_PORT &= ~_BV(LED);
        }
        else if (morse_sig[i] == '1')
        {
            LED_PORT |= _BV(LED);
            _delay_ms(1200);
            LED_PORT &= ~_BV(LED);
        }
    }
    _delay_ms(600);
}

int main(void)
{
    uart_init();
    fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
    stdin = stdout = stderr = &uart_file;
    LED_DDR |= _BV(LED);
    while (1)
    {
        char code[10];
        scanf("%s", code);
        for (int i = 0; code[i] != '\0'; i++)
            display_char(code[i]);
    }
    return 0;
}