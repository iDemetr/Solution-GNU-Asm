#ifndef task5_6_H
#define task5_6_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Макрос для вывода массива с параметризацией массива и делегата вывода
#define PRINT_ARRAY(arr, printer) \
do { \
    for (int i = 0; i < N; i++) { \
        printer(&arr[i]); \
    } \
} while(0)

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

void run_task5_6()
{
    printf("\nЗадание №6\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
   
    int N;
    int i = 0;
   
    printf("Введите длину массива N: ");
    if (scanf("%d", &N) != 1 || N <= 0) {
        fprintf(stderr, "Ошибка ввода N\n");
        return;
    }
   
    int* arr = (int*)malloc(N * sizeof(int));
    if (!arr) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return ;
    }

   __asm__ volatile (
        "mov %[arr], %%rsi;"         // rsi = arr
        "xor %%rax, %%rax;"          // i = 0 (rax - 64-bit)
        "test %[N], %[N];"
        "jz 2f;"                     // если N == 0, выйти
        "1:;"
        "lea (%%rax, %%rax, 1), %%edx;"   // edx = 2*i (edx - 32-bit)
        "add $1, %%edx;"             // edx = 2*i + 1
        "movl %%edx, (%%rsi, %%rax, 4);" // arr[i] = 2*i + 1
        "inc %%rax;"                 // i++
        "cmp %[N], %%rax;"
        "jl 1b;"
        "2:;"
        :
        : [arr] "r" (arr), [N] "r" ((unsigned long)N)
        : "rax", "rdx", "rsi", "memory"
    );

    printf("Результат (первые %d нечётных неотрицательных чисел):\n", N);
    PRINT_ARRAY(arr,print32);

    free(arr);

    printf("=========================================================================\n");
}

#endif