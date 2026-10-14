#ifndef __STM32F1xx_HAL_H
#define __STM32F1xx_HAL_H

#include "stm32f1xx.h"

typedef enum {
    HAL_OK = 0x00,
    HAL_ERROR = 0x01,
    HAL_BUSY = 0x02,
    HAL_TIMEOUT = 0x03
} HAL_StatusTypeDef;

typedef struct {
    uint32_t Instance;
    uint32_t Init;
} TIM_HandleTypeDef;

void HAL_Init(void);
void HAL_Delay(uint32_t Delay);
void HAL_TIM_PWM_Start(TIM_HandleTypeDef *htim, uint32_t Channel);
void __HAL_RCC_GPIOB_CLK_ENABLE(void);
void __HAL_RCC_TIM2_CLK_ENABLE(void);
void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init);
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void __HAL_TIM_SET_COMPARE(TIM_HandleTypeDef *htim, uint32_t Channel, uint32_t Compare);

#endif
