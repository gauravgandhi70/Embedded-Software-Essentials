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




