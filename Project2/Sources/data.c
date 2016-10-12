/*
 * data.c
 *
 *  Created on: 07-Oct-2016
 *      Author: Admin
 */
#include"MKL25Z4.h"
#include"data.h"

int32_t my_atoi(int8_t *str) ;                             //Function definition for ascii string to integer function
void dump_memory(uint8_t *start, uint32_t length) ;
void reverse(int8_t *str, int32_t length);                //Function declaration for reverse
uint32_t big_to_little(uint32_t data);
uint32_t little_to_big(uint32_t data);
int8_t * itoa(int32_t num, int8_t *str, int32_t base);


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
   return 0;
}

void dump_memory(uint8_t *start, uint32_t length)         //Function definition for printing hex output of the data bytes in the memory given pointer to a memory location & length of bytes to print
{
   int32_t i;
   for(i=0;i<length;i++)
   {
      printf("\n Hex output: %x\t",*(start+i));           //Prints the hex value of number of bytes given in the length


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
   return 0;
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
       printf("The data is already stored as big endian\n");
   return 0;
}

int8_t * itoa(int32_t num, int8_t *str, int32_t base)      //Function definition for converting data from integer to ascii string
{
    int32_t i = 0;
    int32_t neg=0;

                                                          // Handle 0 explicitely, otherwise empty string is printed for 0
    //printf("the number is:%d\n",num);
    if (num ==0)
    {
        *str='0';
        i++;
		*(str+i)='\0';
        //printf("The string is:%s",str);
        return str;
    }

    if(num<0 && base==16)
    {
        sprintf(str,"%X",num);                                           // convert decimal to hexadecimal
        //printf("converting %d to hexadecimal notation %s\n",num,str);    //shows the hex output for signed integer
        return str;
    }

    if(num<0 && base==8)
    {
        sprintf(str,"%o",num);                                         //convert decimal to octal
        //printf("converting %d to octal notation %s\n",num,str);        //shows the octal output of signed integer
        return str;
    }

    if (num < 0 && (base == 10 || base==2))
    {
        neg = 1;                                                       //Set neg varibale to 1 if the number is negative
        num = -num;                                                    //Consider only unsigned number initially for conversion
    }

                                                                       // Process individual digits
    while (num != 0)
    {
        int32_t rem = num % base;
        *(str+i)= (rem > 9)?(rem-10) + 'a' : rem + '0';               //Converting integer to ascii string
        i++;
        num = num/base;
    }

    if (neg==1)                                                        //If number is negative, append '-'
    {
        *(str+i)= '-';
        i++;
    }

                                                        // Append string terminator
    reverse(str, i);                                                   // Reverse the string
    *(str+i)= '\0';
    //printf("The string is:%s",str);                                    //Print the ascii string

    return str;
}

void reverse(int8_t *str, int32_t length)                             //Function to perform reverse of the string
{
    int32_t start = 0;
    int32_t end = length -1;
    while (start < end)                                               //Swap the string
    {
        int8_t temp= *(str+start);
        *(str+start)= *(str+end);
        *(str+end)=temp;
        start++;
        end--;
    }
}


void ftoa(float n, int8_t *res, int32_t dec_place)
{
  int32_t neg=0;
    if(n<0)
    {
	     n=-n;
    	neg=1;
			}
			// Extract integer part
    int32_t ipart = (int32_t)n;

    // Extract floating part
    float fpart = n - (float)ipart;

    // convert integer part to string
    int32_t i = intToStr(ipart, res, 0,neg);
    neg=0;

    // check for display option dec_place
    if (dec_place != 0)
    {
        *(res+i) = '.';  // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007
        fpart = fpart * pow(10,dec_place);

        intToStr((int)fpart, res + i + 1, dec_place,neg);
        //printf("neg is ftoi =%d",neg);
    }
}




int intToStr(int32_t x, int8_t str[], int32_t d, int32_t negative)
{
    int32_t i = 0;
    while (x)
    {
        str[i++] = (x%10) + '0';
        x = x/10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';
      if(negative==1)
        {
			str[i++]='-';
		}

    reverse(str, i);
    str[i] = '\0';
    return i;
}
