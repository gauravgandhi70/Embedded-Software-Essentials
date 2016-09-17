#include<stdio.h>
#include<stdint.h>

int main(void)
{
    int length=0;
    char input[10];
    printf("Enter a string: ");
    gets(input);
    my_atoi(input);
    
	
    char buf[10]={"ABCD"};
    dump_memory(buf,2);
   
    int x;
    int num;
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
