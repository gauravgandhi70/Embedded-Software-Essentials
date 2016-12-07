/*
 * sdcard.h
 *
 *  Created on: 06-Dec-2016
 *      Author: Gaurav
 */

#ifndef INCLUDES_SDCARD_H_
#define INCLUDES_SDCARD_H_

uint8_t sdcard_init(void);

uint8_t cmd_zero(void);
uint8_t cmd_eight(void);
uint8_t cmd_fiftyfive(void);
uint8_t cmd_feight(void);
uint8_t acmd(void);
uint8_t cmd_one(void);
uint8_t cmd_sixteen();
uint8_t sdcard_write_block( uint8_t *address,uint8_t* da);
uint8_t* sdcard_read_block( uint8_t *address);
uint8_t sd_data[518];
#endif /* INCLUDES_SDCARD_H_ */
