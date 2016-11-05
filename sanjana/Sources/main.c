#include "MKL25Z4.h"
#include "NRF.h"
#include "SPI.h"
#include "uart.h"
#include "log.h"
#define CLOCK_SETUP 1

#define LOG0(c) uart_log((uint8_t*) c)
#define LOG1(x,y) uart_log1((uint8_t*) x, (uint32_t*) y)


int main(void)
{
	  SPI_init();   //Init SPI0

	  while(1)
	 {

		  nrf_config_write();
		  nrf_config_read();
		  //nrf_status_read();
		  // nrf_fifostatus_read();
		  //nrf_rfsetup_transmit();
		  //nrf_rfsetup_receive();
		  //nrf_tx_addr_write();
		  //nrf_tx_addr_read();
     }
}
