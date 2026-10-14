#ifndef __STM32F1xx_HAL_H
#define __STM32F1xx_HAL_H

#include "stm32f1xx.h"

typedef enum {
    HAL_OK = 0x00,
    HAL_ERROR = 0x01,
    HAL_BUSY = 0x02,
    HAL_TIMEOUT = 0x03
} HAL_StatusTypeDef;

void HAL_Init(void);
void HAL_Delay(uint32_t Delay);

#endif
