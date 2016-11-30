/*
 * rtc.c
 *
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


	 /*RTC_IER |= RTC_IER_TSIE_MASK;

	 NVIC_EnableIRQ(RTC_Seconds_IRQn);
	 __enable_irq();


	 RTC_SR |= RTC_SR_TCE_MASK;     // Enable Counter*/



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


					if(con==0xd)
					{
							f++;
							d[i]=con;
							i=0;
							if(f==1){cur_time.date=my_atoi(d);LOG0("\n\r Enter month : ");}
							else if(f==2){cur_time.month=my_atoi(d);LOG0("\n\r Enter Year in YY format : ");}
							else if(f==3){cur_time.year=my_atoi(d);LOG0("\n\r Enter current time in 24 hour format\n\r Hours : ");}
							else if(f==4){cur_time.hour=my_atoi(d);LOG0("\n\r  Minutes : ");}
							else if(f==5)
							{
								cur_time.min=my_atoi(d);
								break;
							}


					}





			}

		}


		RTC_TSR = datetosec();
		RTC_IER = RTC_IER_TSIE_MASK;
		NVIC_EnableIRQ(RTC_Seconds_IRQn);
		NVIC_SetPriority( RTC_Seconds_IRQn, 2);
		__enable_irq();
		RTC_SR |= RTC_SR_TCE_MASK;
}



uint32_t datetosec(void)
{
	uint32_t sec,i;

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


void RTC_Seconds_IRQHandler()
{
	LED_Control('a');
	//LOG1("\n\rRTC Status: ",RTC_TSR,'i');
}
