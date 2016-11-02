#ifndef _DATA_H
#define _DATA_H

int32_t my_atoi(int8_t *str);                               //Function prototype for ascii string to integer conversion
void dump_memory(uint8_t *start, uint32_t length);          //Function prototype for printing hex output of data bytes in the memory
uint32_t big_to_little(uint32_t data);                      //Function prototype for big endian to little endian conversion
uint32_t little_to_big(uint32_t data);                      //Function prototype for little endian to big endian conversion
int8_t* itoa(int32_t num, int8_t* str, int32_t base);       //Function prototype for integer to ascii string conversion

#endif
