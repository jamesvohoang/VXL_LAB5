#include "sensor.h"

extern ADC_HandleTypeDef hadc1;

uint32_t sensorValue = 0;

void SensorInit(void)
{
    HAL_ADC_Start(&hadc1);
}

uint32_t GetSensorValue(void)
{
    sensorValue = HAL_ADC_GetValue(&hadc1);

    return sensorValue;
}