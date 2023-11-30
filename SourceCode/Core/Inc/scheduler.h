/*
 * scheduler.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Lenovo
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

typedef struct {
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe; // >0 same timer_flag == 1

	uint32_t TaskID;
} sTasks;

#define SCH_MAX_TASKS 40

void SCH_Init(void);

void SCH_Add_Task (void (*pFuction)(), uint32_t DELAY, uint32_t PERIOD); // set Timer

void SCH_Update(void); // same Timer Rung

void SCH_Dispatch_Tasks(void);  // check Flag same whle q

#endif /* INC_SCHEDULER_H_ */
