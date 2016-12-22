/*
 * motor.c
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
#include"motor.h"

void motor_init()
{
    SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM1_MASK; //clock select for TPM1 ,ENABLES TPM1

    SIM_BASE_PTR->SOPT2 |= SIM_SOPT2_TPMSRC(1); //Select clock source to PLL/2

    TPM1_BASE_PTR->SC = TPM_SC_CMOD(1) | TPM_SC_PS(7); //CMOD is clock mode selection to 1 amd prescalar to 1 i.e 128 for TPM1
    TPM1_BASE_PTR->MOD = 1000; //set MOD value, timer counter is set to MOD value when reaches 0


    SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTE_MASK;  //clock select for PORTB, Enables PORTB

    PORTE_BASE_PTR->PCR[20] = PORT_PCR_MUX(3); //set alternate function as TPM channel for port E pin 20


    //Set mode selection to edge aligned PWM
    TPM1_BASE_PTR->CONTROLS[0].CnSC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSA_MASK;

}



uint8_t motor_control(uint8_t speed)
{
	if (speed>100){speed=90;}
	sensor_data[PWM]=speed;
	TPM1_BASE_PTR->CONTROLS[0].CnV = 1000 - ((speed * 10));
	//speed = ((speed * 10)/16);
	return speed;
}
