/*
 * calibrate.c
 *
 *  Created on: 06-Dec-2016
 *      Author: Gaurav
 */

#include "MKL25Z4.h"
#include "uart.h"
#include"circbuf.h"
#include"data.h"
#include"log.h"
#include"memory.h"
#include"main.h"
#include"dma.h"
#include"led.h"
#include"message.h"
#include<malloc.h>
#include"tsi.h"
#include"dac.h"
#include"I2C.h"

#include"sdcard.h"
#include"SPI.h"
#include"adc.h"
#include"calibrate.h"



uint32_t TEMP_calibrate()
{
	 uint32_t  temp;

	             I2C_WriteRegister(0X60,0x26,0x02);

	             temp= I2C_ReadRegister(0X60,0x04);
	          return temp;
}


uint16_t LIGHT_calibrate()
{
	uint16_t light;

	light = ADC_read10b(8);
	light = (light*100)/1024;

	return light;
}
