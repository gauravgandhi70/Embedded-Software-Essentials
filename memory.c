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

int8_t my_memzero(uint8_t *src, uint32_t length)
{
   uint16_t i=0,len=0;
   while(*(src+i)!='\0')
   {
       len++;
       i++;
   }
	
   i=0;
   if(src)
   {
       while(i<length)
       {
           *(src+i)=0;
           i++;
       }
        
       i=0;
       printf(" \n New String is \t");
       while(i<len)
       { 
           printf("%c",*(src+i));
           i++;
       }
        
       printf("\n"); 

       return 0;
   }
	 
   else
   {
       printf("Pointer Error");
       return 1;
   } 
}

int8_t my_reverse(char *src, int length)
{
    uint16_t i=0,counter;
    
    if(src)
     {
    
      int8_t temp;
      for (counter=0;counter<(length/2);counter++)
       {
         temp=*(src+counter);
         *(src+counter)=*(src+length-counter-1);
         *(src+length-counter-1)=temp;
       }
       printf("\n Reveresed string is \t");
       while(i<length)
         {
           printf("%c",*(src+i));
           i++;
         }
	  return 0;
       }
    else
       {
         return 1;
       }
     

}


