#include<stdio.h>
#include<stdint.h>
#include"memory.h"
int8_t my_reverse(char *src, int length);
void main()
{
    uint32_t length;

	uint8_t source[50],destination[50];
	
	    printf("enter the array \t");
		scanf ("%[^\n]%*c",source);

    printf("Enter the number of bytes that you want to reverse \t");
    scanf("%d",&length);
    my_reverse(source,length);
}


