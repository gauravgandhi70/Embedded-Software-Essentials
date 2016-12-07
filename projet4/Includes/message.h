/*
 * message.h
 *
 *  Created on: 01-Nov-2016
 *      Author: Gaurav Gandhi
 *      This header file contains message structure and function prototypes of decode message
 *      Also it defines an enum which gives status of the LED
 */
#ifndef INCLUDES_MESSAGE_H_
#define INCLUDES_MESSAGE_H_
#define MAX_DATA_SIZE 10

typedef enum{Get_temparature=0x01, Get_light=0x02, Acc_ON=0x03, Acc_OFF=0x04, TSI_ON=0x05, TSI_OFF=0x06, Motor_speed=0x07,START_LOG=0x08,STOP_L0G=0x09}cmd;
typedef struct{
	cmd command;
	uint8_t length;
	uint8_t data[MAX_DATA_SIZE];
	uint16_t checksum;
}msg_t;
msg_t m;
uint8_t decode_msg(msg_t *msg);
uint32_t UART_flag;
#endif /* INCLUDES_LOG_H_ */

