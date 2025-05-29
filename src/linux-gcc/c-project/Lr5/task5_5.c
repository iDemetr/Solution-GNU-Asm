#ifndef task5_5_H
#define task5_5_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

void run_task5_5()
{
    printf("\nЗадание №5\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
   
    unsigned int x;
    unsigned int z;
    
    printf("Введите целое беззнаковое число x: ");
    if (scanf("%u", &x) != 1) {
        printf("Ошибка ввода\n");
        return ;
    }

    __asm__ volatile (
        "mov %[x], %%eax;"      // eax = x
        "lea -2(%%eax), %%ecx;" // ecx = x - 2
        "mov $25, %%edx;"       // edx = 25
        "cmp $2, %%eax;"        // сравниваем x с 2
        "cmovb %%edx, %%ecx;"   // если x < 2, то ecx = 25
        "mov %%ecx, %[z];"      // z = ecx
        : [z] "=r" (z)
        : [x] "r" (x)
        : "eax", "ecx", "edx"
    );

    printf("Результат: z = %u\n", z);

    printf("=========================================================================\n");
}

#endif