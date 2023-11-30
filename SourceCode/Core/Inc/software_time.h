/*
 * software_time.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Lenovo
 */

#ifndef SRC_SOFTWARE_TIME_H_
#define SRC_SOFTWARE_TIME_H_


extern int timer1_flag;
extern int timer2_flag;

void setTimer1(int duration);
void setTimer2(int duration);

void timeRun();

#endif /* SRC_SOFTWARE_TIME_H_ */
