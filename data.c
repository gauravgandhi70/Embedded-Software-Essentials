#include<stdint.h>
#include"data.h"

int32_t my_atoi(int8_t *str)                              //Function definition for ascii string to integer function
{
   printf("string:%s\n",str);                             //Prints the input string
   int32_t i=0;                                           
   int32_t length=0;                                      //Initialising length of the string to zero
   while(*(str+i)!='\0')                                  //Calculate the length of the string by incrementing length till the string reaches the null character
   {
       length++;
       i++;
   }
	
   printf("length is: %d\n",length);                      //Displaying the length of the string
   for(i=0;i<length;i++)                                  //Converts the ascii character of each character in the string to its corresponding integer value
   {
       printf("%d",*(str+i));                             //Displays the integer value of the input string
   }
}

void dump_memory(uint8_t *start, uint32_t length)         //Function definition for printing hex output of the data bytes in the memory given pointer to a memory location & length of bytes to print
{
   int32_t i;
   for(i=0;i<length;i++)                                  
   {
      printf("%x\t",*(start+i));                          //Prints the hex value of number of bytes given in the length
	
	
   }
	
}

uint32_t big_to_little(uint32_t data)                    //Function definition for converting data from big endian to little endian 
{
   int32_t z = 1;                                        //Initialising the value of z to one to check endianess
   int8_t *y = (int8_t*)&z;                              //To check the byte in lower memory address
   printf("The value in  lower memory is:%c\n",*y+48);   //Displays the value in lower memory address
  
   if((*y+48)=='0')                                      //If the byte in lower memory address is zero, then it is big endian hence convert it  to little endian
   {
       data = ( data >> 24 ) | (( data << 8) & 0x00ff0000 )| ((data >> 8) & 0x0000ff00) | ( data << 24)  ; //Bitwise shifting for the conversion
       printf("Little endian data is  = %x\n", data);    //Displays the converted little endian data
   }
   
   else
       printf("The data is already stored as little endian\n");

}

uint32_t little_to_big(uint32_t data)                    //Function definition for converting data from little endian to big endian
{
   int32_t z = 1;                                        //Initialising the value of z to one to check endianess
   int8_t *y = (int8_t*)&z;                              //To check the byte in lower memory address
   printf("The value in  lower memory is:%c\n",*y+48);   //Displays the value in lower memory address
  
   if((*y+48)=='1')                                      //If the byte in lower memory address is one, then it is little endian hence convert it to big endian
   {
   
       data = ( data >> 24 ) | (( data << 8) & 0x00ff0000 )| ((data >> 8) & 0x0000ff00) | ( data << 24)  ; //Bitwise shifting for the conversion
       printf("Big endian data is = %x\n", data);         //Displays the converted big endian data
   }
 
   else
       printf("The data is already stored as big endina\n");
}
