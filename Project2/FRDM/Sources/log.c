/*
 * log.c
 *
 *  Created on: 08-Oct-2016
 *      Author: Gaurav Gandhi
 */
#include "MKL25Z4.h"
#include "uart.h"
#include"circbuf.h"
#include"data.h"
#include"main.h"
#include<stdio.h>

//LOG0 function is for displaying the uint8_t data type elements to the serial terminal
void uart_log(uint8_t *c)
{	
	uint32_t i=0;
	while(*(c+i) !='\0')
	{
	add_data(&tx_buf,*(c+i));	// Reads the string till \0 and adds that data to the transmit buffer
	i++;
	}
	UART0_C2 |= UART0_C2_TIE_MASK; //Enable the tx interrupt when there is data in tx buffer
}

/* LOG1 function takes string pointer , parameter and length of parameter as input
It converts the parameter to uint8_t type and then it concatenates the string and parameter and sends it to 
 serial terminal */
void uart_log1(uint8_t *c, uint32_t *para)
{
	uint8_t str[100]="0",ret_para[100]="0";
		uint32_t i = 0,j=0;
		int32_t len=0;
	itoa((uint32_t)(*para),ret_para,10);  //converting to ascii characters
	//ftoa(*para,ret_para,3);
	/*LOG0("STRINGS BEFORE CONCATENATION \n \r");
	LOG0(ret_para);
	LOG0("\n \r");
	LOG0(c);
	LOG0("\n \r");*/

	while(*(ret_para+len)!='\0')
	{
		len++;
	}

	while (*(c+i) != '\0')
	{
		*(str+i)=*(c+i);
		i++;
	}							// Two while loops for concatenating the two strings

	//length=len;
	while(len>=0)
	{
		*(str+i)=*(ret_para+j);
		i++;j++;len--;
	}

	/*LOG0("STRING AFTER CONCTENATION");
	LOG0("\n \r");*/
	LOG0(str);

		//UART0_C2 |= UART0_C2_TIE_MASK; // Enable the tx interrupt

}


void bbb_log(uint8_t *c)
{
	uint32_t i=0;

	while(*(c+i) !='\0')
	{
	printf("%c",*(c+i));	// Reads the string till \0 and adds that data to the transmit buffer
	i++;
	}
	UART0_C2 |= UART0_C2_TIE_MASK; //Enable the tx interrupt when there is data in tx buffer
}
