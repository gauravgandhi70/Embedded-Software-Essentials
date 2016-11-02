#include "MKL25Z4.h"
#include "NRF_TEST1.h"
#include "SPI_TEST1.h"

int main(void)
{
	  SPI_init();   //Init SPI0
	  while(1)
	 {
		  nrf_config_write();

		  nrf_config_read();

	  }
}
