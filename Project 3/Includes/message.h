/*
 * message.h
 *
 *  Created on: 01-Nov-2016
 *      Author: Admin
 */
#ifndef INCLUDES_MESSAGE_H_
#define INCLUDES_MESSAGE_H_
#define MAX_DATA_SIZE 10

typedef enum{led_on=0x01, led_off=0x02, set_color_bri=0x03}cmd;
typedef struct{
	cmd command;
	uint8_t length;
	uint8_t data[MAX_DATA_SIZE];
	uint16_t checksum;
}msg_t;

uint8_t decode_msg(msg_t *msg);

#endif /* INCLUDES_LOG_H_ */

