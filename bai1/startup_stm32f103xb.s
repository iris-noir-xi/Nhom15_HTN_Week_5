.syntax unified
.cpu cortex-m3
.thumb

.global g_pfnVectors
.global Reset_Handler

.section .text.Reset_Handler
.type Reset_Handler, %function
Reset_Handler:
    /* Khởi tạo Stack Pointer cho RAM STM32F103 (20KB: 0x20000000 + 0x5000) */
    ldr   r0, =0x20005000
    mov   sp, r0
    /* Nhảy vào hàm main */
    bl    main
_loop:
    b     _loop

.section .isr_vector,"a",%progbits
.type g_pfnVectors, %object
g_pfnVectors:
    .word 0x20005000
    .word Reset_Handler
