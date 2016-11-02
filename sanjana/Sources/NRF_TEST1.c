#include "MKL25Z4.h"
#include "NRF_TEST1.h"
#include "SPI_TEST1.h"

void nrf_config_write()
{
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_write_register(NORDIC_CONFIG_REG);
	SPI_write(0x03);
	PTD_BASE_PTR->PSOR =  1<<0;
}

void nrf_config_read()
{
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;
	char c;
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_read_register(NORDIC_CONFIG_REG);
	SPI_write(0XFF);
	c=SPI_read();
	if (c==0x03)
	{
		PTB_BASE_PTR->PDDR |= 1<<18;
		PTB_BASE_PTR->PSOR = 1<<18;
	}
	PTD_BASE_PTR->PSOR = 1<<0;
}

void nrf_write_register(unsigned char address)
{
	SPI_write(0x20|address);
}

void nrf_read_register(unsigned char address)
{
	SPI_write(0x00|address);
}

void nrf_flush_tx_fifo()
{
	PTD_BASE_PTR->PCOR = 1<<0;
	SPI_write(0xE1);
	PTD_BASE_PTR->PSOR = 1<<0;
}

void nrf_flush_rx_fifo()
{
	PTD_BASE_PTR->PCOR = 1<<0;
	SPI_write(0xE2);
	PTD_BASE_PTR->PSOR = 1<<0;
}

void nrf_status_read()
{
	char c;
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_read_register(NORDIC_STATUS_REG);
	SPI_write(0xFF);
	c=SPI_read();
	PTD_BASE_PTR->PSOR = 1<<0;
}

void nrf_fifostatus_read()
{
	
	char c;
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_read_register(FIFO_STATUS_REG );
	SPI_write(0xff);
	 c=SPI_read();
	 PTD_BASE_PTR->PSOR = 1<<0;
}
