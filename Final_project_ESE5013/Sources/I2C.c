#include"MKL25Z4.h"
#include "I2C.h"

void I2C_WriteRegister(uint8_t u8SlaveAddress, uint8_t u8RegisterAddress, /*unsigned*/ int8_t u8Data)
{
	I2C_Start();	          
	I2C0_D = u8SlaveAddress << 1;									/* Send I2C device address with W/R bit = 0 */
	I2C_Wait();

	I2C0_D = u8RegisterAddress;										/* Send register address */
	I2C_Wait();

	I2C0_D = u8Data;												/* Send the data */
	I2C_Wait();

	I2C_Stop();

    Pause(50);
}

uint8_t I2C_ReadRegister(uint8_t u8SlaveAddress, uint8_t u8RegisterAddress)
{
	uint8_t result;
	  
	I2C_Start();	          
	I2C0_D = u8SlaveAddress << 1;									/* Send I2C device address with W/R bit = 0 */
	I2C_Wait();										

	I2C0_D = u8RegisterAddress;										/* Send register address */
	I2C_Wait();

	I2C_RepeatedStart();
	
	I2C0_D = (u8SlaveAddress << 1) | 0x01;							/* Send I2C device address this time with W/R bit = 1 */ 
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
}

void i2c_init()
{
	SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;  // Enable PORT B Gate Clock

	// Set the alternate function for PORTB as UART0
	PORTB_PCR2 = PORT_PCR_MUX(2);
	PORTB_PCR3 = PORT_PCR_MUX(2);

	SIM_SCGC4 |= SIM_SCGC4_I2C0_MASK;   // Enble i2c0 clock

	I2C0_F |= I2C_F_MULT(2)  ;          // Select freq multiplier

	I2C0_C1 |= I2C_C1_IICEN_MASK;       // Enable I2C

	I2C0_C1 |= I2C_C1_MST_MASK;			// Select master mode

	//I2C0_C1 |= I2C_C1_TXAK_MASK;
	I2C0_C1 &= ~I2C_C1_TXAK_MASK;


}

