#ifndef task9_3_H
#define task9_3_H

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

double FPU_compute3(double x, double y);

void run_task9_3()
{
    printf("\nЗадание №3\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    double x, y;
    printf("Введите x y: ");
    if (scanf("%lf %lf", &x, &y) != 2) {
        printf("Ошибка ввода\n");
        return;
    }

    double z_fpu = FPU_compute3(x, y);
    printf("z = %.3f * log2(%.3f - 1) = \n", y, x);
    print64(&z_fpu);
    
    printf("=========================================================================\n");
}

double FPU_compute3(double x, double y) {
    double z;
    __asm__ volatile (
        "fldl %2\n\t"           // st0 = y
        "fldl %1\n\t"           // st0 = x, st1 = y
            "fyl2xp1\n\t"           // st1 * log2(st0) -> st0
        "fstpl %0\n\t"
        : "=m"(z)
        : "m"(x), "m"(y)
        : "st"
    );
    return z;
}

#endif