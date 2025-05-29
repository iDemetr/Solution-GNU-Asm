#ifndef task3_1_H
#define task3_1_H

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

void run_task3_1()
{
    printf("\nЗадание №1\n");
    printf("=========================================================================\n");
    
    // Инициализация массивов (значения аналогичны Л1.№3, например)
    unsigned short Ms[N] = {0xFADE, 0xFADE, 0xFADE, 0xFADE, 0xFADE};
    unsigned int Ml[N] = {0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA};
    unsigned long long Mq[N] = {0xC1A551F1AB1EULL, 0xC1A551F1AB1EULL, 0xC1A551F1AB1EULL, 0xC1A551F1AB1EULL, 0xC1A551F1AB1EULL};

    int i = 2; // индекс вставки, 0 <= i <= N-2

    // Вывод до вставки
    printf("Ms before:\n");
    PRINT_ARRAY(Ms, print16);

    printf("Ml before:\n");
    PRINT_ARRAY(Ml,print32);

    printf("Mq before:\n");
    PRINT_ARRAY(Mq,print32);

    // Вставка значения 18 в Ms[i] с помощью movw
    __asm__ volatile (
        "movw $18, %0"
        : "=m" (Ms[i])
    );

    // Вставка значения 18 в Ml[i] с помощью movl
    __asm__ volatile (
        "movl $18, %0"
        : "=m" (Ml[i])
    );

    // Вставка значения 18 в Mq[i] с помощью movq
    __asm__ volatile (
        "movq $18, %0"
        : "=m" (Mq[i])
    );

    // Вывод после вставки
    printf("Ms after:\n");
    PRINT_ARRAY(Ms, print16);

    printf("Ml after:\n");
    PRINT_ARRAY(Ml,print32);

    printf("Mq after:\n");
    PRINT_ARRAY(Mq,print32);

    printf("\n=========================================================================\n");
}

#endif