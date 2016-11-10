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


volatile uint32_t counter=0;

//PIT is used for time profiler in this project

//This initializes the PIT configuration
void pit_init(void)
{
	SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;		// ENabling Gate clack
	PIT_MCR = 0;							// ENabling configuration for PIT

	PIT_LDVAL0  = (24 * RESOLUTION);		// Loading timer overflow value

	PIT_TCTRL0 |= PIT_TCTRL_TIE_MASK;		//	Enabling Timer interrupt and NVIC interrupt
	NVIC_EnableIRQ(PIT_IRQn);

}

void pit_enable(void)
{
	counter=0;								// Initializing Counter for execution time
	PIT_TCTRL0 |= PIT_TCTRL_TEN_MASK;		// Enabling Timer
}



void pit_disable(void)
{
	PIT_TCTRL0 &= ~PIT_TCTRL_TEN_MASK;		// Disabling TImer

}

void get_time(void)
{
	uint32_t clk_cycle,exe_time;					// Logging the executed time
	exe_time= counter*RESOLUTION;
	clk_cycle= (counter*1000*RESOLUTION/41.6);
	LOG1(" ",&exe_time);LOG0(" microseconds \t");
	LOG1(" ",&clk_cycle);LOG0(" Clock Cycles \t");
}


void PIT_IRQHandler(void)
{
	PIT_TFLG0 = PIT_TFLG_TIF_MASK;
	counter++;									// Increamentinf the counter for every interrupt
	PIT_TCTRL0 |= PIT_TCTRL_TIE_MASK;

}

