#ifndef task4_2_H
#define task4_2_H

#include <stdio.h>
#include <stdint.h>
#include <immintrin.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

double f2(double x, double y);

void run_task4_2()
{
    printf("\nЗадание №2\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    double x = 5.0, y = 3.0;
    double result = f2(x, y);

    printf("f2 (\nx= ");
    print64(&x);
    printf(",\ny= ");
    print64(&y); 
    printf(") =\n");
    print64(&result);

    printf("\n=========================================================================\n");
}

double f2_1(double x, double y) {
    double result;
    __asm__ (
        "vsubsd %2, %1, %0"
        : "=x" (result)      // output in xmm register
        : "x" (x), "x" (y)   // inputs in xmm registers
    );
    return result;
}

double f2(double x, double y) {
    __m128d X = _mm_set_sd(x);
    __m128d Y = _mm_set_sd(y);
    __m128d R = _mm_sub_sd(X, Y);
    double result;
    _mm_store_sd(&result, R);
    return result;
}

#endif