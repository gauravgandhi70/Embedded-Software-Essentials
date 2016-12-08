/*
 * sdcard.c
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
#include"profile.h"
#include"SPI.h"
#include"sdcard.h"

/*-----------------------------------------------------------------------------------------
                                void sdcard_init()
 ------------------------------------------------------------------------------------------
 * I/P Arguments: none
 * Return value	: none

 * description: Used for initial setup of the SD card. SD card used is Transcend 2 GB micro SD card (Standard Capacity)
 Commands Used: cmd0, cmd8, cmd58, cmd55, acmd41.
-----------------------------------------------------------------------------------------*/


uint8_t sdcard_init()
{
    int i=0;
    uint8_t response=0xFF,r[3]={0x14,0,0};
    for(i=0;i<100000;i++){;}

    PTC_BASE_PTR->PSOR =  1<<4; //Chip select high
    for(i=0;i<10;i++)
    {
        SPI_write(0xFF);
    }

    PTC_BASE_PTR->PCOR = 1<<4; //Chip select low

  while(response != 0x01 && i<500)
    {
      response = cmd_zero();
      i++;
    }
    if(i==500)
    {
        LOG0("\n\r SD Card Initialization failed");
        return 0;
    }


    cmd_eight();

    cmd_feight();





      response= 0xFF;i=0;
     while(response != 0 && i<500)
     {
         response = cmd_fiftyfive();
             acmd();

          i++;
    }

     if(response==0)
     {

           LOG0("\n\r SD Card Initialization Successful");

     }
     else
    {
        LOG0("\n\r SD Card Initialization Failed");
        return 0;
    }


     //cmd_sixteen();
    // LOG0("\n\r Timing for 512 bytes transfer");
    // pit_enable();
     // sdcard_write_block(r,sd_data);
     // pit_disable();
     // get_time();
     // delay_ms(10);
     //sdcard_read_block(r);


      return 1;

}


/*-----------------------------------------------------------------------------------------
                                void cmd_zero()
 ------------------------------------------------------------------------------------------
 * I/P Arguments: none
 * Return value	: Response from the sd card to command zero

 * description: Used for Reseting the SD card and to put it in SPI mode
-----------------------------------------------------------------------------------------*/
uint8_t cmd_zero()
{
    uint8_t cmd[7]={0x40,0,0,0,0,0x95,0xFF},resp=0;			// Data bytes of the cmd0
    int i=0;
    PTC_BASE_PTR->PCOR = 1<<4; //Chip select low


    for(i=0;i<7;i++)							// Write command
    {
        SPI_write(cmd[i]);
    }

    i=0;
    while(((resp != 0x01) ) & i<2)				// Wait for response for 16 clock cycles
    {
        resp = SPI_write(0XFF);
        i++;
    }


    PTC_BASE_PTR->PSOR =  1<<4; //Chip select high

    return resp;							// Return Response from the sd card
}

/*-----------------------------------------------------------------------------------------
                                void cmd_eight()
 ------------------------------------------------------------------------------------------
 * I/P Arguments: none
 * Return value	: Response from the sd card to command eight

 * description: Used for Reading 40 bit status register of the SD card 
-----------------------------------------------------------------------------------------*/
uint8_t cmd_eight()
{
     uint8_t cmd[6]={0x48,0,0,1,0xAA,0x87},resp;				// Data bytes of the command
    int i=0;
    PTC_BASE_PTR->PCOR = 1<<4; //Chip select low


    for(i=0;i<6;i++)
    {
        SPI_write(cmd[i]);									// Write command to SD card
    }

    i=0;

    //LOG0("\n\r cmd8 : ");
    while(i<6)
    {
        resp = SPI_write(0XFF);								// Get 40 bit response from the SD card
        i++;
        //   LOG0("\t %x",resp);
    }


    PTC_BASE_PTR->PSOR =  1<<4; //Chip select high

    return resp;
}

/*-----------------------------------------------------------------------------------------
                                void cmd_feight()
 ------------------------------------------------------------------------------------------
 * I/P Arguments: none
 * Return value	: Response from the sd card to command fifty eight

 * description: Used for Reading 40 bit status register of the SD card 
-----------------------------------------------------------------------------------------*/
 uint8_t cmd_feight()
 {
      uint8_t cmd[6]={0x7A,0,0,0,0,0x75},resp=0;
    int i=0;
    PTC_BASE_PTR->PCOR = 1<<4; //Chip select low


    for(i=0;i<6;i++)
    {
        SPI_write(cmd[i]);
    }

    i=0;
    //  LOG0("\n\r cmd58 OCR: ");
    while(i<11)
    {
        resp = SPI_write(0XFF);
        i++;
      //  LOG0("\t %x",resp);
    }


    PTC_BASE_PTR->PSOR =  1<<4; //Chip select high

    return resp;
 }
/*-----------------------------------------------------------------------------------------
                                void cmd_fiftyfive()
 ------------------------------------------------------------------------------------------
 * I/P Arguments: none
 * Return value	: Response from the sd card to command 55

 * description: Used before sending application specific commands(acmd). Its respose i used to check if SD card is 
 in idle mode or working mode
-----------------------------------------------------------------------------------------*/


uint8_t cmd_fiftyfive()
 {
      uint8_t cmd[6]={0x77,0,0,0,0,0x95},resp=1;
    int i=0;
    PTC_BASE_PTR->PCOR = 1<<4; //Chip select low

    for(i=0;i<6;i++)
    {
        SPI_write(cmd[i]);
    }

    i=0;
    //LOG0("\n\r cmd55: ");
    while(resp!=0 & i<3)
    {
        resp = SPI_write(0XFF);
       // LOG0("%x",resp);
        i++;
   }



    return resp;
 }

 /*-----------------------------------------------------------------------------------------
                                void acmd()
 ------------------------------------------------------------------------------------------
 * I/P Arguments: none
 * Return value	: Response from the SD card to acmd41.

 * description: Used for putting SD card out of idle. 
-----------------------------------------------------------------------------------------*/
uint8_t acmd(void)
{
    uint8_t cmd[6]={0x69,0,0,0,0,0x5f},resp=1;
    int i=0;
    PTC_BASE_PTR->PCOR = 1<<4; //Chip select low


    for(i=0;i<6;i++)
    {
        SPI_write(cmd[i]);
    }

    i=0;
     // LOG0("\n\r amd41: ");
    while(resp!=0 & i<4)
    {
        resp = SPI_write(0XFF);
           // LOG0("%x",resp);
        i++;
    }




   PTC_BASE_PTR->PSOR =  1<<4; //Chip select high

    return resp;
}



uint8_t cmd_one()
{
     uint8_t cmd[6]={0x41,0,0,0,0,0xff},resp=1;
    int i=0;
    PTC_BASE_PTR->PCOR = 1<<4; //Chip select low


    for(i=0;i<6;i++)
    {
        SPI_write(cmd[i]);
    }

    i=0;

    while(resp!=0 & i<4)
    {
        resp = SPI_write(0XFF);
        i++;
    }


   PTC_BASE_PTR->PSOR =  1<<4; //Chip select high

    return resp;
}

/*-----------------------------------------------------------------------------------------
                                void sdcard_write_block()
 ------------------------------------------------------------------------------------------
 * I/P Arguments: none
 * Return value	: Response from the sd card to write block

 * description: Used for writing single block of 512 bytes of data 
-----------------------------------------------------------------------------------------*/
uint8_t sdcard_write_block(uint8_t *address,uint8_t* da)
{
    uint8_t cmd[6]={0x58,0,0,0x00,0,0xFF},resp=1;    
    int i=0;
     PTC_BASE_PTR->PCOR = 1<<4; //Chip select low

     SPI_write(0x58);								// Write block command 


        SPI_write(*(address+2));					// Address of the start address of the sector
        SPI_write(*(address+1));
        SPI_write(*address);
         SPI_write(0x00);

           SPI_write(0xFF);							// CRC

    i=0;

    while(resp!=0 & i<5)
    {
        resp = SPI_write(0XFF);						// Wait for the response from the SD card
        i++;
           //LOG0("\t cmd24 :%x",resp);
    }




          SPI_write(0xFE);							// Write 0xFE before writing actual data

          for(i=0;i<512;i++)
          {
              SPI_write(*(da+i));					// Write 512 bytes of data
             // LOG0("\t %x", *(da+i));



          }

            SPI_write(0x1D);
           SPI_write(0xAA);


    i=0;
     while(i<10)
    {
        resp = SPI_write(0XFF);
        i++;
        //LOG0("\t write :%x",resp);
    }

    return resp;

}

uint8_t* sdcard_read_block(uint8_t *address)
{
    uint8_t resp=1;
    // uint8_t cmd[6]={0x51,0,0,0,0,0xFF};
    int i=0;
     PTC_BASE_PTR->PCOR = 1<<4; //Chip select low

     SPI_write(0x51);


       SPI_write(*(address+2));
        SPI_write(*(address+1));
        SPI_write(*address);
         SPI_write(0x00);


    SPI_write(0xFF);

    i=0;

    while(i<6)
    {
        resp = SPI_write(0XFF);
        i++;
         //LOG0("\t cmd17 :%x",resp);
    }




          SPI_write(0xFE);
            LOG0("\n\r Read");
          for(i=0;i<518;i++)
          {
              sd_data[i]=SPI_write(0xFF);

               if(i>3)
               {
                   //LOG0("\t %x", sd_read_data[i]);
                  // if((i-4)%16==0){LOG0("\n\r Read");}
               }
          }


    return sd_data;


}




