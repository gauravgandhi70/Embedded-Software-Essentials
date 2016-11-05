#include "MKL25Z4.h"
#include "SPI.h"

void SPI_init(void) {
	// Enable clock network to SPI0
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;// Clock get to PORT C
	SIM->SCGC4 |= SIM_SCGC4_SPI0_MASK;//Clock get to SPI0
	PTC_BASE_PTR->PDDR |= 0x10; //Set pin 4 port C i.e PCS as output direction
	PTC_BASE_PTR->PDOR |= 0x10; //Set pin 4 port C i.e PCS as output

	// configure output crossbar
	PORTC->PCR[4] = PORT_PCR_MUX(1);  // PCS
	PORTC->PCR[5] = PORT_PCR_MUX(2);  // SCK
	PORTC->PCR[6] = PORT_PCR_MUX(2);  // MOSI
	PORTC->PCR[7] = PORT_PCR_MUX(2);  // MISO

	PTC_BASE_PTR->PSOR = 1<<4;
	// configure gpio address select
	/* here */

	// Config registers, turn on SPI0 as master
	// Enable chip select
	SPI0->C1 = 0x50;// Enable SPI and set as Master
	//SPI0->C2 = 0x10;
	//SPI0->BR = 0x00;
	SPI0_BR = (SPI_BR_SPPR(0x03) | SPI_BR_SPR(0x08));     //Set baud rate prescale divisor to 3 & set baud rate divisor to 512 for baud rate of 15625 hz
}

uint8_t SPI_status(void) { //Shows the status of SPI
	return SPI0->S;
}

// Write out all characters in supplied buffer to register at address
uint8_t SPI_write(uint8_t p) {
	int i;
	// set SPI line to output (BIDROE = 1)
	//SPI0->C2 |= 0x04;

	//for (i = 0; i < size; ++i) {
		// poll until empty
		while ((SPI_status() & 0x20) != 0x20); //Check if transfer buffer is empty
		SPI0->D = p;//Send data
		while ((SPI_status() & 0x80) != 0x80); //Check if transfer is complete, hence transfer buffer empty
		return SPI0->D; //return data
	//}
}

// Read size number of characters into buffer p from register at address
  /*uint8_t SPI_read() {
	int i;
	uint8_t p;

	// set SPI line to input (BIDROE = 0)
	//SPI0->C2 &= 0xF7;
	//for (i = 0; i < size; ++i) {
		// poll until full
		//SPI0->D = 0x00;
		while ((SPI_status() & 0x80) != 0x80);
		p = SPI0->D;
		return p;*/
	//}
//}

void spi_flush() //To flush out the transmit and recieve buffers
{
	SPI0_C1&=0xBF;
	SPI_init();
}
