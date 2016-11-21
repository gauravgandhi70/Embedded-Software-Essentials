/*
 * tsi.c
 *
 *  Created on: 20-Nov-2016
 *      Author: Admin
 */
#include "MKL25Z4.h"
#include "uart.h"
#include"circbuf.h"
#include"data.h"
#include"log.h"
#include"led.h"
#include"memory.h"
#include"main.h"
#include"dma.h"
#include"message.h"
#include"tsi.h"
#include<malloc.h>




void tsi_init()
{
	SIM_SCGC5 |= SIM_SCGC5_TSI_MASK;  // Enable  	Access to the TSI module
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;// Enable Port B Gate CLock

	PORTB_PCR16 |= PORT_PCR_MUX(0);		// Choose Alternate function 0 as TSI channel 9
	//PORTB_PCR17 |= PORT_PCR_MUX(0);


	TSI0_GENCS |= TSI_GENCS_ESOR_MASK;	// End of Scan interurpt in allowed
	TSI0_GENCS |= TSI_GENCS_NSCN_MASK;	// 32 scans per electrodr
	TSI0_GENCS |= TSI_GENCS_TSIEN_MASK;	// Enable Touch sensing input mode
	TSI0_GENCS |= TSI_GENCS_TSIIEN_MASK; // Enable Touch sensing input interrupt

	NVIC_EnableIRQ(TSI0_IRQn);			// Enable Global Interrupt
	__enable_irq();

	TSI0_DATA |= TSI_DATA_TSICH(9);		// Select channel number 9 for input


	TSI0_TSHD = 0xFF00;					// THRESHOLD VALUE

	TSI0_DATA |= TSI_DATA_SWTS_MASK;     // START SCAN
}

void tsi_led()
{
			if(d>650 && d<750)
				{

					LOG1("\n\rRED=",&d);
					LEDFunction(RED,200);
				}
			else if(d>750 && d<850)
				{
					LOG1("\n\rYELLOW=",&d);
					LEDFunction(YELLOW,200);
				}
			else if(d>850 && d<950)
				{
					LOG1("\n\rGreen=",&d);
					LEDFunction(GREEN,200);
				}
			else if(d>950 && d<1050)
				{
					LOG1("\n\rBLUE=",&d);
					LEDFunction(BLUE,200);
				}
			else if(d>1050 && d<1150)
				{
					LOG1("\n\rMAGENTA=",&d);
					LEDFunction(MAGENTA,200);
				}
			else if(d>1150 && d<1250)
				{
					LOG1("\n\rCYAN",&d);
					LEDFunction(CYAN,200);
				}
			else if(d>1250 && d<1350)
				{
					LOG1("\n\rWHITE=",&d);
					LEDFunction(WHITE,200);
				}
			else if(d>1350 && d<1450)
				{
					LOG1("\n\LED OFF=",&d);
					LEDFunction(OFF,200);
				}

			TSI0_GENCS |= (TSI_GENCS_TSIIEN_MASK);
			TSI0_DATA |= TSI_DATA_SWTS_MASK;     // START SCAN
}

void TSI0_IRQHandler(void)
{
	TSI0_GENCS |= TSI_GENCS_EOSF_MASK;
	TSI0_GENCS &= ~(TSI_GENCS_TSIIEN_MASK);
	f=1;
	d = (TSI0_DATA<<16);
	d=d/65536;

	//TSI0_DATA |= TSI_DATA_SWTS_MASK;     // START SCAN


}
