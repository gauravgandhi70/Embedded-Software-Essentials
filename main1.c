#include<stdio.h>
#include<stdint.h>

uint32_t main(void)
{
    uint32_t length=0;
    int8_t input[10];
    printf("Enter a string: ");
    gets(input);
    my_atoi(input);
    
	
    int8_t buf[10]={"ABCD"};
    dump_memory(buf,2);
   
    uint32_t  x;
    uint32_t  num;
    printf("Enter a 32 bit number:\t");
    scanf("%x",&num);
    x=num;
    big_to_little(x);
    
    printf("Enter a 32 bit number:\t");
    scanf("%x",&num);
    x=num;
    little_to_big(x);

    return 0;
}
