#ifndef MAIN_H
#define MAIN_H

#include <stdint.h>

// Định nghĩa cấu trúc dữ liệu truyền qua Queue
typedef struct {
    uint8_t led_id;     // ID của LED (0, 1, hoặc 2)
    int8_t brightness;  // Thay đổi độ sáng (-10% hoặc +10%, hoặc chọn LED)
    uint8_t action;     // Hành động: 0 = Chuyển LED, 1 = Đổi độ sáng
} LedMessage_t;

// Khai báo prototype các Task
void Button_Task(void *argument);
void Led1_Task(void *argument);
void Led2_Task(void *argument);
void Led3_Task(void *argument);

#endif
