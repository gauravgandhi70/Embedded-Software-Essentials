/*
 * log.h
 *
 *  Created on: 08-Oct-2016
 *      Author: Admin
 */

#ifndef INCLUDES_LOG_H_
#define INCLUDES_LOG_H_

#define LOG0(c) uart_log((uint8_t*) c)

void uart_log(uint8_t *c);

void bbb_log(uint8_t *c);

void uart_log1(uint8_t *c, uint32_t *para);

#endif /* INCLUDES_LOG_H_ */
