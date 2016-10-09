/*
 * log.c
 *
 *  Created on: 08-Oct-2016
 *      Author: Admin
 */
#include "MKL25Z4.h"
#include "uart.h"
#include"circbuf.h"
#include"data.h"

void LOG0(uint8_t *c)
{
	uint32_t i=0;
	while(*(c+i) !='\0')
	{
	add_data(&tx_buf,*(c+i));
	i++;
	}
	UART0_C2 |= UART0_C2_TIE_MASK;
}


void LOG1(uint8_t *c, uint32_t *para,int32_t length)
{
	uint8_t str[100]="0",ret_para[100]="0";
		uint32_t i = 0,j=0;
	itoa((uint32_t)(*para),ret_para,10);
	//ftoa(*para,ret_para,3);
	LOG0("STRINGS BEFORE CONCATENATION \n \r");
	LOG0(ret_para);
	LOG0("\n \r");
	LOG0(c);
	LOG0("\n \r");

	while (*(c+i) != '\0')
	{
		*(str+i)=*(c+i);
		i++;
	}

	while(length>=0)
	{
		*(str+i)=*(ret_para+j);
		i++;j++;length--;
	}

	LOG0("STRING AFTER CONCTENATION");
	LOG0("\n \r");
	LOG0(str);

		UART0_C2 |= UART0_C2_TIE_MASK;

}

