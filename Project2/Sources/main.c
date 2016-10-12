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
#include"led.h"
#include"data.h"
#include"log.h"
#include"memory.h"
#include"main.h"
#include"profile.h"
#define CLOCK_SETUP 1	// Clock setup for frequany 48MHz


int main(void)
{


	uart_init(57200);
	pit_init();
	__enable_irq();
	uint8_t tx_str[100]="\n Control Characters a,s,w,d,t \n \r a/d=color change \n\r w/s=+/- Brightness \n\r t=echo mode";
	uint8_t rx_str[100]="0";
	LOG0(tx_str);

	//Timetest function is time profiler
	//timetest();



	/* Different data type LOG function test cases */
	//uint8_t para=200;
	//LOG1("This is an Integer Number (8-bit type): ",&para,3);

	//uint16_t para = 4096;
	//LOG1("This is an Integer Number (16-bit type): ",&para,4);

	//uint32_t para = 123456;
	//LOG1("This is an Integer Number (32-bit type): ",&para,6);

	//float para = 1543.321;
	//LOG1(tx_str,&para,8);



	 unittest_init();


	LED_Init();  			// Initializing LED configurations
	uint32_t i=0;
	while(1)				// Infinite loop for continuous operation
	{
		state ec=buff_empty(&rx_buf);					// Checking  Rx buffer for empty

		if(ec==buf_not_empty )				
		{
			uint8_t con=read_data(&rx_buf),mode;		// If its not empty then read data into con variable
			if(con=='t' || con==0xd)					// If t is read then switch mode to echo mode
			{
				mode=con;

			}

			else if(mode=='t')
			 {
				rx_str[i] = con;						// If the mode is echo then store read data into rx_str
				i++;
			}

		    else if((con=='a'|| con=='s' || con=='w' || con=='d'))  // Otherwise if a,s,d,w is pressed go to LED control
		    {
		    				 LED_Control(con);
		    }
		    if(mode==0xd)									// When enter is pressed send all the data in rx_str to serial terminal
		    {												// and removed all the data from the rx_str using my_memzero
		        mode=0;
   				LOG0(rx_str);
   				my_memzero(rx_str,i);
 				 i=0;
   			}
	    }

	}



}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
