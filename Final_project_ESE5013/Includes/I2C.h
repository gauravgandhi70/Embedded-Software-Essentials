#define I2C_DisableAck()       I2C0_C1 |= I2C_C1_TXAK_MASK
#define I2C_EnableAck()        I2C0_C1 &= ~I2C_C1_TXAK_MASK
#define I2C_RepeatedStart()    I2C0_C1 |= I2C_C1_RSTA_MASK
#define I2C_EnterRxMode()      I2C0_C1 &= ~I2C_C1_TX_MASK
#define I2C_write_byte(data)   I2C0_D = data

#define I2C_Start()            I2C0_C1 |= I2C_C1_TX_MASK;\
                               I2C0_C1 |= I2C_C1_MST_MASK

#define I2C_Stop()             I2C0_C1 &= ~I2C_C1_MST_MASK;\
                               I2C0_C1 &= ~I2C_C1_TX_MASK

#define I2C_Wait()             while((I2C0_S & I2C_S_IICIF_MASK)==0) {} \
                               I2C0_S |= I2C_S_IICIF_MASK;

void I2C_WriteRegister(uint8_t u8SlaveAddress, uint8_t u8RegisterAddress, /*unsigned*/ int8_t u8Data);
uint8_t I2C_ReadRegister(uint8_t u8SlaveAddress, uint8_t u8RegisterAddress);
void I2C_ReadMultiRegisters(uint8_t u8SlaveAddress, uint8_t u8RegisterAddress, uint8_t n, uint8_t *r);
