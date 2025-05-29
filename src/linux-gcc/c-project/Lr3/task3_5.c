#ifndef task3_5_H
#define task3_5_H

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

void run_task3_5()
{
    printf("\nЗадание №5\n");
    printf("=========================================================================\n");
    
    unsigned int Ml[N] = {0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF};

    size_t i = 3; // индекс для записи
    unsigned int x = 0x12345678; // значение для вставки

    printf("Ml before:\n");
    PRINT_ARRAY(Ml, print32);

    __asm__ volatile (
        "movl (%[x_addr]), %%edx\n\t"         // загрузить значение по адресу x_addr в edx
        "movl %%edx, (%[base], %[index], 4)"  // записать edx в M[i]
        :
        : [x_addr] "r" (&x),
          [base] "r" (Ml),
          [index] "r" (i)
        : "edx", "memory"
    );

    printf("Ml after:\n");
    PRINT_ARRAY(Ml, print32);

    printf("\n=========================================================================\n");
}

#endif