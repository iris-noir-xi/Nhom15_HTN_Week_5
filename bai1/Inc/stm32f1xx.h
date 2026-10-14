#ifndef __STM32F1xx_H
#define __STM32F1xx_H

#include <stdint.h>

#define PERIPH_BASE           ((uint32_t)0x40000000)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000)

#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000)
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x00000C00)

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB1RSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;
} RCC_TypeDef;

typedef struct
{
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
} GPIO_TypeDef;

#define RCC                   ((RCC_TypeDef *)RCC_BASE)
#define GPIOB                 ((GPIO_TypeDef *)GPIOB_BASE)

#define GPIO_PIN_0            ((uint16_t)0x0001)
#define GPIO_PIN_1            ((uint16_t)0x0002)
#define GPIO_PIN_10           ((uint16_t)0x0400)

typedef enum 
{
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET
} GPIO_PinState;

typedef struct
{
  uint32_t Pin;
  uint32_t Mode;
  uint32_t Pull;
  uint32_t Speed;
} GPIO_InitTypeDef;

#define GPIO_MODE_INPUT       0x00000000U
#define GPIO_PULLUP           0x00000010U

#define TIM_CHANNEL_1         0x00000000U
#define TIM_CHANNEL_2         0x00000004U
#define TIM_CHANNEL_3         0x00000008U

#endif
