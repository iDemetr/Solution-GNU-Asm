#ifndef task9_1_H
#define task9_1_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <immintrin.h>  // Для AVX-инструкций
#include <stddef.h>     // Для size_t

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

double avx_compute(double x, double y);
double FPU_compute(double x, double y);

void run_task9_1()
{
    printf("\nЗадание №1\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    double x = 2.0, y = 3.0;
    
    double z_fpu = FPU_compute(x, y);
    double z_avx = avx_compute(x, y);
    
    printf("z = 1 - 5/%.3f - %.3f^2/7 = \n", x, y);
    printf("fpu: "); print64(&z_fpu);
    printf("avx: "); print64(&z_avx);
    
    printf("=========================================================================\n");
}

double FPU_compute(double x, double y)
{
    double z;
    const double five = 5.0,  seven = 7.0, one = 1.0;
    
    __asm__ volatile (
        "fldl %2\n\t"               // Загружаем y в st0
        "fmul %%st(0), %%st(0)\n\t" // st0 = y²
        "fldl %5\n\t"               // st0 = 7, st1 = y²
        "fdivrp \n\t"               // st0 = y²/7                               ST(1)/ST(0)
        
        "fldl %1\n\t"               // st0 = x, st1 = y²/7
        "fldl %3\n\t"               // st0 = 5, st1 = x, st2 = y²/7
        "fdivp \n\t"                // st0 = 5/x, st1 = y²/7                    ST(0)/ST(1)
        
        "fldl %4\n\t"               // st0 = 1, st1 = 5/x, st2 = y²/7
        "fsubp \n\t"                // st0 = (1-5/x) - y²/7                     ST(0) – ST(1)
        "fsubp \n\t"                // st0 = (1 - 5/x - y²/7)                   ST(0) – ST(1)
        "fstpl %0\n\t"              // Сохраняем результат в z
        : "=m"(z)
        : "m"(x), "m"(y), "m"(five), "m"(one), "m"(seven)
        : "st", "st(1)", "st(2)"
    );
    return z;
}

#endif