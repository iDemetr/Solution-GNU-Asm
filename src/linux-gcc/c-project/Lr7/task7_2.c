#ifndef task7_2_H
#define task7_2_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

float float_abs(float x);

void run_task7_2()
{
    printf("\nЗадание №2\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    float x = -123.456f;
    printf("x = ");
    print32(&x);

    float abs_x = float_abs(x);
    printf("|x| = ");
    print32(&abs_x);

    printf("=========================================================================\n");
}

float float_abs(float x) {
    uint32_t *p = (uint32_t *)&x;
    uint32_t bits = *p;   

    // Сброс знакового бита (старший бит)
    bits &= 0x7FFFFFFF;

    float *res = (float *)&bits;
    return *res;
}

#endif