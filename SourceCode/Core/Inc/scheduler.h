/*
 * scheduler.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Lenovo
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdio.h>
#include <stdint.h>

#define SCH_MAX_TASKS	40

typedef struct {
	void (*pTask)(void); // function pointer to task
	uint32_t Delay;  	// fuction Delay
	uint32_t Period;	// Period
	uint8_t RunMe;		// excute
	uint32_t TaskID; 	// taskID
} sTask;

void SCH_Init();
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Delete_Task(uint32_t taskID);

#endif /* INC_SCHEDULER_H_ */
