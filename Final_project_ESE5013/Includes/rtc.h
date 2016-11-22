/*
 * rtc.h
 *
 *  Created on: 21-Nov-2016
 *      Author: Admin
 */

#ifndef RTC_H_
#define RTC_H_

typedef enum{JAN=1,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC}month_t;
typedef struct{
	uint32_t min;
	uint32_t sec;
	uint32_t date;
	month_t month;
	uint32_t year;

}time_t;


#endif /* RTC_H_ */
