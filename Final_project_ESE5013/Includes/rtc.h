/*
 * rtc.h
 *
 *  Created on: 21-Nov-2016
 *      Author: Admin
 */

#ifndef RTC_H_
#define RTC_H_


void rtc_init(void);
void time_set(void);
uint32_t datetosec(void);
void RTC_IRQHandler(void);

typedef enum{JAN=1,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC}month_t;
typedef struct{
	uint32_t hour;
	uint32_t min;
	uint32_t date;
	month_t month;
	uint32_t year;

}time_t;

time_t cur_time;

uint8_t days[12]={31,28,31,30,31,30,31,31,30,31,30,31};


#endif /* RTC_H_ */
