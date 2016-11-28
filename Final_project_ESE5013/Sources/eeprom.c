/*
 * eeprom.c
 *
 *  Created on: 27-Nov-2016
 *      Author: Admin
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
#include"eeprom.h"

void EEPROMwrite(uint16_t address, uint8_t data)
{
	uint32_t i=100000;
	I2C_Start();
		I2C0_D = (EEPROM_ID|((address/256)<<1));									/* Send I2C device address with W/R bit = 0 */
		I2C_Wait();

		I2C0_D = address - (address/256)*256 ;										/* Send register address */
		I2C_Wait();

		I2C0_D = data;												/* Send the data */
		I2C_Wait();

		I2C_Stop();
		while(i>0){i--;}

}



uint8_t EEPROMread(uint16_t address)
{
		uint8_t result;

		I2C_Start();
		I2C0_D = (EEPROM_ID|((address/256)<<1));										/* Send I2C device address with W/R bit = 0 */
		I2C_Wait();

		I2C0_D = address - (address/256)*256 ;										/* Send register address */
		I2C_Wait();

		I2C_RepeatedStart();

		I2C0_D = I2C0_D = (EEPROM_ID|((address/256)<<1)) | 0x01;							/* Send I2C device address this time with W/R bit = 1 */
		I2C_Wait();

		I2C_EnterRxMode();
		I2C_DisableAck();

		result = I2C0_D;
		I2C_Wait();
		I2C_Stop();
		//result = I2C0_D;
		//Pause(50);
		return result;
}
