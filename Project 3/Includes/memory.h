/*
 * memory.h
 *
 *  Created on: 08-Oct-2016
 *      Author: Admin
 */

#ifndef INCLUDES_MEMORY_H_
#define INCLUDES_MEMORY_H_

int8_t my_memmove(uint8_t *src, uint8_t *dst, uint32_t length);   //Function prototype for transferring data from one location to another
void my_memzero(uint8_t *src, uint32_t length);                 //Function prototype to set given length of bytes to zero
int8_t my_reverse(uint8_t *src, uint32_t length);                         //Function prototype to reverse

#endif /* INCLUDES_MEMORY_H_ */
