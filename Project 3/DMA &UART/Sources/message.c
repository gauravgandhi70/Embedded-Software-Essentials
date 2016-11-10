/*
 * message.c
 *
 *  Created on: 01-Nov-2016
 *      Author: Admin
 */
#include "MKL25Z4.h"
#include "uart.h"
#include"circbuf.h"
#include"data.h"
#include"log.h"
#include"led.h"
#include"memory.h"
#include"main.h"
#include"dma.h"
#include"profile.h"
#include"message.h"
#include<malloc.h>

uint8_t decode_msg(msg_t *msg)
{
	uint32_t i=0;
	uint16_t chk = msg->command + msg->length;
	for(i=0;i<msg->length;i++)
	{
		chk += msg->data[i];
	}
	i=0;
	if(chk!=msg->checksum)
	{
		LOG0("Checksum Error");
		return 0;
	}

	if(msg->command == led_on)
	{
		LED_Init();
		LOG0("\n\rLED ON");
		LEDFunction(RED,100);
		i=1;
	}
	else if(msg->command == led_off)
	{
		LOG0("\n\rLED OFF");
		LEDFunction(OFF,100);
	}
	else if(msg->command == set_color_bri)
	{
		if(i==1)
		{
			LOG0("\n\rSET Color and Brightness");
			LEDFunction(msg->data[0],(msg->data[1])*100);
		}
		else
		{
			LOG0("\n\r First Turn ON the LED \n\r");
		}

	}
	return 1;
}
