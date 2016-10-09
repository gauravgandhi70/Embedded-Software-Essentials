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
#define CLOCK_SETUP 1


int main(void)
{

	uart_init(57200);
	uint8_t tx_str[100]="This is an Integer Number: ",rx_str[100]="0";
	/*//para=200;
	//uint16_t para = 4096;
	uint32_t para = 123456;
	LOG1("This is an Integer Number: ",&para,6);
	*/
    LOG(tx_str);

	LED_Init();
	uint32_t i=0;
	while(1)
	{
		state ec=buff_empty(&rx_buf);

		if(ec==buf_not_empty )
		{
			uint8_t con=read_data(&rx_buf),mode;
			if(con=='t' || con==0xd)
			{
				mode=con;

			}

			else if(mode=='t')
			 {
				rx_str[i] = con;
				i++;
			}

		    else if((con=='a'|| con=='s' || con=='w' || con=='d'))
		    {
		    				 LED_Control(con);
		    }
		    if(mode==0xd)
		    {
		        mode=0;
   				LOG(rx_str);
   				my_memzero(rx_str,i);
 				 i=0;
   			}
	    }

	}



}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
