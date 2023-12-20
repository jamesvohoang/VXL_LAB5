#ifndef __PROCESSING_H
#define __PROCESSING_H

#include "stm32f1xx_hal.h"
#include "transceiver.h"
#include "sensor.h"

typedef enum
{
    DO_NOTHING,
    REQUEST,
    KEEP_REQUEST,
}commandTypeDef;
extern uint16_t count;
uint8_t CheckCommand(void);

void InvokeCommand(void);

#endif /* __PROCESSING_H */