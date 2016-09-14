#include<stdio.h>
#include"hw1.h"
char reverse(char *str, int length)
{
    int i=0,counter;
    while(*(str+i)!='\0')
    {
	i++;
    }
    if((*(str+length)=='\0')&&(length>0)&&(i==length))
    {
    
    char temp;
    for (counter=0;counter<(length/2);counter++)
    {
      temp=*(str+counter);
      *(str+counter)=*(str+length-counter-1);
      *(str+length-counter-1)=temp;
    }
	return 0;
    }
    else
    {
     return 1;
    }


}
