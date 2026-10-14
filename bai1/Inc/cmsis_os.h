#ifndef __CMSIS_OS_H
#define __CMSIS_OS_H

#include <stdint.h>
#include <stddef.h>

typedef void* QueueHandle_t;
typedef void* TaskHandle_t;
typedef uint32_t TickType_t;

#define portMAX_DELAY 0xffffffffUL
#define pdPASS        (1)
#define tskIDLE_PRIORITY 0

void vTaskDelay(const TickType_t xTicksToDelay);
QueueHandle_t xQueueCreate(const unsigned int uxQueueLength, const unsigned int uxItemSize);
int xQueueSend(QueueHandle_t xQueue, const void * const pvItemToQueue, TickType_t xTicksToWait);
int xQueueReceive(QueueHandle_t xQueue, void * const pvBuffer, TickType_t xTicksToWait);
int xTaskCreate(void (*pxTaskCode)( void * ), const char * const pcName, const uint16_t usStackDepth, void * const pvParameters, unsigned long uxPriority, TaskHandle_t * const pxCreatedTask);
void osKernelStart(void);

#define pdMS_TO_TICKS(xTimeInMs) (xTimeInMs)

#endif
