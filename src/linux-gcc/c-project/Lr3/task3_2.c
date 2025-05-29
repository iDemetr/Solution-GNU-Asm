#ifndef task3_2_H
#define task3_2_H

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

void run_task3_2()
{
    printf("\nЗадание №2\n");
    printf("=========================================================================\n");
    
    // Инициализация массивов (значения аналогичны Л1.№3, например)
    unsigned short Ms[N] = {0xFADE, 0xFADE, 0xFADE, 0xFADE, 0xFADE};

    size_t i = 2; // индекс вставки

    printf("Ms before:\n");
    PRINT_ARRAY(Ms, print16);

    // Ассемблерная вставка с использованием Base, Index, Scale=2 для Ms (16-бит)
    // Эффективный адрес: base = &Ms[0], index = i, scale = 2 (sizeof(short))
    // Запишем -1 (0xFFFF) в Ms[i]

    unsigned short val = 0xFFFF;

    __asm__ volatile (
        "movw %[val], (%[base], %[index], 2)"
        :
        : [val] "r" (val),
          [base] "r" (Ms),
          [index] "r" (i)
        : "memory"
    );

    printf("Ms after:\n");
    PRINT_ARRAY(Ms, print16);

    printf("\n=========================================================================\n");
}

#endif