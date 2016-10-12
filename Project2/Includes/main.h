/*
 * main.h
 *
 *  Created on: 11-Oct-2016
 *      Author: Admin
 */

#ifndef INCLUDES_MAIN_H_
#define INCLUDES_MAIN_H_
// FOR FRDM ARCH=1
// FOR BBB ARCH= 2
#define BOARD (1)
#include"log.h"
#ifdef BOARD==1

#define LOG0(c) uart_log((uint8_t*) c)

#elif	BOARD==2

#define LOG0(c) bbb_log((uint8_t*) c)


#else

#define LOG0(c)
#endif

#endif /* INCLUDES_MAIN_H_ */
