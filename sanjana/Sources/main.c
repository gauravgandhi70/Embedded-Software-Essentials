#include "MKL25Z4.h"
#include "NRF.h"
#include "SPI.h"

int main(void)
{
	  SPI_init();   //Init SPI0

	  while(1)
	 {

		  nrf_config_write();
		  nrf_config_read();
		  nrf_status_read();
		  nrf_fifostatus_read();
		  nrf_rfsetup_transmit();
		  nrf_rfsetup_receive();
		  nrf_tx_addr_write();
		  nrf_tx_addr_read();
     }
}
