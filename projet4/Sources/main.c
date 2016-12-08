/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
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
#include"profile.h"
#include"sdcard.h"
#include"SPI.h"
#include"adc.h"
#include"calibrate.h"
#include"rtc.h"
#include"accelerometer.h"






int main(void)
{
	uint32_t i=0,c;
	uint32_t msg_f=1,msg_f1=1;
	uart_init(57600);								// Initialize UART
	SPI_init();

	rtc_init();
	time_setup();
	pit_init();
	sdcard_init();
	LED_Init();
	I2C_init();
	tsi_init();
	dac_init();
	ADC_Init10b();
	motor_init();
	acc_flag=0;

	/*LOG0("\n\rADC Timing Analysis: ");
	pit_enable();
	sensor_data[LIGHT] = LIGHT_calibrate();
	pit_disable();
	get_time();*/




	while(1)			// Infinite loop for continuous operation
		{

				sensor_data[TEMP] = TEMP_calibrate();					// Gather Data from digital temparature sensor via I2C

				sensor_data[LIGHT] = LIGHT_calibrate();                // Gather Data from analog light sensor via ADC





				// Store acquired status of all the peripherals in an array with time and date stamp for Logging it in SD Card
				// Data is stored in such a format that every peripheral starts on a new line and is separated by ',' and sentemce is erminated by '\n'
				 sd_data[0]=cur_time.date ; sd_data[1]= cur_time.month ; sd_data[2]= cur_time.year ;sd_data[3]=',';
				 sd_data[16]= cur_time.hour; sd_data[17]=cur_time.min ;sd_data[18]=',';
				 sd_data[32]=sensor_data[LIGHT]; sd_data[33]= ',';
				 sd_data[48]=  sensor_data[TEMP]; sd_data[49]= ',';
				 sd_data[64]= sensor_data[PWM];sd_data[65]= '\n';

				
				// Message Structure Implementation (m= message structure)
				state ec=buff_empty(&rx_buf);					// Checking  Rx buffer for empty

					if(ec==buf_not_empty && (msg_f1==1))				// If buffer is not empty and length is not read then
					{												// read command ID first and then read message length
						uint8_t con=read_data(&rx_buf);
						if(msg_f==1 && con>0 && con<15)
						{
							m.command = con;						// Store command in m.command
							msg_f=0;
						}
						else if(msg_f1==1 && msg_f==0)
						{
							m.length = con;							// Store data length in m.length
							msg_f1=0;
						}

				    }

					// After command command ID and Length is recieved then Read data into mesage structure
					else if(ec==buf_not_empty && i<m.length && m.length<MAX_DATA_SIZE)
					{
						uint8_t con=read_data(&rx_buf);
						m.data[i]=con;
						i++;
					}
					else if(ec==buf_not_empty && i==m.length)
					{														
						uint8_t con=read_data(&rx_buf);					// After all data is read then get the checksum and store it in m.checksum
						m.checksum = con;
						msg_f=msg_f1=1;
						i=0;
						decode_msg(&m);								// Pass structure m to decode message

					}


				// UART Logger
			if(log_flag ==1 && UART_flag==1 )					// If user hs enabled UART logging by setting UART_flag then data is logged every second using RTC interrupt
			{
				if(sensor==LIGHT)								// Log every sensor one after another 
				       {									// Starting with LIGHT, TEMP, PWM

				           LOG1("\n\r Light : ",sensor_data[sensor],'i');
				           LOG0("%");
				           log_flag=0;
				       }
				else  if(sensor==TEMP)
				       {
					 	 	 LOG1("\t TEMP : ",sensor_data[sensor],'i');
					 	 	 LOG0("Celcius");
				             log_flag=0;
				       }
				else  if(sensor==PWM)
				       {
					 	 	 LOG1("\t  PWM : ",sensor_data[sensor],'i');
									           LOG0("%");
									 sensor=0;
				                     log_flag=0;
				       }




			}





			// If Touch sensitive input is enbled by user then LED is controlled by tsi status by tsi_led function
			if(tsi_flag==1 && tsi_led_flag==1)
			{
				tsi_flag=0;
				tsi_led();

			}



			if(acc_flag==1)
			{
				ACCELEROMETER_control();
			}




		}



}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
/*-----------------------------------------------------------------------------------------
                                void lcd_init()
 ------------------------------------------------------------------------------------------
 * I/P Arguments: none
 * Return value	: none

 * description: Used for initial setup of the lcd
-----------------------------------------------------------------------------------------*/
