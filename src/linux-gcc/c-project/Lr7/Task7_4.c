#ifndef task7_4_H
#define task7_4_H

#include <stdio.h>
#include <stdint.h>
#include <immintrin.h>  // Для AVX intrinsics

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();
int checkAVXorSSE();

double avx_compute(double x, double y);

void run_task7_4()
{
    printf("\nЗадание №4\n");
    printf("=========================================================================");
    printSystemInfo();
    checkAVXorSSE();
    printf("=========================================================================\n");
    
    double x = 2.0;
    double y = 3.0;

    double z = avx_compute(x, y);
    printf("z = 1 - 5/%.3f - %.3f^2/7 = %e\n", x, y, z);

    printf("=========================================================================\n");
}

double avx_compute(double x, double y) {
    __m128d vx = _mm_set_sd(x);
    __m128d vy = _mm_set_sd(y);
    
    __m128d five = _mm_set_sd(5.0);
    __m128d one = _mm_set_sd(1.0);
    __m128d seven = _mm_set_sd(7.0);
    
    __m128d div1 = _mm_div_sd(five, vx);
    __m128d y_sq = _mm_mul_sd(vy, vy);
    __m128d div2 = _mm_div_sd(y_sq, seven);
    __m128d res = _mm_sub_sd(one, div1);
    res = _mm_sub_sd(res, div2);
    
    double result;
    _mm_store_sd(&result, res);
    return result;
}

#endif