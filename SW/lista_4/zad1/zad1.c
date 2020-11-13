
#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <util/delay.h>

#define BAUD 9600
#define UBRR_VALUE ((F_CPU) / 16 / (BAUD)-1)


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

void timer1_init(){
    // ustaw tryb licznika
    // WGM1  = 0000 -- normal
    // CS1   = 001  -- prescaler 1
    TCCR1B = _BV(CS10);
}

FILE uart_file;

int main(void)
{
    uart_init();
    fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
    stdin = stdout = stderr = &uart_file;
    timer1_init();
    volatile uint8_t i8_1, i8_2, i8_3;
    volatile uint16_t i16_1, i16_2, i16_3;
    volatile uint32_t i32_1, i32_2, i32_3;
    volatile uint64_t i64_1, i64_2, i64_3;
    volatile float f_1, f_2, f_3;
    uint16_t czas_01, czas_02, czas_1, czas_2, czas_3, czas_4;
    while(1){
        czas_01 = TCNT1;
        i8_3 = i8_1 + i8_2;
        czas_02 = TCNT1;
        czas_1 = czas_02 - czas_01;
        czas_01 = TCNT1;
        i8_3 = i8_1 - i8_2;
        czas_02 = TCNT1;
        czas_2 = czas_02 - czas_01;
        czas_01 = TCNT1;
        i8_3 = i8_1 * i8_2;
        czas_02 = TCNT1;
        czas_3 = czas_02 - czas_01;
        czas_01 = TCNT1;
        i8_3 = i8_1 / i8_2;
        czas_02 = TCNT1;
        czas_4 = czas_02 - czas_01;
        printf("W uint8_t czas dla \"+\"=%d, dla \"-\"=%d, dla \"*\"=%d, dla \"/\"=%d\r\n", czas_1, czas_2, czas_3, czas_4);
        czas_01 = TCNT1;
        i16_3 = i16_1 + i16_2;
        czas_02 = TCNT1;
        czas_1 = czas_02 - czas_01;
        czas_01 = TCNT1;
        i16_3 = i16_1 - i16_2;
        czas_02 = TCNT1;
        czas_2 = czas_02 - czas_01;
        czas_01 = TCNT1;
        i16_3 = i16_1 * i16_2;
        czas_02 = TCNT1;
        czas_3 = czas_02 - czas_01;
        czas_01 = TCNT1;
        i16_3 = i16_1 / i16_2;
        czas_02 = TCNT1;
        czas_4 = czas_02 - czas_01;
        printf("W uint16_t czas dla \"+\"=%d, dla \"-\"=%d, dla \"*\"=%d, dla \"/\"=%d\r\n", czas_1, czas_2, czas_3, czas_4);
        czas_01 = TCNT1;
        i32_3 = i32_1 + i32_2;
        czas_02 = TCNT1;
        czas_1 = czas_02 - czas_01;
        czas_01 = TCNT1;
        i32_3 = i32_1 - i32_2;
        czas_02 = TCNT1;
        czas_2 = czas_02 - czas_01;
        czas_01 = TCNT1;
        i32_3 = i32_1 * i32_2;
        czas_02 = TCNT1;
        czas_3 = czas_02 - czas_01;
        czas_01 = TCNT1;
        i32_3 = i32_1 / i32_2;
        czas_02 = TCNT1;
        czas_4 = czas_02 - czas_01;
        printf("W uint32_t czas dla \"+\"=%d, dla \"-\"=%d, dla \"*\"=%d, dla \"/\"=%d\r\n", czas_1, czas_2, czas_3, czas_4);
        czas_01 = TCNT1;
        i64_3 = i64_1 + i64_2;
        czas_02 = TCNT1;
        czas_1 = czas_02 - czas_01;
        czas_01 = TCNT1;
        i64_3 = i64_1 - i64_2;
        czas_02 = TCNT1;
        czas_2 = czas_02 - czas_01;
        czas_01 = TCNT1;
        i64_3 = i64_1 * i64_2;
        czas_02 = TCNT1;
        czas_3 = czas_02 - czas_01;
        czas_01 = TCNT1;
        i64_3 = i64_1 / i64_2;
        czas_02 = TCNT1;
        czas_4 = czas_02 - czas_01;
        printf("W uint64_t czas dla \"+\"=%d, dla \"-\"=%d, dla \"*\"=%d, dla \"/\"=%d\r\n", czas_1, czas_2, czas_3, czas_4);
        czas_01 = TCNT1;
        f_3 = f_1 + f_2;
        czas_02 = TCNT1;
        czas_1 = czas_02 - czas_01;
        czas_01 = TCNT1;
        f_3 = f_1 - f_2;
        czas_02 = TCNT1;
        czas_2 = czas_02 - czas_01;
        czas_01 = TCNT1;
        f_3 = f_1 * f_2;
        czas_02 = TCNT1;
        czas_3 = czas_02 - czas_01;
        czas_01 = TCNT1;
        f_3 = f_1 / f_2;
        czas_02 = TCNT1;
        czas_4 = czas_02 - czas_01;
        printf("W float czas dla \"+\"=%d, dla \"-\"=%d, dla \"*\"=%d, dla \"/\"=%d\r\n", czas_1, czas_2, czas_3, czas_4);
        _delay_ms(6000);
    }
}