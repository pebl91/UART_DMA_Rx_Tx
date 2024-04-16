/*
 * parse.c
 *
 *  Created on: Apr 15, 2024
 *      Author: Paweł Smusz
 */

#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "transmit.h"


void Parse(uint16_t Buffer)
{
	uint8_t ReceiveBuffer[32];
	HAL_UARTEx_ReceiveToIdle_DMA(&hlpuart1, ReceiveBuffer, 32);
	uint8_t i;
	uint8_t *Parse = malloc(Buffer);

	for(i = 0; i < (Buffer-1); i++)
			{
				Parse[i] = ReceiveBuffer[i];
			}
			Parse[i] = '\0';


			// Check Received commends on UART, when comannd is right light on/off LD2, LED1, LED2...
			if(strcmp("LD2_ON", (char*)Parse) == 0)
			{
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
				SendMessage("LD2 IS ON\r\n");
			}
			else if(strcmp("LD2_OFF", (char*)Parse) == 0)
			{
				HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);\
				SendMessage("LD2 IS OFF\r\n");
			}

			if(strcmp("LED1_ON", (char*)Parse) == 0)
			{
				HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
				SendMessage("LED_1 IS ON\r\n");
			}
			else if(strcmp("LED1_OFF", (char*)Parse) == 0)
			{
				HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_RESET);
				SendMessage("LED_1 IS OFF\r\n");
			}

			if(strcmp("LED2_ON", (char*)Parse) == 0)
			{
				HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
				SendMessage("LED_2 IS ON\r\n");
			}
			else if(strcmp("LED2_OFF", (char*)Parse) == 0)
			{
				HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_RESET);
				SendMessage("LED_2 IS OFF\r\n");
			}


			free(Parse);
		}
