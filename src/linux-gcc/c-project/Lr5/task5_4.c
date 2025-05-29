#ifndef task5_4_H
#define task5_4_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

void run_task5_4()
{
    printf("\nЗадание №4\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
   
    float x;
    unsigned char z;
    float cmp_val = -3.0f;

    printf("Введите число с плавающей точкой x:\n");
    if (scanf("%f", &x) != 1) {
        printf("Ошибка ввода\n");
        return;
    }

    __asm__ volatile (
        "vmovss %[x], %%xmm0\n\t"        // загрузить x в xmm0
        "vmovss %[cmp_val], %%xmm1\n\t"  // загрузить -3.0 в xmm1
        "vcomiss %%xmm1, %%xmm0\n\t"     // сравнить xmm0 с xmm1 (x с -3.0)
        "setg %[z]\n\t"                  // z = 1, если x > -3.0, иначе 0
        : [z] "=r" (z)
        : [x] "m" (x), [cmp_val] "m" (cmp_val)
        : "xmm0", "xmm1", "cc"
    );

    printf("z = (%0.3f > -3) = %u\n", x, z);

    printf("=========================================================================\n");
}

#endif