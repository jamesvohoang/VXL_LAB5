#ifndef __TRANSCEIVER_H
#define __TRANSCEIVER_H

#include "stm32f1xx_hal.h"
#include <stdio.h>

#define MAX_BUFFER_SIZE 30

extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t isCommandTypingFlag;
extern uint8_t invokeCommandFlag;

void TransceiverInit(void);
void RespondSensorValue(uint32_t value);

#endif /* __TRANSCEIVER_H */
