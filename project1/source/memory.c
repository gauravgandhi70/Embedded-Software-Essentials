#include<stdio.h>
#include<stdint.h>
#include"memory.h"

int8_t my_memmove(uint8_t *src, uint8_t *dst, uint32_t length)                               //Function definition to move data from one location to other location
{   
    uint32_t i=0;
    uint8_t temp[50];

    if(src)
    {
 
        copying_LOOP(i,length,src,temp);                                                     //Copies data from source  to temp array
        i=0;
        copying_LOOP(i,length,temp,dst);                                                     //Copies data from temp array to destination

        printf(" \n Source is at : %p new string at destination %p \t",src,dst);             //Prints the address to which source and destination pointer refer
        i=0;

        while(i<length)
        {
            printf("%c",*(dst+i));                                                           //Displays the transferred data in destination
            i++;
        }
            return 0;
    }
    
    else
    {
        printf("Pointer ERROR");                                                             //Displays an error if move failed
        return 1;
   }

}

int8_t my_memzero(uint8_t *src, uint32_t length)                                             //Function definition to zero out given length of bytes in the memory
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
        printf(" \n New String is \t");
	    
        while(i<len)
 	{ 
            printf("%c",*(src+i));                                                           //Displays the new string after clearing a certain part of memory
            i++;
        }
        
        printf("\n"); 

        return 0;
    }
	 
    else
    {
        printf("Pointer Error");                                                             //Displays an error if function fails
        return 1;
    } 
}

int8_t my_reverse(char *src, int length)                                                     //Function definition for reverse function
{
    uint16_t i=0,counter;
    
    if(src)
    {
        int8_t temp;
        for (counter=0;counter<(length/2);counter++)
        {
           temp=*(src+counter);                                                             //Performs the reverse operation  using a temporary variable
           *(src+counter)=*(src+length-counter-1);
           *(src+length-counter-1)=temp;
        }
       
        printf("\n Reveresed string is \t");
        while(i<length)
        {
            printf("%c",*(src+i));                                                          //Displays the reverse string
            i++;
        }
	
        return 0;
    } 
    
    else
    {
        return 1;
    }
     
}


