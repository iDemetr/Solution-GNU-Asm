#ifndef task9_2_H
#define task9_2_H

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

double fpu_atan2(double x, double y);

void run_task9_2()
{
    printf("\nЗадание №2\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    double x, y;
    printf("Введите x y: ");
    if (scanf("%lf %lf", &x, &y) != 2) {
        printf("Ошибка ввода\n");
        return;
    }

    double z_fpu = fpu_atan2(x, y);
    printf("atan2(%.3f, %.3f) = \n", x, y);
    print64(&z_fpu);
    
    printf("=========================================================================\n");
}

double fpu_atan2(double x, double y)
{
    double z;
    __asm__ volatile (
        "fldl %1\n\t"       // st0 = x
        "fldl %2\n\t"       // st0 = y, st1 = x
        "fpatan\n\t"        // st0 = atan2(x, y)
        "fstpl %0\n\t"
        : "=m"(z)
        : "m"(x), "m"(y)
        : "st", "st(1)", "st(2)"
    );
    return z;
}

#endif