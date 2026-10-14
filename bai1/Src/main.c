#include "main.h"

volatile uint8_t current_led = 0;
volatile uint8_t led_brightness[3] = {50, 50, 50}; // Độ sáng mặc định 50%

void delay_cycles(volatile uint32_t t) {
    while(t--);
}

// Khởi tạo UART1 (Baudrate 9600, TX: PA9, RX: PA10)
void UART1_Init(void) {
    // Bật clock GPIOA và USART1
    *(volatile uint32_t*)0x40021018 |= (1 << 2) | (1 << 14);

    // PA9 (TX) Alternate function push-pull, PA10 (RX) Input floating
    *(volatile uint32_t*)0x40010404 &= 0xFFFF00FF;
    *(volatile uint32_t*)0x40010404 |= 0x00004B00;

    // Baudrate = 9600 với PCLK2 = 8MHz -> USARTDIV = 52.083 -> Mantissa = 52, Fraction = 1
    *(volatile uint32_t*)0x40013808 = (52 << 4) | 1;

    // Bật Transmitter, Receiver và USART
    *(volatile uint32_t*)0x4001380C = (1 << 13) | (1 << 3) | (1 << 2);
}

// Đọc ký tự từ UART1 không chờ (Non-blocking)
int UART1_ReadChar(void) {
    if (*(volatile uint32_t*)0x40013800 & (1 << 5)) {
        return *(volatile uint32_t*)0x40013804 & 0xFF;
    }
    return -1;
}

int main(void) {
    // 1. Bật Clock GPIOA
    *(volatile uint32_t*)0x40021018 |= (1 << 2);

    // 2. Cấu hình PA0, PA1, PA2 làm Output Push-Pull 2MHz
    *(volatile uint32_t*)0x40010800 &= 0xFFFFF000;
    *(volatile uint32_t*)0x40010800 |= 0x00000222;

    // 3. Khởi tạo UART1
    UART1_Init();

    uint32_t pwm_counter = 0;

    while (1) {
        // Đọc ký tự từ bàn phím máy tính qua UART
        int key = UART1_ReadChar();
        if (key != -1) {
            if (key == 'c' || key == 'C') {
                current_led = (current_led + 1) % 3; // Chuyển đổi qua lại giữa PA0, PA1, PA2
            } else if (key == '+' || key == '=') {
                if (led_brightness[current_led] <= 90) led_brightness[current_led] += 10; // Tăng sáng
            } else if (key == '-' || key == '_') {
                if (led_brightness[current_led] >= 10) led_brightness[current_led] -= 10; // Giảm sáng
            }
        }

        // Software PWM điều khiển độ sáng LED
        pwm_counter = (pwm_counter + 1) % 10;
        
        for (int i = 0; i < 3; i++) {
            if (pwm_counter < (led_brightness[i] / 10)) {
                *(volatile uint32_t*)0x4001080C |= (1 << i);  // Bật LED
            } else {
                *(volatile uint32_t*)0x4001080C &= ~(1 << i); // Tắt LED
            }
        }
        
        delay_cycles(400);
    }
}
