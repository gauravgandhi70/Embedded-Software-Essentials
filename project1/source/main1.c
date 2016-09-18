#include<stdio.h>
#include<stdint.h>

uint32_t main(void)
{
    uint32_t length=0;                      //Initialising the length of the string to zero
    int8_t input[10];                       //Declaration of the input array 
    printf("Enter a string: ");       
    gets(input);                            //Obtains the input string from the user
    my_atoi(input);                         //Function call for ascii string to integer conversion
    
	
    int8_t buf[10]={"ABCD"};                //Input string 
    dump_memory(buf,2);                     //Function call for printing hex output of the bytes
   
    uint32_t  x;                            
    uint32_t  num;
    printf("Enter a 32 bit number:\t");
    scanf("%x",&num);                       //Obtains 32 bit input from the user 
    x=num;                                  
    big_to_little(x);                       //Function call to convert from big endian to little endian 
    
    printf("Enter a 32 bit number:\t");
    scanf("%x",&num);                       //Obtains 32 bit input from the user
    x=num;
    little_to_big(x);                       //Function call to convert from little endian to big endian
   
    char str[100];                          //Declaration of ascii string
    itoa(-1,str,2);                         //Function call to convert integer to ascii string

    return 0;        
}
