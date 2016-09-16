#include<stdio.h>
#include<stdint.h>
#include<memory.h>
int8_t my_memzero(uint8_t *src,uint32_t length);
void main()
{
    uint32_t length;

	uint8_t source[50],destination[50];
	
	    printf("enter the array \t");
		scanf ("%[^\n]%*c",source);

    printf("Enter the number of bytes that you want to  \t");
    scanf("%d",&length);
    my_memzero(source,length);
}



