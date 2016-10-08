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

void LOG(uint8_t *c)
{
	uint32_t i=0;
	while(*(c+i) !='\0')
	{
	add_data(&tx_buf,*(c+i));
	i++;
	}
	UART0_C2 |= UART0_C2_TIE_MASK;
}


void LOG1(uint8_t *c, uint8_t *para)
{
	uint8_t str[100]="0";
	uint32_t i = 0;
	while (*(c+i) != '\0')
	{
		*(str+i)=*(c+i);
		i++;
	}


	while(*(str+i) != '\0')
	{
		*(str+i)=*(para+i);
	}

	while(*(str+i) !='\0')
		{
		add_data(&tx_buf,*(str+i));
		i++;
		}
		UART0_C2 |= UART0_C2_TIE_MASK;

}

