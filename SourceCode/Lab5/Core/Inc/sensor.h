#ifndef __SENSOR_H
#define __SENSOR_H

#include "stm32f1xx_hal.h"

void SensorInit(void);

uint32_t GetSensorValue(void);

#endif /* __SENSOR_H */