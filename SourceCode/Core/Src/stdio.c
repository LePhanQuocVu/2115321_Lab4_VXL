/**
 * @brief Retargets the C library printf function to the USART.
 * @param None
 * @retval None
 */
#include "stdio.h"
PUTCHAR_PROTOTYPE
{
 /* Place your implementation of fputc here */
 /* e.g. write a character to the USART */
 HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 100);
 return ch;
}


