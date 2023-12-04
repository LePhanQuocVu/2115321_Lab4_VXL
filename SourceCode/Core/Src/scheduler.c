/*
 * scheduler.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Lenovo
 */

#include "scheduler.h"

uint32_t current_id_task;
sTask SCH_tasks_G[SCH_MAX_TASKS];


void SCH_Init(){
	current_id_task = 0;
}

void SCH_Update(void) {
	if(SCH_tasks_G[0].pTask && SCH_tasks_G[0].RunMe == 0){
			if(SCH_tasks_G[0].Delay > 0){
				// run task when delay == 0
				SCH_tasks_G[0].Delay--;
			}
			if(SCH_tasks_G[0].Delay == 0){
					// run task
				SCH_tasks_G[0].RunMe = 1;
			}
		}
}


void SCH_Dispatch_Tasks(void) {
	if(SCH_tasks_G[0].RunMe > 0){
		// run
		(*SCH_tasks_G[0].pTask)();
		// save funtion poiter
		void(*pFunction)() = SCH_tasks_G[0].pTask;
		uint32_t period = SCH_tasks_G[0].Period;
		// delete task
		SCH_Delete_Task(0);
		// add again in task
		SCH_Add_Task(pFunction, period, period);
		}
}

void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {

	if(current_id_task < SCH_MAX_TASKS) {
		// check period
		if(PERIOD==0) return;

		uint32_t i = 0;
		while(DELAY > SCH_tasks_G[i].Delay && i < current_id_task) {
				DELAY = DELAY - SCH_tasks_G[i].Delay;
				i++;
			}
		// add task in Array
		if(i != current_id_task){
				//add task in position i -1
			for(uint32_t idx = current_id_task; idx > i; idx--){
				SCH_tasks_G[idx].pTask = SCH_tasks_G[idx - 1].pTask;
				SCH_tasks_G[idx].Delay = SCH_tasks_G[idx - 1].Delay;
				SCH_tasks_G[idx].Period = SCH_tasks_G[idx - 1].Period;
				SCH_tasks_G[idx].RunMe= SCH_tasks_G[idx - 1].RunMe;
				SCH_tasks_G[idx].TaskID = idx;
			}
			// new time delay of new task
			SCH_tasks_G[i+1].Delay -= DELAY;
		}
		SCH_tasks_G[i].pTask = pFunction;
		SCH_tasks_G[i].Delay = DELAY;
		SCH_tasks_G[i].Period = PERIOD;
		SCH_tasks_G[i].RunMe =  0;
		SCH_tasks_G[i].TaskID = i;
		current_id_task++;

	}

}
void SCH_Delete_Task(uint32_t taskID){
	for(uint32_t i = taskID; i < current_id_task; i ++){
		SCH_tasks_G[i].pTask = SCH_tasks_G[i+1].pTask;
		SCH_tasks_G[i].Delay = SCH_tasks_G[i+1].Delay;
		SCH_tasks_G[i].Period = SCH_tasks_G[i+1].Period;
		SCH_tasks_G[i].RunMe = SCH_tasks_G[i+1].RunMe;
		SCH_tasks_G[i].TaskID = i;
	}
	current_id_task--;
}
