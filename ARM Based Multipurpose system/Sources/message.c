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
#include"tsi.h"
#include"message.h"
#include"accelerometer.h"
#include<malloc.h>




uint8_t decode_msg(msg_t *msg)
{
	uint32_t i=0;
	// Calculate the checksum
	uint16_t chk = msg->command + msg->length;
	for(i=0;i<msg->length;i++)
	{
		chk += msg->data[i];
	}
	i=0;
	// Compare calculated checksum with recieved checksum
	if(chk!=msg->checksum)
	{
		LOG0("Checksum Error");
		return 0;
	}

	// If check sum is correct then Check for command ID
	if(msg->command == Get_temparature)
	{
		LOG1("\n\rTEMPARATURE: ",sensor_data[TEMP],'i');
		LOG0("Celcius");

	}
	else if(msg->command == Get_light)
	{		LOG1("\n\r Light: ",sensor_data[LIGHT],'i');
			LOG0("%");		// FOr led_off command turn off the LED


	}
	else if(msg->command == Acc_ON)
	{

		LOG0("\n\r ACCELEROMETER Controlled LED ON");
		tsi_stop_scan();
		//ACCELEROMETER_control();
		acc_flag=1;
	}
	else if(msg->command == Acc_OFF)
	{
		LOG0("\n\r ACCELEROMETER Controlled LED OFF ");// FOr led_off command turn off the LED
			acc_flag=0;
			I2C_init();

	}

	else if(msg->command == TSI_ON)
	{								// FOr led_off command turn off the LED

			LOG0("\n\r TSI LED ON");

			tsi_start_scan();
			tsi_led_flag=1;
	}
	else if(msg->command == TSI_OFF)
		{
				LOG0("\n\r TSI LED OFF");// FOr led_off command turn off the LED
				tsi_stop_scan();
				tsi_led_flag=0;
		}


	else if(msg->command == Motor_speed)
		{
			motor_control(msg->data[0]);

		}

	else if(msg->command == START_LOG)
		{
			LOG0("START UART LOGGING");
			UART_flag=1;
			sensor=1;

		}

	else if(msg->command == STOP_L0G)
		{
		LOG0("\n\rSTOP UART LOGGING");
						UART_flag=0;

		}
	else if(msg->command == GET_PWM)
		{
				LOG1("\n\rPWM  :",sensor_data[PWM],'i');
				LOG0(" %");
		}
	return 1;
}
