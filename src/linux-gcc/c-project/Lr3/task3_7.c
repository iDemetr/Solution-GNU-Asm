#ifndef task3_7_H
#define task3_7_H

#define N 5

// Макрос для вывода массива с параметризацией массива и делегата вывода
#define PRINT_ARRAY(arr, printer) \
do { \
    for (int i = 0; i < N; i++) { \
        printer(&arr[i]); \
    } \
} while(0)

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void run_task3_7()
{
    printf("\nЗадание №7\n");
    printf("=========================================================================\n");
    
    // Вариант 17: x = 8/3 для float/double
    double Mfl[N];
    
    size_t i = 2;
    double x = 9.87654321;

    for (size_t i = 0; i < N; i++) {
        Mfl[i] = 8.0 / 3.0;
    }

    printf("Before:\n");
    PRINT_ARRAY(Mfl, print64);

    __asm__ volatile (
        "vmovsd (%[x_addr]), %%xmm4\n\t"             // загрузить double x в xmm4
        "vmovsd %%xmm4, (%[base], %[index], 8)\n\t"  // записать xmm4 в M[i], scale=8 (double)
        :
        : [x_addr] "r" (&x),
          [base] "r" (Mfl),
          [index] "r" (i)
        : "xmm4", "memory"
    );

    printf("After:\n");
    PRINT_ARRAY(Mfl, print64);
    
    printf("\n=========================================================================\n");
}

#endif