#include<stdio.h>
#include"hw1.h"
char reverse(char * str, int length);
void main()
{
    int len,counter,b;
    printf("enter the length of the array \t");
    scanf("%d",&len);
    char ret,array[len];
	
        printf("enter the array \t");
        scanf("%s",array);
  
    ret=reverse(array,len);
    if (ret==0)
    {
        printf("Array reverse successful \n");
        for(counter=0;counter<len;counter++)
    {
        printf("%d \n",*(array+counter));
    }
    }
    else
    {
        printf("Array reverse failed \n");
    }

}
