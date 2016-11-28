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



/**************************************************************************************************
 *  Services performed by FREESCALE in this matter are performed AS IS and without any warranty.  *
 *  CUSTOMER retains the final decision relative to the total design and functionality of the     *
 *  end product. FREESCALE neither guarantees nor will be held liable by CUSTOMER for the         *
 *  success of this project. FREESCALE disclaims all warranties, express, implied or statutory    *
 *  including, but not limited to, implied warranty of merchantability or fitness for a           *
 *  particular purpose on any hardware, software ore advise supplied to the project by FREESCALE, *
 *  and or any product resulting from FREESCALE services . In no event shall FREESCALE be         *
 *  liable for incidental or consequential damages arising out of this agreement. CUSTOMER        *
 *  agrees to hold FREESCALE harmless against any and all claims demands or actions by anyone     *
 *  on account of any damage, or injury, whether commercial, contractual, or tortuous, rising     *
 *  directly or indirectly as a result of the advise or assistance supplied CUSTOMER in           *
 *  connection with product, services or goods supplied under this Agreement.                     *
 **************************************************************************************************/
#include "MKL25Z4.h"
#include<stdio.h>
#include<stdint.h>
#include "adc.h"

/********************************************************************************************/
#define Vtemp25 0.7012


/********************************************************************************************/

float result=0;
float m=0;
float Temp=0;
int ADC_value=0;

/********************************************************************************************/

int main(void)
{


	//Initialize ADC module on 16-bit mode and polling method
	ADC_Init10b();

	for(;;)
	{
		//Read ADC Temperature channel
		ADC_value = ADC_read10b(26);
        result=ADC_value * 0.003125;
	   	if(result>Vtemp25) //compare for hot or cold slope
	   	m=0.001646; //Cold slope
	   	else
	   	m=0.001749; //Hot slope
	   	Temp=25-((result-Vtemp25)/m); //Calculate the temperature
	}

	return 0;
}
