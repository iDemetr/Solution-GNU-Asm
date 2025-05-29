#ifndef task7_5_H
#define task7_5_H

#pragma comment(lib, "m")  // Явное указание линковать с libm

#include <math.h>
#include <stdio.h>
#include <stdint.h>
//#include <immintrin.h>  // Для AVX intrinsics

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();
//int checkAVXorSSE();

double my_atan2(double y, double x);

void run_task7_5()
{
    printf("\nЗадание №5\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    double x, y;
    printf("Введите x y: ");
    if (scanf("%lf %lf", &x, &y) != 2) {
        printf("Ошибка ввода\n");
        return;
    }

    double z = my_atan2(x, y);
    printf("atan2(%.3f, %.3f) = %e\n", x, y, z);

    printf("=========================================================================\n");
}

double my_atan2(double y, double x) {
    double result;
    __asm__ (
        "fpatan"                   // Инструкция процессора для atan2
        : "=t" (result)            // Результат в ST(0)
        : "0" (x), "u" (y)         // Входные значения в ST(0) и ST(1)
        : "st(1)"                  // Регистр FPU, который будет изменён
    );
    return result;
}

#endif