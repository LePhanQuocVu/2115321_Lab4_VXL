/*
 * task.c
 *
 *  Created on: Dec 4, 2023
 *      Author: Lenovo
 */

#ifndef SRC_TASK_C_
#define SRC_TASK_C_

#include "main.h"
#include "stdio.h"
#include "string.h"

int counter = 0;
void Counter(){
	counter++;
}
void task0(void) {
	const unsigned char arr[20] = "Task 0: ";
	HAL_UART_Transmit(&huart1, arr, sizeof(arr), 1000);
	char temp[20];
	sprintf(temp, "%dms\r\n", counter*10);
	HAL_UART_Transmit(&huart1, (uint8_t*)temp, strlen(temp), 1000);
	HAL_GPIO_TogglePin(Task0_GPIO_Port, Task0_Pin);
}
void task1(void) {
	const unsigned char arr[20] = "Task 1: ";
		HAL_UART_Transmit(&huart1, arr, sizeof(arr), 1000);
		char temp[20];
		sprintf(temp, "%dms\r\n", counter*10);
		HAL_UART_Transmit(&huart1, (uint8_t*)temp, strlen(temp), 1000);
		HAL_GPIO_TogglePin(Task1_GPIO_Port, Task2_Pin);
}
void task2(void) {
	const unsigned char arr[20] = "Task 2: ";
		HAL_UART_Transmit(&huart1, arr, sizeof(arr), 1000);
		char temp[20];
		sprintf(temp, "%dms\r\n", counter*10);
		HAL_UART_Transmit(&huart1, (uint8_t*)temp, strlen(temp), 1000);
		HAL_GPIO_TogglePin(Task2_GPIO_Port, Task2_Pin);
}
void task3(void) {
	const unsigned char arr[20] = "Task 3: ";
		HAL_UART_Transmit(&huart1, arr, sizeof(arr), 1000);
		char temp[20];
		sprintf(temp, "%dms\r\n", counter*10);
		HAL_UART_Transmit(&huart1, (uint8_t*)temp, strlen(temp), 1000);
		HAL_GPIO_TogglePin(Task3_GPIO_Port, Task3_Pin);
}
void task4(void) {
	const unsigned char arr[20] = "Task 4: ";
		HAL_UART_Transmit(&huart1, arr, sizeof(arr), 1000);
		char temp[20];
		sprintf(temp, "%dms\r\n", counter*10);
		HAL_UART_Transmit(&huart1, (uint8_t*)temp, strlen(temp), 1000);
		HAL_GPIO_TogglePin(Task4_GPIO_Port, Task4_Pin);
}
void task5(void) {
	const unsigned char arr[20] = "Task 5: ";
		HAL_UART_Transmit(&huart1, arr, sizeof(arr), 1000);
		char temp[20];
		sprintf(temp, "%dms\r\n", counter*10);
		HAL_UART_Transmit(&huart1, (uint8_t*)temp, strlen(temp), 1000);
		HAL_GPIO_TogglePin(Task5_GPIO_Port, Task5_Pin);
}

#endif /* SRC_TASK_C_ */
