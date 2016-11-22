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
#include"rtc.h"


void rtc_init()
{
	uint32_t i=100000;
	SIM_SCGC6 |= SIM_SCGC6_RTC_MASK;
	RTC_CR |= RTC_CR_OSCE_MASK;
	while(i>0){i--;}

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
		RTC_SR |= RTC_SR_TCE_MASK;
}



uint32_t datetosec(void)
{
	uint32_t sec,i;

	sec = cur_time.min * 60;
	sec += cur_time.hour * 3600;
	sec += (cur_time.date-1)*86,164;
	for(i=0;i<cur_time.month-1;i++)
	{
		sec += days[i]*86,164;
	}

	sec += (cur_time.year-16)*31536000;


	return sec;



}



