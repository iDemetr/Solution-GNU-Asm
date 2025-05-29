#ifndef task8_3_H
#define task8_3_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <immintrin.h>  // Для AVX-инструкций
#include <stddef.h>     // Для size_t

// Макрос для вывода массива с параметризацией массива и делегата вывода
#define PRINT_ARRAY(arr, size, printer) \
do { \
    for (size_t i = 0; i < size; i++) { \
        printer(&arr[i]); \
    } \
} while(0)

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

int v4(void *px, void *py, void *pz, size_t N);

void run_task8_3()
{
    printf("\nЗадание №3\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    size_t N = 3;
    double *x = (double*)aligned_alloc(32, N * sizeof(double));
    double *y = (double*)aligned_alloc(32, N * sizeof(double));
    double *z = (double*)aligned_alloc(32, N * sizeof(double));

    if (!x || !y || !z) {
        printf("Ошибка выделения памяти\n");
        return;
    }

    // Инициализируем массивы
    for (size_t i = 0; i < N; i++) {
        x[i] = i + 1.0;      // 1.0, 2.0, ..., 8.0
        y[i] = (i + 1) * 2;  // 2.0, 4.0, ..., 16.0
        z[i] = 0.0;
    }

    printf("\nИсходные данные: N=%u", N);
    printf("\n(𝑥0, ...𝑥3): \n"); PRINT_ARRAY(x, N, print64);
    printf("\n(𝑦0, ...𝑦3): \n"); PRINT_ARRAY(y, N, print64);
    printf("\n(𝑧0, ...𝑧3): \n"); PRINT_ARRAY(z, N, print64);
    
    int res = v4(x, y, z, N);
    if (res < 0) {
        printf("Ошибка: N не кратно 4\n");
        free(x); free(y); free(z);
        return;
    }

    printf("\nРезультат v4:\n");
    PRINT_ARRAY(z,N, print64);

    free(x);
    free(y);
    free(z);

    printf("\n=========================================================================\n");
}

int v4(void *px, void *py, void *pz, size_t N) {
    if (N % 2 != 0) return -1;

    asm volatile (
        "xor %%rcx, %%rcx\n\t"          // i = 0
        "vbroadcastsd %4, %%ymm3\n\t"   // ymm3 = 2.0
        "1:\n\t"
        "cmp %3, %%rcx\n\t"
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
        : "r"(px), "r"(py), "r"(pz), "r"(N), "x"(2.0)
        : "rcx", "ymm0", "ymm1", "ymm2", "ymm3", "memory"
    );

    return (int)N;
}

#endif