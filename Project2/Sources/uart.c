/*
 * uart.c
 *
 *  Created on: 07-Oct-2016
 *      Author: Gaurav Gandhi
 */
#include "MKL25Z4.h"
#include "uart.h"
#include"circbuf.h"
#include"data.h"


void uart_init(uint32_t baud)
{
	uint16_t baud_divisor;


	//Set gate clock  for PORTA
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;

	//Enable clock for UART0 and set clock source as MCGCLKFLL
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1);

	// Set the alternate function for PORTA as UART0
	PORTA_PCR1 = PORT_PCR_MUX(2);
	PORTA_PCR2 = PORT_PCR_MUX(2);

	// Disable tx and rx before editing registers of UART0
	UART0_C2=0x00;
	UART0_C1=0x00;





	/* Calculate baud_divisor for sbr register and set baud rate */
	baud_divisor= (uint16_t)(DEFAULT_SYSTEM_CLOCK/(baud *16));
	UART0_BDH |= (baud_divisor >> 8) & UART0_BDH_SBR_MASK;
	UART0_BDL = (baud_divisor & UART0_BDL_SBR_MASK);


	//tx buffer initialization
	tx_buf.buff = initialize(&tx_buf);
	tx_buf.head=tx_buf.data;
			 	tx_buf.tail=tx_buf.data;
			 	tx_buf.buff=tx_buf.data;
			 	tx_buf.new_len= 0;

	//rx buffer initialization
	rx_buf.buff = initialize(&rx_buf);
    rx_buf.head=rx_buf.data;
			rx_buf.tail=rx_buf.data;
			rx_buf.buff=rx_buf.data;
			rx_buf.new_len= 0;

	//Set NVIC interrupts and CPU interrupts
	NVIC_EnableIRQ(UART0_IRQn);
	UART_C2_REG(UART0_BASE_PTR) |= UART_C2_RIE_MASK; //Setup receiver interrupt
	//UART_C2_REG(UART0_BASE_PTR) |= UART_C2_TIE_MASK;
	//__enable_irq();

    UART_C2_REG(UART0_BASE_PTR) |= (UART_C2_TE_MASK | UART_C2_RE_MASK ); //Switch on transmitter and receiver
  }


volatile uint8_t da=0;

void UART0_IRQHandler()
{	state error_code = buff_empty(&tx_buf);
	
	if((UART0_S1 & UART0_S1_TDRE_MASK)&& error_code==buf_not_empty)
	{											// If buffer is not empty and TDRE flag is set then transmit the character

		UART0_D =  read_data(&tx_buf);
	}
	else if(error_code==buf_empty)
	{
		UART0_C2 &= ~UART0_C2_TIE_MASK;			// If tx buffer is empty then disable the tx interrupt
	}

	error_code = buff_full(&rx_buf);
	
	if((UART0_S1 & UART0_S1_RDRF_MASK) && error_code==buf_not_full) 
	{													
														// If buffer is not and RDRF flag is set then recieve the character from UARTD0
		uint8_t mode;
		uint32_t i;
		da= UART0_D;
		add_data(&rx_buf,da);


	}

	else if(error_code==buf_empty)	
		{
			UART0_C2 &= ~UART0_C2_RIE_MASK;  		// If rx buffer is full then disable the rx interrupt 
		}



}

