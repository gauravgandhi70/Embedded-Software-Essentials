#include<stdio.h>
#include<stdint.h>
#include "ADC.h"
//**************************************************
//					ADC DRIVERS
//**************************************************

void ADC_Init12b(void)
{
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	
	ADC0_CFG1 |= (ADC_CFG1_MODE(1) | //12 bit conversion
			      ADC_CFG1_ADIV(2));// input clock /4
	
	ADC0_SC1A  = ADC_SC1_ADCH(31);
}

void ADC_Init16b(void)
{
	SIM_SCGC6 |= SIM_SCGC6_ADC0_MASK;
	
	ADC0_CFG1 |= (ADC_CFG1_MODE(3) | //16 bit conversion
			      ADC_CFG1_ADIV(2)); //input clock/4
	
	ADC0_SC1A  = ADC_SC1_ADCH(31); //Disable module
}


unsigned short ADC_read12b(unsigned char channelNumber) 
{
	ADC0_SC1A = channelNumber & ADC_SC1_ADCH_MASK; 	//Write to SC1A to start conversion
	while(ADC0_SC2 & ADC_SC2_ADACT_MASK);  			//Conversion in progress
	while(!(ADC0_SC1A & ADC_SC1_COCO_MASK));			//wait till conversion is complete
	/Until conversion complete
	return ADC0_RA;
}

unsigned short ADC_read16b(unsigned char channelNumber) 
{
	ADC0_SC1A = channelNumber & ADC_SC1_ADCH_MASK; 	//Write to SC1A to start conversion
	while(ADC0_SC2 & ADC_SC2_ADACT_MASK);  			//Conversion in progress
	while(!(ADC0_SC1A & ADC_SC1_COCO_MASK));			//Until conversion complete
	return ADC0_RA;
}

