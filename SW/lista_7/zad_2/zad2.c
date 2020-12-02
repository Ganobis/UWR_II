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

const uint8_t eeprom_addr = 0xa0;

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
	int dlugosc = 0;
	uint16_t rekordy = 0;
	uint16_t ostatni_rekord = 0;
	uint16_t checksum = 0;
	uint8_t checksum_sprawdz = 0;
	uint16_t wartosc = 0;
	uint16_t dluosc = 0;
	uint16_t wyjscie[255];
	uint16_t wejscie[255];
	char flaga;
	while(1) {
		scanf("%s", bufor);
		printf("Wypisano %s\r\n", bufor);
		if(strcmp(bufor, "read") == 0){
			scanf("%"SCNx16, &adres);
			scanf("%d", &dlugosc);
			printf("Odczytano adres = %02x dlugosc = %d\n\r", adres, dlugosc);
			i2cStart();
			i2cCheck(0x08, "I2C start")
			i2cSend(eeprom_addr | ((adres & 0x100) >> 7));
			i2cCheck(0x18, "I2C EEPROM write request")
			i2cSend(adres & 0xff);
			i2cCheck(0x28, "I2C EEPROM set address")
			i2cStart();
			i2cCheck(0x10, "I2C second start")
			i2cSend(eeprom_addr | 0x1 | ((adres & 0x100) >> 7));
			i2cCheck(0x40, "I2C EEPROM read request")
			rekordy = dlugosc / 16;
			ostatni_rekord = dlugosc % 16;
			for (int8_t i = 0; i <= rekordy; i++) {
				dluosc = i == rekordy ? ostatni_rekord : 16;
				checksum = 0x00 - (dluosc + adres);
				for (uint8_t j = 0; j < dluosc; j++) {
					wartosc = j == dluosc - 1 && i == rekordy ? i2cReadNoAck() : i2cReadAck();
					checksum -= wartosc;
					wyjscie[j] = wartosc;
				}
				if(dluosc == 0)
					break;
				printf(":%02x %04x 00 ", dluosc, adres);
        for(int j = 0; j < dluosc; j++){
            printf("%02x ", wyjscie[j]);
            adres++;
        }
        printf(" %02x \r\n", (uint8_t)checksum);
			}     
			i2cStop();
			i2cCheck(0xf8, "I2C stop")
			printf(":00 0000 01 ff\r\n");
		}
		else if (strcmp(bufor, "write") == 0){
			scanf("%c", &flaga);
			printf("Rozpoczęto pisanie\r\n");
			while(1){
				scanf("%c", &flaga);
				if (flaga != ':'){
					printf("Błędny znak!\r\n");
					break;
				}
				scanf("%2x%4x%2x", (unsigned int*)(&dlugosc), (unsigned int*)(&adres), (unsigned int*)(&rekordy));
				for (int i = 0; i < dlugosc; ++i){
					scanf("%2x", (unsigned int*)(&wejscie[i]));
				}
				scanf("%2x", (unsigned int*)(&checksum));
				if (dlugosc == 0 && adres == 0 && rekordy == 1 && checksum == 0xff){
					printf("Koniec pliku dodano\r\n");
					break;
				}
				printf(":%.2x %.4x %.2x ", dlugosc, adres, rekordy);
				for (int i = 0; i < dlugosc; ++i){
					printf("%.2x ", wejscie[i]);
				}
				printf("%.2x\r\n", checksum);
				checksum_sprawdz = 0x00;
				for (int i = 0; i < dlugosc; ++i){
					checksum_sprawdz -= wejscie[i];
				}
				checksum_sprawdz -= dlugosc + adres;
				if(checksum_sprawdz != checksum){
					printf("Żle wpisana suma kontorlna podano %2x a ma być %2x\r\n", checksum, checksum_sprawdz);
					break;
				}
				i2cStart();
				i2cCheck(0x08, "I2C start")
				i2cSend(eeprom_addr | ((adres & 0x100) >> 7));
				i2cCheck(0x18, "I2C EEPROM write request");
				i2cSend(adres & 0xff);
				i2cCheck(0x28, "I2C EEPROM set address");                
				for(uint8_t i = 0; i < dlugosc; i++) {
					i2cSend(wejscie[i]);
					i2cCheck(0x28, "I2C EEPROM data transmitted");
				}
				i2cStop();
				i2cCheck(0xf8, "I2C stop");
				printf("Zapisano linie\r\n");
			}
		}
		else{
			printf("Błędna komenda\r\n");
		}
	}
}
