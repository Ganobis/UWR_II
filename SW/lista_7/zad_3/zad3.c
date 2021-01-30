#include <avr/io.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include "i2c.h"

#define BAUD 9600                          // baudrate
#define UBRR_VALUE ((F_CPU)/16/(BAUD)-1)   // zgodnie ze wzorem

// inicjalizacja UART
void uart_init()
{
	// ustaw baudrate
	UBRR0 = UBRR_VALUE;
	// wyczyść rejestr UCSR0A
	UCSR0A = 0;
	// włącz odbiornik i nadajnik
	UCSR0B = _BV(RXEN0) | _BV(TXEN0);
	// ustaw format 8n1
	UCSR0C = _BV(UCSZ00) | _BV(UCSZ01);
}

// transmisja jednego znaku
int uart_transmit(char data, FILE *stream)
{
	// czekaj aż transmiter gotowy
	while(!(UCSR0A & _BV(UDRE0)));
	UDR0 = data;
	return 0;
}

// odczyt jednego znaku
int uart_receive(FILE *stream)
{
	// czekaj aż znak dostępny
	while (!(UCSR0A & _BV(RXC0)));
	return UDR0;
}

FILE uart_file;

const uint8_t eeprom_addr = 0xd0;

int main()
{
	// zainicjalizuj UART
	uart_init();
	// skonfiguruj strumienie wejścia/wyjścia
	fdev_setup_stream(&uart_file, uart_transmit, uart_receive, _FDEV_SETUP_RW);
	stdin = stdout = stderr = &uart_file;
	// zainicjalizuj I2C
	#define i2cCheck(code, msg) \
		if ((TWSR & 0xf8) != (code)) { \
			printf(msg " failed, status: %.2x\r\n", TWSR & 0xf8); \
			i2cReset(); \
			continue; \
		}
	i2cInit();
	char bufor[20] = {"\0\0\0\0\0\0\0\0\0\0\0"};
	uint16_t adres = 0;
	uint8_t a = 0;
	uint8_t b = 0;
	uint8_t c = 0;
	int temp;
	while(1) {
		scanf("%s", bufor);
		if(strcmp(bufor, "time") == 0){
			adres = 0x00;
			i2cStart();
			i2cCheck(0x08, "I2C start")
			i2cSend(eeprom_addr);
			i2cCheck(0x18, "I2C EEPROM write request")
			i2cSend(adres & 0xff);
			i2cCheck(0x28, "I2C EEPROM set address")
			i2cStart();
			i2cCheck(0x10, "I2C second start")
			i2cSend(eeprom_addr | 0x1);
			i2cCheck(0x40, "I2C EEPROM read request")
			a = i2cReadAck();
			b = i2cReadAck();
			c = i2cReadNoAck();
			i2cCheck(0x58, "I2C EEPROM read")
			i2cStop();
			i2cCheck(0xf8, "I2C stop")
			a = ((a & 0x0a) + ((a >> 4) * 10));
			b = ((b & 0x0a) + ((b >> 4) * 10));
			c = ((((c & 0x30) >> 4) * 10) + (c & 0x0a));
			printf("Godzina %02"PRIu8":%02"PRIu8":%02"PRIu8"\r\n", c, b, a);
		}
		else if (strcmp(bufor, "date") == 0){
			adres = 0x04;
			i2cStart();
			i2cCheck(0x08, "I2C start")
			i2cSend(eeprom_addr);
			i2cCheck(0x18, "I2C EEPROM write request")
			i2cSend(adres & 0xff);
			i2cCheck(0x28, "I2C EEPROM set address")
			i2cStart();
			i2cCheck(0x10, "I2C second start")
			i2cSend(eeprom_addr | 0x1);
			i2cCheck(0x40, "I2C EEPROM read request")
			a = i2cReadAck();
			b = i2cReadAck();
			c = i2cReadNoAck();
			i2cCheck(0x58, "I2C EEPROM read")
			i2cStop();
			i2cCheck(0xf8, "I2C stop")
			a = ((a & 0x0a) + ((a >> 4) * 10));
			b = ((b & 0x0a) + (((b & 0x10) >> 4) * 10));
			c = ((c & 0x0a) + ((c >> 4) * 10));
			printf("Data:%02"PRIu8"-%02"PRIu8"-%02"PRIu8"\r\n", a, b, c);
		}
		else if (strcmp(bufor, "set") == 0){
			scanf("%s", bufor);
			if (strcmp(bufor, "time") == 0){
				adres = 0x00;
				printf("Godzina, minuta, sekunda\r\n");
				scanf("%d", &temp);
  			a = ((temp % 10) + ((temp / 10) << 4));
  			scanf("%d", &temp);
  			b = ((temp % 10) + ((temp / 10) << 4));
  			scanf("%d", &temp);
  			c = ((temp % 10) + ((temp / 10) << 4));
  			i2cStart();
		    i2cCheck(0x08, "I2C write start")
		    i2cSend(eeprom_addr);
		    i2cCheck(0x18, "I2C EEPROM write request")
		    i2cSend(adres & 0xff);
		    i2cCheck(0x28, "I2C EEPROM set address")
		    i2cSend(c);
		    i2cSend(b);
		    i2cSend(a);
		    i2cCheck(0x28, "I2C EEPROM data transmitted")
		    i2cStop();
		    i2cCheck(0xf8, "I2C stop")
		    printf("Zapissano pomyślnie\r\n");
			}
			else if (strcmp(bufor, "date") == 0){
				printf("Dzień, miesiąc, rok\r\n");
				adres = 0x04;
				scanf("%d", &temp);
  			a = ((temp % 10) + ((temp / 10) << 4));
  			scanf("%d", &temp);
  			b = ((temp % 10) + ((temp / 10) << 4));
  			scanf("%d", &temp);
  			c = ((temp % 10) + ((temp / 10) << 4));
  			i2cStart();
		    i2cCheck(0x08, "I2C write start")
		    i2cSend(eeprom_addr);
		    i2cCheck(0x18, "I2C EEPROM write request")
		    i2cSend(adres & 0xff);
		    i2cCheck(0x28, "I2C EEPROM set address")
		    i2cSend(c);
		    i2cSend(b);
		    i2cSend(a);
		    i2cCheck(0x28, "I2C EEPROM data transmitted")
		    i2cStop();
		    i2cCheck(0xf8, "I2C stop")
		    printf("Zapissano pomyślnie\r\n");
			}
			else{	
			printf("Błędna komenda\r\n");
			}
		}
		else{
			printf("Błędna komenda\r\n");
		}
	}
}
