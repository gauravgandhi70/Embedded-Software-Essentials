#include<stdio.h>
#include<stdint.h>

int main(void)
{
    int length=0;
    char input[10];
    printf("Enter a string: ");
    gets(input);
    my_atoi(input);
    return 0;
}
