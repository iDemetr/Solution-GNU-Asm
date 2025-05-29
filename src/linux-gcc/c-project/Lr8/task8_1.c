#ifndef task8_1_H
#define task8_1_H

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

size_t init_pd_C(void *p, size_t N, double x);
size_t init_pd_asm(void *p, size_t N, double x);

void test_init_pd(size_t N, double x);

void run_task8_1()
{
    printf("\nЗадание №1\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    double test_values[] = {1.0, -1.0, 3.1415926535, 1e100, 1e-100};
    int count = sizeof(test_values)/sizeof(test_values[0]);

    for (size_t i = 0; i < count; i++) {
        test_init_pd(i, test_values[i]);
    }

    printf("=========================================================================\n");
}

//__attribute__((target("avx")))
size_t init_pd_asm(void *p, size_t N, double x){
    if (N % 2 != 0) {               // Сокращено для лучшей наглядности
        return (size_t)-1;
    }
    
    asm volatile (
        "vxorpd %%ymm0, %%ymm0, %%ymm0\n\t"      // очистить ymm0 (необязательно, но для примера)
        "vbroadcastsd %2, %%ymm0\n\t"             // vpbroadcastd xmm0 = x в ymm0
        "xor %%rcx, %%rcx\n\t"                     // счетчик i = 0
        "1:\n\t"
        "cmp %1, %%rcx\n\t"
        "jge 2f\n\t"
        "vmovupd %%ymm0, (%0, %%rcx, 8)\n\t"      // записать 4 double (32 байта)
        "add $4, %%rcx\n\t"
        "jmp 1b\n\t"
        "2:\n\t"
        : // нет выходных
        : "r"(p), "r"(N), "m"(x)
        : "rcx", "ymm0", "memory"
    );
    
    return N;
}

__attribute__((target("avx")))
size_t init_pd_С(void *p, size_t N, double x) {
    if (N % 2 != 0) {               // Сокращено для лучшей наглядности
        return (size_t)-1;
    }

    double *arr = (double *)p;
    __m256d val = _mm256_set1_pd(x); // vpbroadcastd

    for (size_t i = 0; i < N; i += 4) {
        _mm256_storeu_pd(&arr[i], val); // vmovupd
    }
    return N;
}

void test_init_pd(size_t N, double x) {
    printf("N = %u\n", N);

    // Выделяем память с выравниванием по 32 байтам для AVX
    double *arr = aligned_alloc(32, N * sizeof(double));
    if (!arr) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return;
    }
    
    // Заполняем массив "мусором" для демонстрации
    memset(arr, 0xCC, N * sizeof(double));

    printf("Тест N=%zu, x=%.2e\n", N, x);
    printf("До инициализации: \n");
    PRINT_ARRAY(arr, N, print64);
    
    // Вызываем ассемблерную функцию
    size_t res = init_pd_asm(arr, N, x);
    
    printf("Возвращено: %d\n", res);
    if(res != -1){
        printf("После инициализации: \n");
        PRINT_ARRAY(arr, N, print64);
    }
    
    free(arr);
}

#endif