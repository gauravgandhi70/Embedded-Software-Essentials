#include "MKL25Z4.h"
#include<stdio.h>
#include<stdint.h>
#include "I2C.h"


void I2C_init(void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTC_MASK;	//Set clock for portC
	SIM_SCGC4 |= SIM_SCGC4_I2C0_MASK;	//set clock for I2c module

	PORTC_PCR8 |= PORT_PCR_MUX(2);		//Select alternate function as I2C0_SCL
	PORTC_PCR9 |= PORT_PCR_MUX(2);		//select alternate funtion as I2C0_SDA

	I2C0_C1 = 0;						//Turn off I2C
	I2C0_S |= I2C_S_IICIF_MASK;			//clear interrupt flag
	I2C0_F |= I2C_F_ICR(0x14);			//Divide bus clock of 24Mhz with 64 to get 375Khz
	I2C0_C1 |= I2C_C1_IICEN_MASK;		//enable I2C
}

void I2C_WriteRegister(uint8_t u8SlaveAddress, uint8_t u8RegisterAddress, int8_t u8Data)
{
	I2C_Start();	          
	I2C0_D = u8SlaveAddress << 1;									/* Send I2C device address with W/R bit = 0 */
	while((I2C0_S & I2C_S_TCF_MASK)==0);
	while(!(I2C0_S & I2C_S_RXAK_MASK)==0);
	I2C_Wait();

	I2C0_D = u8RegisterAddress;										/* Send register address */
	while((I2C0_S & I2C_S_TCF_MASK)==0);
	while(!(I2C0_S & I2C_S_RXAK_MASK)==0);
	I2C_Wait();

	I2C0_D = u8Data;												/* Send the data */
	while((I2C0_S & I2C_S_TCF_MASK)==0);
	while(!(I2C0_S & I2C_S_RXAK_MASK)==0);
	I2C_Wait();

	I2C_Stop();

    Pause(50);
}

uint8_t I2C_ReadRegister(uint8_t u8SlaveAddress, uint8_t u8RegisterAddress)
{
	uint8_t result;
	  
	I2C_Start();	          
	I2C0_D = u8SlaveAddress << 1;									/* Send I2C device address with W/R bit = 0 */
	while((I2C0_S & I2C_S_TCF_MASK)==0);
	I2C_Wait();

	I2C0_D = u8RegisterAddress;										/* Send register address */
	while((I2C0_S & I2C_S_TCF_MASK)==0);
	I2C_Wait();

	I2C_RepeatedStart();
	
	I2C0_D = (u8SlaveAddress << 1) | 0x01;							/* Send I2C device address this time with W/R bit = 1 */ 
	while((I2C0_S & I2C_S_TCF_MASK)==0);
	I2C_Wait();

	I2C_EnterRxMode();
	I2C_DisableAck();

	result = I2C0_D;												
	I2C_Wait();
	I2C_Stop();  
	result = I2C0_D;
	Pause(50);
	return result;
}

void I2C_ReadMultiRegisters(uint8_t u8SlaveAddress, uint8_t u8RegisterAddress, uint8_t n, uint8_t *r)
{
	int8_t i;
	
	I2C_Start();	          
	I2C0_D = u8SlaveAddress << 1;									/* Send I2C device address with W/R bit = 0 */
	I2C_Wait();										

	I2C0_D = u8RegisterAddress;										/* Send register address */
	I2C_Wait();

	I2C_RepeatedStart();
		
	I2C0_D = (u8SlaveAddress << 1) | 0x01;							/* Send I2C device address this time with W/R bit = 1 */ 
	I2C_Wait();	

	I2C_EnterRxMode();
	I2C_EnableAck();
	
	i = I2C0_D;
	I2C_Wait();
	
	for(i=0; i<n-2; i++) 
	{
	    *r = I2C0_D;
	    r++;
	    I2C_Wait();
	}
	
	I2C_DisableAck();
	*r = I2C0_D;
	r++;
	I2C_Wait();
	I2C_Stop();
	*r = I2C0_D; 
	Pause(50);		
}

void Pause(int number)
{
	int cnt;
	for(cnt=0; cnt<number; cnt++)
	{
		//asm("nop");
	};
}
