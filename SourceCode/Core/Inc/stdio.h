/*
 * stdio.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Lenovo
 */

#ifndef INC_STDIO_H_
#define INC_STDIO_H_

/**
 * @brief Retargets the C library printf function to the USART.
 * @param None
 * @retval None
 */
PUTCHAR_PROTOTYPE
{
 /* Place your implementation of fputc here */
 /* e.g. write a character to the USART */
 HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 100);
 return ch;
}

#endif /* INC_STDIO_H_ */
