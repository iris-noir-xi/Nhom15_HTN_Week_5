#include "main.h"

extern QueueHandle_t ledQueue;

void Led1_Task(void *argument) {
    (void)argument;
    LedMessage_t recvMsg;

    for(;;) {
        // Đợi dữ liệu từ Queue gửi sang
        if (xQueueReceive(ledQueue, &recvMsg, portMAX_DELAY) == pdPASS) {
            // Xử lý bật/tắt LED dựa vào recvMsg.led_id và recvMsg.brightness
            // Ví dụ đảo trạng thái chân GPIO hoặc cập nhật PWM
        }
    }
}

void Led2_Task(void *argument) { for(;;) { vTaskDelay(pdMS_TO_TICKS(1000)); } }
void Led3_Task(void *argument) { for(;;) { vTaskDelay(pdMS_TO_TICKS(1000)); } }
