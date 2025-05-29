#ifndef task3_3_H
#define task3_3_H

#define N 5

// Макрос для вывода массива с параметризацией массива и делегата вывода
#define PRINT_ARRAY(arr, printer) \
do { \
    for (int i = 0; i < N; i++) { \
        printer(&arr[i]); \
    } \
} while(0)

#include <stdio.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void run_task3_3()
{
    printf("\nЗадание №3\n");
    printf("=========================================================================\n");
    
   unsigned long long Mq[N] = {
        0xC1A551F1AB1E0000ULL, 0xC1A551F1AB1E0000ULL,
        0xC1A551F1AB1E0000ULL, 0xC1A551F1AB1E0000ULL,
        0xC1A551F1AB1E0000ULL
    };

    const int i = 2; // индекс элемента для изменения
    const int byte_offset = 2;  // №2 — третий байт

    printf("Mq before:\n");
    PRINT_ARRAY(Mq, print64);

   // Вычисляем адрес нужного байта
    unsigned char *addr = (unsigned char *)Mq + i * sizeof(unsigned long long) + byte_offset;

    // Используем movb для записи 0x55 в третий байт Mq[i]
    __asm__ volatile (
        "movb $0x55, (%[addr])"
        :
        : [addr] "r" (addr)
        : "memory"
    );

    printf("Mq after:\n");
    PRINT_ARRAY(Mq, print64);

    printf("\n=========================================================================\n");
}

#endif