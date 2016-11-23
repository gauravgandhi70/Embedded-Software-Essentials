
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

#include<stdio.h>
#include<stdint.h>
#include <MKL25Z4.h>
#include "adc.h"

/********************************************************************************************/
#define Vtemp25 0.7012


/********************************************************************************************/

unsigned float result;

/********************************************************************************************/

int main(void)
{
	
	
	//Initialize ADC module on 16-bit mode and polling method	
	ADC_Init12b();
	
	for(;;) 
	{	   		
		//Read ADC Temperature channel
		result = ADC_read12b(26);
		
	   	result*=0.003125
	   	if(result>Vtemp25)
	   	m=0.001646
	   	else
	   	m=0.001749
	   	Temp=25-((result-Vtemp25)/m)
	}
	
	return 0;
}


/********************************************************************************************/
