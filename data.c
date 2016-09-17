#include<stdint.h>
#include"data.h"

int my_atoi(char *str)
{
   printf("string:%s\n",str);
   int i=0;
   int length=0;
   while(*(str+i)!='\0')
   {
       length++;
       i++;
   }
	
   printf("length is: %d /n",length);
   for(i=0;i<length;i++)
   {
       printf(" %d",*(str+i));
   }
}

void dump_memory(uint8_t *start, uint32_t length)
{
   int i;
   for(i=0;i<length;i++)
   {
      printf("%x \t",*(start+i));
	
	
   }
	
}

uint32_t big_to_little(uint32_t data)
{
   int z = 1;
   char *y = (char*)&z;
   printf("The value in  lower memory is:%c\n",*y+48);   
  
   if((*y+48)=='0')
   {
       data = ( data >> 24 ) | (( data << 8) & 0x00ff0000 )| ((data >> 8) & 0x0000ff00) | ( data << 24)  ; 
       printf("value = %x", data); 
   }

}

uint32_t little_to_big(uint32_t data)
{
   int z = 1;
   char *y = (char*)&z;
   printf("The value in  lower memory is:%c\n",*y+48);   
  
   if((*y+48)=='1')
   {
   
      data = ( data >> 24 ) | (( data << 8) & 0x00ff0000 )| ((data >> 8) & 0x0000ff00) | ( data << 24)  ; 
      printf("value = %x", data); 
   }

}
