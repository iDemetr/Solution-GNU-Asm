#ifndef task2_6_H
#define task2_6_H

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define toUInt *(uint32_t*)
#define toInt *(int32_t*)
#define toFloat *(float*)

void print32(void *p);

void run_task2_6()
{
    printf("\nЗадание №6\n");
    printf("=========================================================================\n");
    
    uint32_t umin = 0x00000000;          // минимальное беззнаковое
    uint32_t umax = 0xFFFFFFFF;          // максимальное беззнаковое
    int32_t smin = 0x80000000;           // минимальное знаковое (-2147483648)
    int32_t smax = 0x7FFFFFFF;           // максимальное знаковое (2147483647)

    print32(&umin);
    print32(&umax);
    print32(&smin);
    print32(&smax);

    // Вариант 17: (17-1)%2 + 1 = 1
    int32_t x = 9;
    int32_t y = -9;
    int32_t a = 1;
    int32_t b = 2;
    int32_t c = 12345678;
    int32_t d = 123456789;

    float fx = 9.0f;
    float fy = -9.0f;
    float fa = 1.0f;
    float fb = 2.0f;
    float fc = 12345678.0f;
    float fd = 123456789.0f;

    print32(&x);
    print32(&y);
    print32(&a);
    print32(&b);
    print32(&c);
    print32(&d);

    print32(&fx);
    print32(&fy);
    print32(&fa);
    print32(&fb);
    print32(&fc);
    print32(&fd);

    printf("\n=========================================================================\n");
}

void print32(void *p) {
    printf("%08X %08b %u %+d %+a %+e %+.2f \n", toFloat p, toFloat p, toFloat p, toInt p, toUInt p, toUInt p, toUInt p);
}

#endif