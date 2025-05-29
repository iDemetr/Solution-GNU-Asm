#ifndef task5_2_H
#define task5_2_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

void run_task5_2()
{
    printf("\nЗадание №2\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
   
    uint32_t x;
    unsigned char z;

    printf("Введите целое число x:\n");
    if (scanf("%u", &x) != 1) {
        printf("Ошибка ввода\n");
        return;
    }

    // Сравним младшие 32 бита x с 0xFFFFFFFD
    uint32_t x32 = (uint32_t)(x & 0xFFFFFFFF);
    
    __asm__ volatile (
        "cmpl $0xFFFFFFFD, %[x32]\n\t"  // сравнить x с -3
        "seta %[z]\n\t"               // z = 1, если x > -3 
        : [z] "=r" (z)
        : [x32] "r" (x32)
        : "cc"
    );

    printf("z = (%u > -3) = %u\n", x32, z);

    printf("=========================================================================\n");
}

#endif