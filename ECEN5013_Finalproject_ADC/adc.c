#include "MKL25Z4.h"
#include<stdio.h>
#include<stdint.h>
#include "adc.h"
//**************************************************
//				ADC DRIVERS
//**************************************************

void ADC_Init10b(void)
{
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK; //Clock to ADC
	
	/*10 bit conversion, Prescalar of 8, long sample time*/
	ADC0_CFG1 |= (ADC_CFG1_MODE(0X2) | ADC_CFG1_ADIV(0X3)|ADC_CFG1_ADLSMP(0X01));
	//ADC0_CFG2 |= ADC_CFG1_ADLSTS(0X0);
	ADC0_SC1A  = ADC_SC1_ADCH(31); //Disable the module
}

unsigned short ADC_read10b(unsigned char channelNumber)
{
	ADC0_SC1A = channelNumber & ADC_SC1_ADCH_MASK; 	//Write to SC1A to start conversion
	while(ADC0_SC2 & ADC_SC2_ADACT_MASK);  			//Conversion in progress
	while(!(ADC0_SC1A & ADC_SC1_COCO_MASK));			//wait till conversion is complete
	return ADC0_RA; //return the ADC temperature value
}


