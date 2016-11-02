#include "MKL25Z4.h"
#include "NRF.h"
#include "SPI.h"
#include "led.h"

void nrf_config_write()
{
	PTC_BASE_PTR->PCOR = 1<<4; //Chip select low
	//PTC->PCOR=
	nrf_write_register(NORDIC_CONFIG_REG); //write command to Config register
	SPI_write(0x03);//Write data to Config register
	PTC_BASE_PTR->PSOR =  1<<4; //Chip select high
}

void nrf_config_read()
{
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK; //enable clock to port B
	char c;
	PTC_BASE_PTR->PCOR = 1<<4; //Chip select low
	nrf_read_register(NORDIC_CONFIG_REG); // read command to Config register
	c=SPI_write(0XFF);//Send dummy value to recieve data
	//c=SPI_read();
	if (c==0x03) //if data recieved is data sent, glow RED LED
	{   LED_Init();
	    LEDFunction(RED, 500);
	   /* PTB_BASE_PTR->PDOR |= 1<<18;
		PTB_BASE_PTR->PDDR |= 1<<18;
		PTB_BASE_PTR->PSOR = 1<<18;*/
	}
	PTC_BASE_PTR->PSOR = 1<<4; //Chip select high
}

void nrf_write_register(unsigned char address)
{
	SPI_write(0x20|address); //write command
}

void nrf_read_register(unsigned char address)
{
	SPI_write(0x00|address);//read command
}

/*void nrf_flush_tx_fifo()
{
	PTC_BASE_PTR->PCOR = 1<<4;
	SPI_write(0xE1);
	PTC_BASE_PTR->PSOR = 1<<4;
}

void nrf_flush_rx_fifo()
{
	PTC_BASE_PTR->PCOR = 1<<4;
	SPI_write(0xE2);
	PTC_BASE_PTR->PSOR = 1<<4;
}

void nrf_status_read()
{
	char c;
	PTC_BASE_PTR->PCOR = 1<<4;
	nrf_read_register(NORDIC_STATUS_REG);
	SPI_write(0xFF);
	c=SPI_read();
	PTC_BASE_PTR->PSOR = 1<<4;
}

void nrf_fifostatus_read()
{

	char c;
	PTC_BASE_PTR->PCOR = 1<<4;
	nrf_read_register(FIFO_STATUS_REG );
	SPI_write(0xff);
	 c=SPI_read();
	 PTC_BASE_PTR->PSOR = 1<<4;
}*/
