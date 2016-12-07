/*
 * tsi.h
 *
 *  Created on: 20-Nov-2016
 *      Author: Admin
 */

#ifndef INCLUDES_TSI_H_
#define INCLUDES_TSI_H_
uint8_t tsi_flag,tsi_led_flag;
volatile uint16_t d;
void tsi_init(void);
void TSI0_IRQHandler(void);
void tsi_led(void);
void tsi_start_scan(void);
void tsi_stop_scan(void);
void tsi_dac(uint16_t digital);
#endif /* INCLUDES_TSI_H_ */
