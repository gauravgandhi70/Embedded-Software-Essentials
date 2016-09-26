#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include"circbuf.h"


int main()
{
cirbuf_t b;
b.buff=b.data;
b.head=b.data;
b.tail=b.data;
b.length=MAX_LEN;
state st;
    int i,d,j;
    char c;

        while(1)
        {
       printf("enter the choice : \n 1. Add  \t 2. Remove \t 3. Print buffer \n");
       scanf("%d",&i);
            getchar();

       if(i==1)
       {
           printf("enter a character to add \t");
           scanf("%c",&c);
           st=add_data(&b,c);
       }
       else if(i==2)
        {
           st=remove_data(&b);

        }
        else if(i==3)
            {
                for(d=0;d<b.length;d++)
                {
                 printf("%c \t",*(b.buff+d));
                }

            }
        else
        {
            printf("\n Enter valid input");
        }

            if(st==0 )
            {
                printf(" \t error buffer full \n");
            }
            else if(st==1)
            {
                printf("\t error buffer empty \n");
            }
        }
   return 10;

}

