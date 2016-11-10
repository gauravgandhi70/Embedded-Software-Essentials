/*
 * led.c
 *
 *  Created on: 07-Oct-2016
 *      Author: Admin
 */


/*
 * led.c
 *
 *  Created on: 07-Oct-2016
 *      Author: Admin
 */

/*
 * led.c
 *
 *  Created on: 07-Oct-2016
 *      Author: Admin
 */
#include "MKL25Z4.h"
#include <math.h>
#include "led.h"


LEDColour_t LEDColour=OFF; //Set initial colour 
uint16_t  value=100;// Set initial brightness

LED_Init()
{
    SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM2_MASK; //clock select for TPM2 ,ENABLES TPM2
	SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM0_MASK; //clock select for TPM0, ENABLES TPM0
    SIM_BASE_PTR->SOPT2 |= SIM_SOPT2_TPMSRC(1); //Select clock source to PLL/2

    TPM2_BASE_PTR->SC = TPM_SC_CMOD(1) | TPM_SC_PS(7); //CMOD is clock mode selection to 1 amd prescalar to 1 i.e 128 for TPM2
    TPM2_BASE_PTR->MOD = 1875; //set MOD value, timer counter is set to MOD value when reaches 0
    TPM0_BASE_PTR->SC = TPM_SC_CMOD(1) | TPM_SC_PS(7); //CMOD is clock mode selection to 1 amd prescalar to 1 i.e 128 for TPM0
    TPM0_BASE_PTR->MOD = 1875;// set MOD value, timer counter is setto MOD value when reaches 0

    SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTB_MASK;  //clock select for PORTB, Enables PORTB
    SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTD_MASK;//clock select for PORTD, Enables PORTD
    PORTB_BASE_PTR->PCR[18] = PORTB_BASE_PTR->PCR[19] = PORT_PCR_MUX(3); //set alternate function as TPM channel for port B pin 18
    PORTD_BASE_PTR->PCR[1]= PORT_PCR_MUX(4);// set alternate function as TPM channel for port D pin 1
    
    //Set mode selection to edge aligned PWM
    TPM2_BASE_PTR->CONTROLS[0].CnSC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSA_MASK; 
    TPM2_BASE_PTR->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSA_MASK;
    TPM0_BASE_PTR->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSA_MASK;
}

void LED_Control(uint8_t Character)
{
      if(Character=='w' && value<1000) //with character 'w', the brightness of the LED is increased every 100 values
      {
    	  value+=100;

      }
      else if(Character=='s' && value>0)//with character 's', the brightness of the LED is decreased every 100 values
       {
             value-=100;
        }

      else if(Character=='a') //with character 'a', the LED colours are cycled in the forward direction
            {
          	 LEDColour++;
          	 if(LEDColour>=8)//wrap around
          	 {
          		 LEDColour=0;
          	 }

            }
      else if(Character=='d') //with character 'd', the LED colours are cycles in the backward direction
             {
              LEDColour--;
               if(LEDColour==0) // wrap around
                {



            		   LEDColour=7;


                }
              }
      LEDFunction(LEDColour, value); // Call to LED function

}

LEDFunction(LEDColour_t LEDColour, uint16_t Brightness)
{
 if(LEDColour==RED)
    {
	TPM2_BASE_PTR->CONTROLS[0].CnV = Brightness; //Channel value for RED LEDColour with brightness value
	TPM2_BASE_PTR->CONTROLS[1].CnV = 0;//Channel value for GREEN LEDColour with brightness value as 0
	TPM0_BASE_PTR->CONTROLS[1].CnV = 0; //Channel value for BLUE LEDColour with brightness value as 0
	}
	else if(LEDColour==YELLOW)
	{
	TPM2_BASE_PTR->CONTROLS[0].CnV = TPM2_BASE_PTR->CONTROLS[1].CnV = Brightness; ////Channel value for RED and YELLOWLEDColour with brightness value
	TPM0_BASE_PTR->CONTROLS[1].CnV = 0; //Channel value for BLUE LEDColour with brightness value
	}
	else if(LEDColour==GREEN)
	{
	TPM2_BASE_PTR->CONTROLS[1].CnV = Brightness; //Channel value for GREEN LEDColour with brightness value
	TPM2_BASE_PTR->CONTROLS[0].CnV = 0; //Channel value for RED LEDColour with brightness value as 0
	TPM0_BASE_PTR->CONTROLS[1].CnV = 0; //Channel value for BLUE LEDColour with brightness value as 0
	}
	else if(LEDColour==BLUE)
	{
	TPM0_BASE_PTR->CONTROLS[1].CnV = Brightness; //Channel value for BLUE LEDColour with brightness value
	TPM2_BASE_PTR->CONTROLS[1].CnV = 0; //Channel value for GREEN LEDColour with brightness value as 0
	TPM2_BASE_PTR->CONTROLS[0].CnV = 0; //Channel value for RED LEDColour with brightness value as 0
	}
	else if(LEDColour==MAGENTA)
	{
	TPM2_BASE_PTR->CONTROLS[0].CnV = TPM0_BASE_PTR->CONTROLS[1].CnV = Brightness; //Channel value for RED and BLUELEDColour with brightness value
	TPM2_BASE_PTR->CONTROLS[1].CnV = 0; //Channel value for GREEN LEDColour with brightness value as 0
	}
	else if(LEDColour==CYAN)
	{
	TPM2_BASE_PTR->CONTROLS[1].CnV = TPM0_BASE_PTR->CONTROLS[1].CnV = Brightness; //Channel value for GREEN and BLUE LEDColour with brightness value
	TPM2_BASE_PTR->CONTROLS[0].CnV = 0; //Channel value for RED LEDColour with brightness value	as 0
	}
	else if(LEDColour==WHITE)
	{
	TPM2_BASE_PTR->CONTROLS[1].CnV = TPM2_BASE_PTR->CONTROLS[0].CnV=TPM0_BASE_PTR->CONTROLS[1].CnV = Brightness; //Channel value for RED, GREEN and BLUE LEDColour with brightness value
	}
	else if(LEDColour==OFF)
	{
		TPM2_BASE_PTR->CONTROLS[0].CnV = 0; //Channel value for RED LEDColour with brightness value as 0
		TPM2_BASE_PTR->CONTROLS[1].CnV = 0; //Channel value for GREEN LEDColour with brightness value as 0
		TPM0_BASE_PTR->CONTROLS[1].CnV = 0; //Channel value for BLUE LEDColour with brightness value AS 0

	}
}

