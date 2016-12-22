/*
 * accelerometer.h
 *
 *  Created on: 08-Dec-2016
 *      Author: Gaurav
 */

#ifndef INCLUDES_ACCELEROMETER_H_
#define INCLUDES_ACCELEROMETER_H_

/******************************************************************************
* Constants and macros
******************************************************************************/

//MMA8451Q Registers

#define STATUS_REG            0x00		// STATUS Register

#define OUT_X_MSB_REG         0x01		// [7:0] are 8 MSBs of the 14-bit X-axis sample
#define OUT_X_LSB_REG         0x02		// [7:2] are the 6 LSB of 14-bit X-axis sample
#define OUT_Y_MSB_REG         0x03		// [7:0] are 8 MSBs of the 14-bit Y-axis sample
#define OUT_Y_LSB_REG         0x04		// [7:2] are the 6 LSB of 14-bit Y-axis sample
#define OUT_Z_MSB_REG         0x05		// [7:0] are 8 MSBs of the 14-bit Z-axis sample
#define OUT_Z_LSB_REG         0x06		// [7:2] are the 6 LSB of 14-bit Z-axis sample

#define F_SETUP_REG           0x09    	// F_SETUP FIFO Setup Register
#define TRIG_CFG_REG          0x0A    	// TRIG_CFG Map of FIFO data capture events
#define SYSMOD_REG            0x0B    	// SYSMOD System Mode Register
#define INT_SOURCE_REG        0x0C    	// INT_SOURCE System Interrupt Status Register
#define WHO_AM_I_REG          0x0D    	// WHO_AM_I Device ID Register
#define XYZ_DATA_CFG_REG      0x0E    	// XYZ_DATA_CFG Sensor Data Configuration Register
#define HP_FILTER_CUTOFF_REG  0x0F    	// HP_FILTER_CUTOFF High Pass Filter Register

#define PL_STATUS_REG         0x10    	// PL_STATUS Portrait/Landscape Status Register
#define PL_CFG_REG            0x11    	// PL_CFG Portrait/Landscape Configuration Register
#define PL_COUNT_REG          0x12    	// PL_COUNT Portrait/Landscape Debounce Register
#define PL_BF_ZCOMP_REG       0x13    	// PL_BF_ZCOMP Back/Front and Z Compensation Register
#define P_L_THS_REG           0x14    	// P_L_THS Portrait to Landscape Threshold Register

#define FF_MT_CFG_REG         0x15    	// FF_MT_CFG Freefall and Motion Configuration Register
#define FF_MT_SRC_REG         0x16    	// FF_MT_SRC Freefall and Motion Source Register
#define FT_MT_THS_REG         0x17    	// FF_MT_THS Freefall and Motion Threshold Register
#define FF_MT_COUNT_REG       0x18    	// FF_MT_COUNT Freefall Motion Count Register

#define TRANSIENT_CFG_REG     0x1D    	// TRANSIENT_CFG Transient Configuration Register
#define TRANSIENT_SRC_REG     0x1E    	// TRANSIENT_SRC Transient Source Register
#define TRANSIENT_THS_REG     0x1F    	// TRANSIENT_THS Transient Threshold Register
#define TRANSIENT_COUNT_REG   0x20    	// TRANSIENT_COUNT Transient Debounce Counter Register

#define PULSE_CFG_REG         0x21    	// PULSE_CFG Pulse Configuration Register
#define PULSE_SRC_REG         0x22    	// PULSE_SRC Pulse Source Register
#define PULSE_THSX_REG        0x23    	// PULSE_THS XYZ Pulse Threshold Registers
#define PULSE_THSY_REG        0x24
#define PULSE_THSZ_REG        0x25
#define PULSE_TMLT_REG        0x26    	// PULSE_TMLT Pulse Time Window Register
#define PULSE_LTCY_REG        0x27    	// PULSE_LTCY Pulse Latency Timer Register
#define PULSE_WIND_REG        0x28    	// PULSE_WIND Second Pulse Time Window Register

#define ASLP_COUNT_REG        0x29    	// ASLP_COUNT Auto Sleep Inactivity Timer Register

#define CTRL_REG1             0x2A    	// CTRL_REG1 System Control 1 Register
#define CTRL_REG2             0x2B    	// CTRL_REG2 System Control 2 Register
#define CTRL_REG3             0x2C    	// CTRL_REG3 Interrupt Control Register
#define CTRL_REG4             0x2D    	// CTRL_REG4 Interrupt Enable Register
#define CTRL_REG5             0x2E    	// CTRL_REG5 Interrupt Configuration Register

#define OFF_X_REG             0x2F    	// XYZ Offset Correction Registers
#define OFF_Y_REG             0x30
#define OFF_Z_REG             0x31

//MMA8451Q 7-bit I2C address

#define MMA845x_I2C_ADDRESS   0x1D		// SA0 pin = 1 -> 7-bit I2C address is 0x1D

//MMA8451Q Sensitivity at +/-2g

#define SENSITIVITY_2G		  4096

#define PI					  3.14159

#define PositiveHighRange     4200
#define PositiveLowRange      3000
#define NegativeHighRange     -3000
#define NegativeLowRange     -4200


/******************************************************************************
* Global variables
******************************************************************************/

uint8_t AccData[6],acc_flag;
short Xout_14_bit, Yout_14_bit, Zout_14_bit;
float Xout_g, Yout_g, Zout_g;
uint8_t Xoffset, Yoffset, Zoffset;

/******************************************************************************
* Functions
******************************************************************************/

void MCU_Init(void);
void Accelerometer_Init (void);
void Calibrate(void);
void ACCELEROMETER_control();

#endif /* INCLUDES_ACCELEROMETER_H_ */
