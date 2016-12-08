/*
 * rtc.c
 * This is RTC library for MKL25Z4. It contains RTC initialization
 Real time acquiring for the RTC and Interrupt handler
 *  Created on: 21-Nov-2016
 *      Author: Gaurav Gandhi
 */
#include "MKL25Z4.h"
#include "uart.h"
#include"circbuf.h"
#include"data.h"
#include"log.h"
#include"memory.h"
#include"main.h"
#include"dma.h"
#include"led.h"
#include"message.h"
#include<malloc.h>
#include"tsi.h"
#include"dac.h"
#include"I2C.h"
#include"rtc.h"
#include"sdcard.h"
uint32_t sd_log_freq=0;
uint8_t sd_addr[3];
/*-----------------------------------------------------------------------------------------
                                void rtc_init()
 ------------------------------------------------------------------------------------------
 * I/P Arguments: none
 * Return value	: none

 * description: Used for initial setup of the RTC
-----------------------------------------------------------------------------------------*/

void rtc_init()
{
		uint32_t i=100000;

		MCG_C1 |= MCG_C1_IRCLKEN_MASK; //Enable internal reference clock
		MCG_C2 &= ~(MCG_C2_IRCS_MASK);  //Internal Reference Clock -->Slow

		SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;  // Enable PORT C Gate Clock

		PORTC_PCR1 |= (PORT_PCR_MUX(0x1));       //PTC1 as RTC_CLKIN
		SIM_SOPT1 |= SIM_SOPT1_OSC32KSEL(0b10);  //32 Khz clock source for RTC


		SIM_SOPT2 |= SIM_SOPT2_CLKOUTSEL(0b100); //Clockout pin --> i KHz

		PORTC_PCR3 |= (PORT_PCR_MUX(0x5)); //PTC3 as CLKOUT






	 SIM_SCGC6 |= SIM_SCGC6_RTC_MASK; //    Enable RTC



	 // Clear RTC Registers
	 RTC_CR = RTC_CR_SWR_MASK;
	 RTC_CR &= ~RTC_CR_SWR_MASK;

	 if (RTC_SR & RTC_SR_TIF_MASK){
	      RTC_TSR = 0x00000000;
	 }



			sd_addr[0]=0;				// Initialize SD card locations at the start of the RTC initializations because 
			sd_addr[1]=0;				// RTC interrupt is used for SD card data logging
			sd_addr[2]=0;
	 


}


void time_setup()
{
	uint8_t d[5],t[5],f=0;
	uint32_t i=0;
	LOG0("\n\r Enter date : ");
	while(1)				// Infinite loop for continuous operation
		{
			state ec=buff_empty(&rx_buf);					// Checking  Rx buffer for empty

			if(ec==buf_not_empty )
			{
				uint8_t con=read_data(&rx_buf),mode;		

					d[i] = con;
					i++;


					if(con==0xd)							// Accept data until '\n' is recieved
					{
							f++;			
							d[i]=con;						// Data i stored in d array
							i=0;
							if(f==1){cur_time.date=my_atoi(d);LOG0("\n\r Enter month : ");}		// First Date, then Month, Year, Time in hh.mm format is accepted from the user
							else if(f==2){cur_time.month=my_atoi(d);LOG0("\n\r Enter Year in YY format : ");}
							else if(f==3){cur_time.year=my_atoi(d);LOG0("\n\r Enter current time in 24 hour format\n\r Hours : ");}
							else if(f==4){cur_time.hour=my_atoi(d);LOG0("\n\r  Minutes : ");}
							else if(f==5)
							{
								cur_time.min=my_atoi(d);										// Once time is recieved All the data is stored in structure time
								break;
							}


					}





			}

		}


		RTC_TSR = datetosec();																// Pass data acquired from the user to datetosec function for converting it to sec for the use of RTC registers
		RTC_IER = RTC_IER_TSIE_MASK;														// Enable RTC Interrupt
		NVIC_EnableIRQ(RTC_Seconds_IRQn);
		__enable_irq();
		RTC_SR |= RTC_SR_TCE_MASK;															// Enable RTC
}


/*-----------------------------------------------------------------------------------------
                                datetosec()
 ------------------------------------------------------------------------------------------
 * I/P Arguments: none
 * Return value	: 32 bit value in seconds for the use of RTC registers

 * description: Used for converting current time to seconds by comparing it with 1 Jan 2016 for the use of RTC registers
-----------------------------------------------------------------------------------------*/



uint32_t datetosec(void)
{
	uint32_t sec,i;
	uint8_t days[12]={31,28,31,30,31,30,31,31,30,31,30,31};

	sec = cur_time.min * 60;																

	sec += cur_time.hour * 3600;

	sec += (cur_time.date-1)*86164;

	for(i=0;i<cur_time.month-1;i++)
	{
		sec += days[i]*86164;
	}

	sec += (cur_time.year-16)*31536000;

	LOG1("\n\rSECONDS : ",sec,'i');
	return sec;



}

/*-----------------------------------------------------------------------------------------
                                RTC_Seconds_IRQHandler
 ------------------------------------------------------------------------------------------
 * I/P Arguments: none
 * Return value	: None

 * description: This ISR is to handle interrupt given by RTC every second. This ISR is used as a scheduler 
 for logging data to SD card and UART. As well as keeping track of current time.
-----------------------------------------------------------------------------------------*/
void RTC_Seconds_IRQHandler()
{
	LED_Control('a');				// Led color is changed every seconds to show that cock is running

	sensor++;						// Increament sensor to acquire new data after every second
	sd_log_freq++;					// Increament sd_log_freq to log data to SD card after every 4 seconds
	log_flag=1;						

	if(sd_log_freq==4)
	{
		sd_log_freq = 0;
		sdcard_write_block(sd_addr,sd_data);				// Write 512 bytes data on SD card
		sd_addr[0]+=2;										// Increamanet address to set it to address of the new sector address of the SD card
		if(sd_addr[0]==254){sd_addr[0]=0;sd_addr[1]++;}
		if(sd_addr[1]==255){sd_addr[1]=0;sd_addr[2]++;}
		if(sd_addr[2]==255){sd_addr[1]=0;sd_addr[0]==0;}
	}
	
	/*if(sec==60){cur_time.min++;}
	if(cur_time.min==60){cur_time.hour++;}
	if(cur_time.hour==24){cur_time.day++;}*/


}
