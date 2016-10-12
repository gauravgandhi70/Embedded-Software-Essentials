/*
 * profile.c
 *
 *  Created on: 11-Oct-2016
 *      Author: Admin
 */
#include "MKL25Z4.h"
#include"profile.h"
#include"data.h"
#include"main.h"


uint32_t counter=0;

void pit_init(void)
{
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;
	PIT_MCR = 0;

	PIT_LDVAL0  = 0x18;

	PIT_TCTRL0 |= PIT_TCTRL_TIE_MASK;
	NVIC_EnableIRQ(PIT_IRQn);

}

void pit_enable(void)
{
	counter=0;
	PIT_TCTRL0 |= PIT_TCTRL_TEN_MASK;
}



void pit_disable(void)
{
	PIT_TCTRL0 &= ~PIT_TCTRL_TEN_MASK;

}

void get_time(void)
{
	uint8_t time[16];
	itoa(counter, time, 10);
	LOG0(time);
}


void PIT_IRQHandler(void)
{
	PIT_TFLG0 = PIT_TFLG_TIF_MASK;
	counter++;
	PIT_TCTRL0 |= PIT_TCTRL_TIE_MASK;

}

