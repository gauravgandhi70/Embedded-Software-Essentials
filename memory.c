#include<stdio.h>
#include<stdint.h>
#include"memory.h"

int8_t my_memmove(uint8_t *src, uint8_t *dst, uint32_t length)
{   
    uint32_t i=0,len=0;
    uint8_t temp[50];

    if(src)
        {
 
            copying_LOOP(i,length,src,temp);
            
            i=0;
            
            copying_LOOP(i,length,temp,dst);
            printf(" \n Source is at : %p new string at destination %p \t",src,dst);
            i=0;

            while(i<length)
		  {
			   printf("%c",*(dst+i));
                           i++;
		  }
            return 0;
        }
    else
       {
            printf("Pointer ERROR");
            return 1;
       }

}



