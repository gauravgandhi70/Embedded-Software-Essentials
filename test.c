#include<stdio.h>
#include<stdint.h>
#include"memory.h"
int8_t my_memmove(uint8_t *src, uint8_t *dst, uint32_t length);
void main()
{
    uint32_t length;

	uint8_t source[50],destination[50];
	
	    printf("enter the array \t");
		scanf ("%[^\n]%*c",source);

    printf("Enter the number of bytes that you want to move \t");
    scanf("%d",&length);
    my_memmove(source,destination,length);
}

int8_t my_memmove(uint8_t *src, uint8_t *dst, uint32_t length)
{   uint32_t i=0,len=0;
    uint8_t temp[50];

    if(src)
        {
       while(i<length)
       {
           *(temp+i)=*(src+i);
           i++ ;
       }
        i=0;

       while(i<length)
       {
           *(dst+i)=*(temp+i);
           i++ ;
       }
       
      

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

