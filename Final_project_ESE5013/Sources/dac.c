/*
 * dac.c
 *
 *  Created on: 26-Nov-2016
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



void dac_init()
{
	SIM_SCGC6 |= SIM_SCGC6_DAC0_MASK;
	SIM_SCGC5 |= SIM_SCGC5_PORTE_MASK;  // Enable PORT E Gate Clock

	DAC0_C0 = DAC_C0_DACEN_MASK;
	DAC0_C0 |= DAC_C0_DACTRGSEL_MASK;
	DAC0_C0  |= DAC_C0_DACSWTRG_MASK;

	DAC0_DAT0L = 0xFF;
	DAC0_DAT0H = 0x0F;


}

