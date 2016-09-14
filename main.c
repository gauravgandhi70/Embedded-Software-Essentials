#include<stdio.h>
#include"hw1.h"
char reverse(char * str, int length);
void main()
{
    int len=0,counter,b;
    
	char array[50],ret;		
        printf("enter the array \t");
		scanf ("%[^\n]%*c", array);
	
		printf(" \n Array before reversing  \n ");
	while(*(array+len)!='\0')
		{	
			printf("%c",*(array+len));			
			len++;
		}
		printf("\n");
		
			
					

    ret=reverse(array,len);
    if (ret==0)
    {
		counter=0;
        printf("Array reverse successful \n Array After Reversing :");
        while(*(array+counter)!='\0')
		{
			printf("%c",*(array+counter));
			counter++;
		}
		printf("\n");
    }
    else
    {
        printf("Array reverse failed \n");
    }

}
