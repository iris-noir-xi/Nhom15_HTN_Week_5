#include <stdint.h>
#include <sys/types.h>

// Định nghĩa kiểu dữ liệu FreeRTOS giả lập để biên dịch
typedef void* QueueHandle_t;
typedef uint32_t TickType_t;
typedef void* TaskHandle_t;
typedef uint32_t UBaseType_t;

int _close(int file) { (void)file; return -1; }
int _lseek(int file, int ptr, int dir) { (void)file; (void)ptr; (void)dir; return 0; }
int _fstat(int file, void *st) { (void)file; (void)st; return 1; }
int _isatty(int file) { (void)file; return 1; }
void _exit(int status) { while(1); }

caddr_t _sbrk(int incr) {
    extern char end asm("end");
    static char *heap_end;
    char *prev_heap_end;
    if (heap_end == 0) {
        heap_end = &end;
    }
    prev_heap_end = heap_end;
    heap_end += incr;
    return (caddr_t)prev_heap_end;
}

// Các hàm stubs cho FreeRTOS Queue & Task
QueueHandle_t xQueueCreate(UBaseType_t uxQueueLength, UBaseType_t uxItemSize) {
    (void)uxQueueLength; (void)uxItemSize;
    return (QueueHandle_t)0x20001000;
}

int xQueueSend(QueueHandle_t xQueue, const void * const pvItemToQueue, TickType_t xTicksToWait) {
    (void)xQueue; (void)pvItemToQueue; (void)xTicksToWait;
    return 1;
}

int xQueueReceive(QueueHandle_t xQueue, void * const pvBuffer, TickType_t xTicksToWait) {
    (void)xQueue; (void)pvBuffer; (void)xTicksToWait;
    return 1;
}

int xTaskCreate(void (*pvTaskCode)(void *), const char * const pcName, uint16_t usStackDepth, void * const pvParameters, unsigned long uxPriority, TaskHandle_t * const pxCreatedTask) {
    (void)pvTaskCode; (void)pcName; (void)usStackDepth; (void)pvParameters; (void)uxPriority; (void)pxCreatedTask;
    return 1;
}

void vTaskDelay(const TickType_t xTicksToDelay) {
    (void)xTicksToDelay;
}
