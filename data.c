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
