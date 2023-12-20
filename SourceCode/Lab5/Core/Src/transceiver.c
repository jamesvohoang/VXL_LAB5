#include "transceiver.h"

extern UART_HandleTypeDef huart1;

uint8_t buffer[MAX_BUFFER_SIZE] = {0};
uint8_t temp = 0;
uint8_t bufferIndex = 0;

uint8_t isCommandTypingFlag = 0;
uint8_t invokeCommandFlag = 0;

void TransceiverInit(void)
{
    HAL_UART_Receive_IT(&huart1, &temp, 1);
}

void RespondSensorValue(uint32_t value)
{
    char temp[MAX_BUFFER_SIZE];
    int size = sprintf(temp, "\n!ADC=%ld#\n", value);
    HAL_UART_Transmit(&huart1, (uint8_t *)temp, size, 1000);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if(huart->Instance == USART1)
  {
    switch (temp)
    {

    // Start cmd
    case 0x21:
      bufferIndex = 0;
      isCommandTypingFlag = 1;
      break;

    // End cmd
    case 0x23:
      isCommandTypingFlag = 0;
      invokeCommandFlag = 1;
      break;
    
    default:
      break;
    }

    buffer[bufferIndex] = temp;
    bufferIndex++;
    if(bufferIndex == MAX_BUFFER_SIZE)
      bufferIndex = 0;

    HAL_UART_Receive_IT(&huart1, &temp, 1);
  }
}