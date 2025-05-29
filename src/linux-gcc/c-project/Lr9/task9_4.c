#ifndef task9_4_H
#define task9_4_H

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

int FPU_compute4(double x);

void run_task9_4()
{
    printf("\nЗадание №4\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    double x1 = -2.0, x2 = -3.0, x3 = -4.0; 
    int z;
    
    z = FPU_compute4(x1);
    printf("z = (%f > -3) = %i\n", x1, z);
    
    z = FPU_compute4(x2);
    printf("z = (%f > -3) = %i\n", x2, z);
    
    z = FPU_compute4(x3);
    printf("z = (%f > -3) = %i\n", x3, z);
    
    printf("=========================================================================\n");
}

int FPU_compute4(double x) {
    int result;
    const double compare_v = -3.0;
    
    __asm__ volatile (
        "fldl %2\n\t"                   // st0 = -3
        "fldl %1\n\t"                   // st0 = x, st1 = -3
        "fcomip \n\t"                   // сравнить st0(-3) и st1(x), удалить st0
        "fstp %%st(0)\n\t"              // очистить стек FPU
        "seta %b0\n\t"                  // если x > -3, seta = 1, иначе 0
        : "=r" (result)
        : "m"(x), "m"(compare_v)
        : "cc", "st", "st(1)"
    );
    return result;
}

#endif