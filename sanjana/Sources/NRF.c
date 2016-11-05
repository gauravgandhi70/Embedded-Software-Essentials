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

void nrf_flush_tx_fifo()
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
}

void nrf_transmit_data() //send data to nrf buffer
{
	PTD_BASE_PTR->PCOR = 1<<0;
	SPI_write(W_TXPAYLOAD);
	SPI_write(0x10);
	PTD_BASE_PTR->PSOR = 1<<0;
}
 
void nrf_read_data() //receive data from nrf buffer
{
	char c;
	PTD_BASE_PTR->PCOR = 1<<0;
	SPI_write(R_RXPAYLOAD);
	SPI_write(0xff);
	c=SPI_read();
	PTD_BASE_PTR->PSOR = 1<<0;

	nrf_fifostatus_read();

	if (c==0x07) //poll for data 07 from the tx
	{
		PTB_BASE_PTR->PDDR |= 1<<18;

	}
}

void nrf_rfsetup_transmit() //setup the rf register
{
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_write_register(NORDIC_RF_SETUP_REG);
	SPI_write(0x84);
	PTD_BASE_PTR->PSOR = 1<<0;
}

void nrf_rfsetup_receive() //read the rf register
{
	char c;
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_write_register(NORDIC_RF_SETUP_REG);
	SPI_write(0xff);
	 c=SPI_read();
	PTD_BASE_PTR->PSOR = 1<<0;

}

void nrf_tx_addr_read() //read the tx address register
{
	int i;
	char c;
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_read_register(TX_ADDR);
	 for(i=0;i<5;i++)
	 {

		 SPI_write(0xff);
		 c=SPI_read();
	 }
	PTD_BASE_PTR->PSOR = 1<<0;
}

void nrf_tx_addr_write() //write the tx address register
{
	int i;
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_write_register(TX_ADDR);
	 for(i=0;i<5;i++)
	 {
		 SPI_write(0xBB);
	 }
	 PTD_BASE_PTR->PSOR = 1<<0;
}

void nrf_rx_addr_read() //read the rx address register
{
	int i;
	char c;
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_read_register(RX_ADDR_P0_REG);
	 for(i=0;i<5;i++)
	 {
		 SPI_write(0xff);
		 c=SPI_read();
	 }
	PTD_BASE_PTR->PSOR = 1<<0;
}

void nrf_rx_addr_write() //write the rx address register
{
	int i;
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_write_register(RX_ADDR_P0_REG);
	 for(i=0;i<5;i++)
	 {
		 SPI_write(0xE7);
	 }
	 PTD_BASE_PTR->PSOR = 1<<0;
}

void nrf_en_rxaddr_write() //write to the datapipe register
{
	int i;
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_write_register(NRF_ENRXADDR);

	SPI_write(0x01);

	 PTD_BASE_PTR->PSOR = 1<<0;
}

void nrf_en_rxaddr_read() //read from the datapipe register
{
	int i;
	char c;
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_read_register(NRF_ENRXADDR);

	 SPI_write(0xff);
	 c=SPI_read();

	 PTD_BASE_PTR->PSOR = 1<<0;
}


void nrf_rx_pipesize_write() //set the data pipe size
{
	int i;
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_write_register(NRF_PIPESIZE);

	SPI_write(0x01);

	PTD_BASE_PTR->PSOR = 1<<0;
}

void nrf_rx_pipesize_read()  //read the data pipe size
{
	int i;
	char c;
	PTD_BASE_PTR->PCOR = 1<<0;
	nrf_read_register(NRF_PIPESIZE);

	 SPI_write(0xff);
	 c=SPI_read();

	 PTD_BASE_PTR->PSOR = 1<<0;
}
