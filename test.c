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


int8_t my_reverse(char *src, int length)
{
    uint16_t i=0,counter;
    
    if(src)
     {
    
      int8_t temp;
      for (counter=0;counter<(length/2);counter++)
       {
         temp=*(src+counter);
         *(src+counter)=*(src+length-counter-1);
         *(src+length-counter-1)=temp;
       }
       printf("\n Reveresed string is \t");
       while(i<length)
         {
           printf("%c",*(src+i));
           i++;
         }
	  return 0;
       }
    else
       {
         return 1;
       }
     

}

