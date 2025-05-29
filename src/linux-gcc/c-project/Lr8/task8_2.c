#ifndef task8_2_H
#define task8_2_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <immintrin.h>  // Для AVX-инструкций
#include <stddef.h>     // Для size_t

// Макрос для вывода массива с параметризацией массива и делегата вывода
#define PRINT_ARRAY(arr, printer) \
do { \
    size_t n = sizeof(arr) / sizeof(arr[0]); \
    for (int i = 0; i < n; i++) { \
        printer(&arr[i]); \
    } \
} while(0)

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

void compute_z_avx_asm(const double *x, const double *y, double *z);
void compute_z_avx_c(const double *x, const double *y, double *z);

void run_task8_2()
{
    printf("\nЗадание №2\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
 
    double arrX[] = {1.0, -1.0, 2.2, 3.3};
    double arrY[] = {4.4, 5.5, 6.6, 7.7};
    double arrZ[] = {0,0,0,0};
    
    printf("\nИсходные данные: ");
    printf("\n(𝑥0, ...𝑥3): \n"); PRINT_ARRAY(arrX, print64);
    printf("\n(𝑦0, ...𝑦3): \n"); PRINT_ARRAY(arrY, print64);
    
    compute_z_avx_asm(arrX, arrY, arrZ);
    
    printf("\nРезультат ассемблерной ф-ии: ");
    printf("\n(𝑧0, ...𝑧3): \n"); PRINT_ARRAY(arrZ, print64);
    
    memset(arrZ, 0, sizeof(arrZ)); // Обнуление
    
    compute_z_avx_c(arrX, arrY, arrZ);
     
    printf("\nРезультат Си ф-ии: ");
    printf("\n(𝑧0, ...𝑧3): \n"); PRINT_ARRAY(arrZ, print64);
 
    printf("\n=========================================================================\n");
}


void compute_z_avx_asm(const double *x, const double *y, double *z) {
    asm volatile (
        "vmovupd (%0), %%ymm0\n\t"              // загрузить x0..x3
        "vmovupd (%1), %%ymm1\n\t"              // загрузить y0..y3
        "vdivpd %%ymm1, %%ymm0, %%ymm2\n\t"     // ymm2 = ymm0 / ymm1
        "vbroadcastsd %3, %%ymm3\n\t"           // ymm3 = 2.0
        "vaddpd %%ymm3, %%ymm2, %%ymm2\n\t"     // ymm2 += 2.0
        "vmovupd %%ymm2, (%2)\n\t"              // сохранить z0..z3
        :
        : "r"(x), "r"(y), "r"(z), "x"(2.0)
        : "ymm0", "ymm1", "ymm2", "ymm3", "memory"
    );
}

__attribute__((target("avx")))
void compute_z_avx_c(const double *x, const double *y, double *z) {
    __m256d vx = _mm256_loadu_pd(x);        // vmovupd
    __m256d vy = _mm256_loadu_pd(y);        // vmovupd
    __m256d v2 = _mm256_set1_pd(2.0);       // vpbroadcastd

    __m256d vdiv = _mm256_div_pd(vx, vy);   // vdivpd
    __m256d vres = _mm256_add_pd(vdiv, v2); // vaddpd

    _mm256_storeu_pd(z, vres);              // vmovupd
}

#endif