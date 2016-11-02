/*
 * profile.h
 *
 *  Created on: 11-Oct-2016
 *      Author: Admin
 */

#ifndef SOURCES_PROFILE_H_
#define SOURCES_PROFILE_H_
void pit_init(void);
void pit_enable(void);
void pit_disable(void);
void PIT_IRQHandler(void);
void get_time(void);
#define RESOLUTION 1
#endif /* SOURCES_PROFILE_H_ */
