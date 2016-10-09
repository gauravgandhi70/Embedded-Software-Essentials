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


LEDColour_t LEDColour=OFF;
uint16_t  value=100;

LED_Init()
{
    SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM2_MASK;
	SIM_BASE_PTR->SCGC6 |= SIM_SCGC6_TPM0_MASK;
    SIM_BASE_PTR->SOPT2 |= SIM_SOPT2_TPMSRC(1);

    TPM2_BASE_PTR->SC = TPM_SC_CMOD(1) | TPM_SC_PS(7);
    TPM2_BASE_PTR->MOD = 1875;
    TPM0_BASE_PTR->SC = TPM_SC_CMOD(1) | TPM_SC_PS(7);
    TPM0_BASE_PTR->MOD = 1875;

    SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTB_MASK;
    SIM_BASE_PTR->SCGC5 |= SIM_SCGC5_PORTD_MASK;
    PORTB_BASE_PTR->PCR[18] = PORTB_BASE_PTR->PCR[19] = PORT_PCR_MUX(3);
    PORTD_BASE_PTR->PCR[1]=PORT_PCR_MUX(4);

      TPM2_BASE_PTR->CONTROLS[0].CnSC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSA_MASK;
      TPM2_BASE_PTR->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSA_MASK;
      TPM0_BASE_PTR->CONTROLS[1].CnSC = TPM_CnSC_MSB_MASK |TPM_CnSC_ELSA_MASK;
}

void LED_Control(uint8_t Character)
{
      if(Character=='w' && value<1000)
      {
    	  value+=100;

      }
      else if(Character=='s' && value>0)
       {
             value-=100;
        }

      else if(Character=='a')
            {
          	 LEDColour++;
          	 if(LEDColour>=8)
          	 {
          		 LEDColour=0;
          	 }

            }
      else if(Character=='d')
             {
              LEDColour--;
               if(LEDColour==0)
                {



            		   LEDColour=7;


                }
              }
      LEDFunction(LEDColour, value);

}

LEDFunction(LEDColour_t LEDColour, uint16_t Brightness)
{
 if(LEDColour==RED)
    {
	TPM2_BASE_PTR->CONTROLS[0].CnV = Brightness;
	TPM2_BASE_PTR->CONTROLS[1].CnV = 0;
	TPM0_BASE_PTR->CONTROLS[1].CnV = 0;
	}
	else if(LEDColour==YELLOW)
	{
	TPM2_BASE_PTR->CONTROLS[0].CnV = TPM2_BASE_PTR->CONTROLS[1].CnV = Brightness;
	TPM0_BASE_PTR->CONTROLS[1].CnV = 0;
	}
	else if(LEDColour==GREEN)
	{
	TPM2_BASE_PTR->CONTROLS[1].CnV = Brightness;
	TPM2_BASE_PTR->CONTROLS[0].CnV = 0;
	TPM0_BASE_PTR->CONTROLS[1].CnV = 0;
	}
	else if(LEDColour==BLUE)
	{
	TPM0_BASE_PTR->CONTROLS[1].CnV = Brightness;
	TPM2_BASE_PTR->CONTROLS[1].CnV = 0;
	TPM2_BASE_PTR->CONTROLS[0].CnV = 0;
	}
	else if(LEDColour==MAGENTA)
	{
	TPM2_BASE_PTR->CONTROLS[0].CnV = TPM0_BASE_PTR->CONTROLS[1].CnV = Brightness;
	TPM2_BASE_PTR->CONTROLS[1].CnV = 0;
	}
	else if(LEDColour==CYAN)
	{
	TPM2_BASE_PTR->CONTROLS[1].CnV = TPM0_BASE_PTR->CONTROLS[1].CnV = Brightness;
	TPM2_BASE_PTR->CONTROLS[0].CnV = 0;
	}
	else if(LEDColour==WHITE)
	{
	TPM2_BASE_PTR->CONTROLS[1].CnV = TPM2_BASE_PTR->CONTROLS[0].CnV=TPM0_BASE_PTR->CONTROLS[1].CnV = Brightness;
	}
	else if(LEDColour==OFF)
	{
		TPM2_BASE_PTR->CONTROLS[0].CnV = 0;
		TPM2_BASE_PTR->CONTROLS[0].CnV = 0;
		TPM0_BASE_PTR->CONTROLS[1].CnV = 0;

	}
}

