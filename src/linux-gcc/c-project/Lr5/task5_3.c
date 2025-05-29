#ifndef task5_3_H
#define task5_3_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

void run_task5_3()
{
    printf("\nЗадание №2\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
   
    uint32_t x;
    unsigned char z;

    printf("Введите целое число в любой системе x:\n");
    if (scanf("%i", &x) != 1) {
        printf("Ошибка ввода\n");
        return;
    }

    __asm__ volatile (
        "cmpl $0xFFFFFFFD, %[x]\n\t"  // сравнить x с -3
        "setg %[z]\n\t"               // z = 1, если x > -3 (знаковое сравнение)
        : [z] "=r" (z)
        : [x] "r" (x)
        : "cc"
    );

    printf("z = (%d > -3) = %u\n", x, z);

    printf("=========================================================================\n");
}

#endif