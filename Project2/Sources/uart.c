/*
 * uart.c
 *
 *  Created on: 07-Oct-2016
 *      Author: Admin
 */
#include "MKL25Z4.h"
#include "uart.h"
#include"circbuf.h"
#include"data.h"


void uart_init(uint32_t baud)
{
	uint16_t sbr;
	uint8_t temp;

	//Set clock frequency for PORTA
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;

	//Set clock frequency
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
	SIM_SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;
	SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1);// Select the clock as PLL/2

	PORTA_PCR1 = PORT_PCR_MUX(2);// Set the alternate function for PORTA
	PORTA_PCR2 = PORT_PCR_MUX(2);

	UART0_C2_REG(UART0_BASE_PTR) &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK); // Switch off UART before setting
	UART0_C1_REG(UART0_BASE_PTR)=0x00; //Set all default configuration

	//SBR calculation

	sbr= (uint16_t)(DEFAULT_SYSTEM_CLOCK/(baud *16));

	/* Save off the current value of the uartx_BDH except for the SBR field */
	temp = UART_BDH_REG(UART0_BASE_PTR) & ~(UART_BDH_SBR(0x1F));
	UART_BDH_REG(UART0_BASE_PTR) = temp |  UART_BDH_SBR(((sbr & 0x1F00) >> 8));//set SBR field for Baud rate
	UART_BDL_REG(UART0_BASE_PTR) = (uint8_t)(sbr & UART_BDL_SBR_MASK);

	tx_buf.buff = initialize(&tx_buf);
	tx_buf.head=tx_buf.data;
			 	tx_buf.tail=tx_buf.data;
			 	tx_buf.buff=tx_buf.data;
			 	tx_buf.new_len= 0;
    rx_buf.buff = initialize(&rx_buf);
    rx_buf.head=rx_buf.data;
			rx_buf.tail=rx_buf.data;
			rx_buf.buff=rx_buf.data;
			rx_buf.new_len= 0;
	//Set NVIC interrupts and set priority
	NVIC_EnableIRQ(UART0_IRQn);
	NVIC_SetPriority(UART0_IRQn,2);

	UART_C2_REG(UART0_BASE_PTR) |= UART_C2_RIE_MASK; //Setup receiver interrupt
	//UART_C2_REG(UART0_BASE_PTR) |= UART_C2_TIE_MASK;
	__enable_irq();

    UART_C2_REG(UART0_BASE_PTR) |= (UART_C2_TE_MASK | UART_C2_RE_MASK ); //Switch on transmitter and receiver
  }


uint8_t da=0;

void UART0_IRQHandler()
{	state error_code = buff_empty(&tx_buf);
	// If buffer is not empty and TDRE flag is set then transmit the character
	if((UART0_S1 & UART0_S1_TDRE_MASK)&& error_code==buf_not_empty)
	{

		UART0_D =  read_data(&tx_buf);
	}
	else if(error_code==buf_empty)
	{
		UART0_C2 &= ~UART0_C2_TIE_MASK;
	}

	error_code = buff_full(&rx_buf);
	if((UART0_S1 & UART0_S1_RDRF_MASK) && error_code==buf_not_full)
	{
		uint8_t mode;
		uint32_t i;
		da= UART0_D;
		add_data(&rx_buf,da);


	}

	else if(error_code==buf_empty)
		{
			UART0_C2 &= ~UART0_C2_RIE_MASK;
		}



}

