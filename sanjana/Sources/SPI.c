#include "MKL25Z4.h"
#include "SPI.h"

void SPI_init(void) {
	// Enable clock network to SPI0
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	SIM->SCGC4 |= SIM_SCGC4_SPI0_MASK;
	PTC_BASE_PTR->PDDR |= 0x01;
	
	// configure output crossbar
	PORTC->PCR[4] = PORT_PCR_MUX(1);  // PCS
	PORTC->PCR[5] = PORT_PCR_MUX(2);  // SCK
	PORTC->PCR[6] = PORT_PCR_MUX(2);  // MOSI
	PORTC->PCR[7] = PORT_PCR_MUX(2);  // MISO
	
	// configure gpio address select
	/* here */
	
	// Config registers, turn on SPI0 as master
	// Enable chip select
	SPI0->C1 = 0x52;
	//SPI0->C2 = 0x10;
	//SPI0->BR = 0x00;
	SPI0_BR = (SPI_BR_SPPR(0x02) | SPI_BR_SPR(0x08));     //Set baud rate prescale divisor to 3 & set baud rate divisor to 64 for baud rate of 15625 hz
}

uint8_t SPI_status(void) {
	return SPI0->S;
}

// Write out all characters in supplied buffer to register at address
void SPI_write(uint8_t p) {
	int i;
	// set SPI line to output (BIDROE = 1)
	//SPI0->C2 |= 0x04;
	
	//for (i = 0; i < size; ++i) {
		// poll until empty
		while ((SPI_status() & 0x20) != 0x20);
		SPI0->D = p;
	//}
}

// Read size number of characters into buffer p from register at address
  uint8_t SPI_read() {
	int i;
	uint8_t p;

	// set SPI line to input (BIDROE = 0)
	//SPI0->C2 &= 0xF7;
	//for (i = 0; i < size; ++i) {
		// poll until full
		//SPI0->D = 0x00;
		while ((SPI_status() & 0x80) != 0x80);
		p = SPI0->D;
		return p;
	//}
}

void spi_flush()
{
	SPI0_C1&=0xBF;
	SPI_init();
}
