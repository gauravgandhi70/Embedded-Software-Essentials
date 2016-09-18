#include<stdio.h>
#include<stdint.h>
#include"memory.h"
#include"data.h"

uint32_t main()

{
    uint32_t length;                                                             
    uint8_t source[50];

    printf("enter the array \t");
    scanf ("%[^\n]%*c",source);                                                 //Input an array

    printf("Enter the number of bytes that you want to reverse \t");            
    scanf("%d",&length);                                                        //Input the length
    my_reverse(source,length);                                                  //Function call for reverse
    
    return 1;

}


