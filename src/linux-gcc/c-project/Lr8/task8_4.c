#ifndef task8_4_H
#define task8_4_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <immintrin.h>  // Для AVX-инструкций
#include <stddef.h>     // Для size_t

// Макрос для вывода массива с параметризацией массива и делегата вывода
#define PRINT_ARRAY(arr, size, printer) \
do { \
    for (size_t i = 0; i < size; i++) { \
        printer(&arr[i]); \
    } \
} while(0)

void print64(void *p);
void printSystemInfo();

int Equals(double a, double b);

void test_v1(size_t N);
int v1(void *px, void *py, void *pz, size_t N);

void run_task8_4()
{
    printf("\nЗадание №4\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    const size_t k = 1;
    
    for (int test = 0; test < 7; test++) {
        size_t N = 4*k + test;
        test_v1(N);
    }

    printf("\n=========================================================================\n");
}

int v1(void *px, void *py, void *pz, size_t N) {
    size_t limit = N - (N % 4);
    
    asm volatile (
        "xor %%rcx, %%rcx\n\t"          // i = 0
        "vbroadcastsd %5, %%ymm3\n\t"   // ymm3 = 2.0
        "1:\n\t"
        "cmp %4, %%rcx\n\t"
        "jge 2f\n\t"
        "vmovupd (%0, %%rcx, 8), %%ymm0\n\t"
        "vmovupd (%1, %%rcx, 8), %%ymm1\n\t"
        "vdivpd %%ymm1, %%ymm0, %%ymm2\n\t"
        "vaddpd %%ymm3, %%ymm2, %%ymm2\n\t"
        "vmovupd %%ymm2, (%2, %%rcx, 8)\n\t"
        "add $4, %%rcx\n\t"
        "jmp 1b\n\t"
        "2:\n\t"
        : 
        : "r"(px), "r"(py), "r"(pz), "r"(N), "r"(limit), "x"(2.0)
        : "rcx", "ymm0", "ymm1", "ymm2", "ymm3", "memory"
    );
    
    return (int)N;
}

void test_v1(size_t N) {
    
    size_t limit = N - (N % 4);
    const double controlValue = -1.1111;

    printf("\n--------Тест N=%zu, Limit=%zu, ControlValue=%.3f--------\n", N, limit, controlValue);

    double *x = (double*)aligned_alloc(32, N * sizeof(double));
    double *y = (double*)aligned_alloc(32, N * sizeof(double));
    double *z = (double*)aligned_alloc(32, N * sizeof(double));

    if (!x || !y || !z) {
        printf("Ошибка выделения памяти\n");
        return;
    }

    // Инициализация x и y для первых N элементов
    for (size_t i = 0; i < limit; i++) {
        x[i] = i + 1.0;
        y[i] = (i + 1) * 2.0;
    }
    // Инициализация защитных элементов (после N) для x, y и z
    for (size_t i = limit; i < N; i++) {
        x[i] = 12345.6789;
        y[i] = 98765.4321;
        z[i] = controlValue; // контрольное значение
    }

    // Запускаем функцию
    int res = v1(x, y, z, N);
    
    // Проверяем корректность вычислений для первых N%4 элементов
    int error = 0;
    for (size_t i = 0; i < limit; i++) {
        if (Equals(z[i], controlValue)) {
            printf("Ошибка вычисления z[%zu]: получили %f\n", i, z[i]);
            error = 1;
        }
    }
    // Проверяем, что N%4  элементы не изменились
    for (size_t i = limit; i < N; i++) {
        if (z[i] != controlValue) {
            printf("Ошибка: z[%zu] изменён, значение %f\n", i, z[i]);
            error = 1;
        }
    }

    if (!error) {
        printf("\t\t\t\t\tТест пройден.\n");
    }
    else{
        printf("\nТест завален.\n Массив расчитанных Z\n");
        PRINT_ARRAY(z, N, print64);
    }

    free(x); free(y); free(z);
}

int Equals(double a, double b) {
    return memcmp(&a, &b, sizeof(double)) == 0;
}

#endif