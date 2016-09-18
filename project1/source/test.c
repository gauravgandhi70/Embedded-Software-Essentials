#include<stdio.h>
#include<stdint.h>
#include"memory.h"

void main()
{
    uint32_t length;
    uint8_t source[50],destination[50];
    
    printf("enter the array \t");
    scanf ("%[^\n]%*c",source);

    printf("Enter the number of bytes that you want to reverse \t");
    scanf("%d",&length);
    
    my_memmove(source, destination, length);
    my_memzero(source, length);
    my_reverse(source, length);
}


