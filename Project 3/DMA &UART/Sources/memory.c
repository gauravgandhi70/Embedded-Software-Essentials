/*
 * memory.c
 *
 *  Created on: 08-Oct-2016
 *      Author: Admin
 */
#include "MKL25Z4.h"
#include"memory.h"


int8_t my_memmove(uint8_t *src, uint8_t *dst, uint32_t length)                               //Function definition to move data from one location to other location
{
    uint32_t i=0;
    uint8_t temp[5000];

    if(src)
    {



        while(i<length)                                                                     //Copies data from source  to temp array
        {
             *(temp+i)=*(src+i);
             i++;
        }
        i=0;

        while(i<length)                                                                       //Copies data from temp to destination array
        {
             *(dst+i)=*(temp+i);
             i++;
        }





        return 0;


    }

    else
    {

                                                                  //Displays an error if move failed
        return 1;
    }




}

void my_memzero(uint8_t *src, uint32_t length)                                             //Function definition to zero out given length of bytes in the memory
{

    uint16_t i=0,len=0;
    while(*(src+i)!='\0')
    {
        len++;                                                                               //Calculates the total length of the memory
        i++;
    }

    i=0;

    if(src)
    {
        while(i<length)
        {
             *(src+i)=0;                                                                     //Clears the memory i.e sets it to zero for given length of bytes
             i++;
        }

        i=0;
    }



}

int8_t my_reverse(uint8_t *src, uint32_t length)                                                     //Function definition for reverse function
{
    uint16_t counter;

    if(src)
    {
        int8_t temp=0;
        for (counter=0;counter<(length/2);counter++)
        {
           temp=*(src+counter);                                                             //Performs the reverse operation  using a temporary variable
           *(src+counter)=*(src+length-counter-1);
           *(src+length-counter-1)=temp;
        }


        return 0;
    }

    else
    {
        return 1;
    }

}




