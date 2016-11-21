/*
 * uart.h
 *
 *  Created on: 07-Oct-2016
 *      Author: Admin
 */

#ifndef INCLUDES_UART_H_
#define INCLUDES_UART_H_
#include "circbuf.h"
void uart_init(uint32_t baud);
void UART0_IRQHandler();
void LOG(uint8_t *c);
cirbuf_t tx_buf,rx_buf;
#endif /* INCLUDES_UART_H_ */
