#include<stdio.h>
#include<stdint.h>

int8_t my_memzero(uint8_t *src,uint32_t length);
void main()
{
    uint32_t length;

	uint8_t source[50],destination[50];
	
	    printf("enter the array \t");
		scanf ("%[^\n]%*c",source);

    printf("Enter the number of bytes that you want to move \t");
    scanf("%d",&length);
    my_memzero(source,length);
}


int8_t my_memzero(uint8_t *src, uint32_t length)
{
    uint16_t i=0,len=0;
	while(*(src+i)!='\0')
	{
		len++;
		i++;
	}
	i=0;
    if(src)
    {
    while(i<length)
    {
        *(src+i)=0;
        i++;
    }
    i=0;
    printf(" \n New String is \t");
	while(i<len)
	{
		printf("%c",*(src+i));
		i++;
	}

    }
	return 0;
}


