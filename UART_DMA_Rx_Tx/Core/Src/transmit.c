/*
 * transmit.c
 *
 *  Created on: Apr 15, 2024
 *      Author: Paweł Smusz
 */

#include "main.h"
#include "dma.h"
#include "usart.h"
#include "stdio.h"


void SendMessage(char *Input)
{
	uint8_t Length;
    uint8_t MessageBuffer[64]; // Buffer to hold the formatted message
    Length = sprintf((char *)MessageBuffer, "%s", Input); // Format the input string into the message buffer
    HAL_UART_Transmit_DMA(&hlpuart1, MessageBuffer, Length); // Transmit the formatted message via UART using DMA
}
