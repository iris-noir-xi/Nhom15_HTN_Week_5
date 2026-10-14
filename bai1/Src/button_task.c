#include "main.h"

extern QueueHandle_t ledQueue;

void Button_Task(void *argument) {
    (void)argument;
    LedMessage_t msg;
    
    for(;;) {
        // Giả lập đọc nút bấm và gửi message vào Queue
        msg.led_id = 1;
        msg.brightness = 50; // Mức độ sáng hoặc trạng thái
        
        xQueueSend(ledQueue, &msg, portMAX_DELAY);
        
        // Delay 500ms
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
