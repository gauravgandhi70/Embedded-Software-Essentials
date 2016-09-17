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
    
    return 0;
}
