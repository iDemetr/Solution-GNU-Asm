#ifndef task5_1_H
#define task5_1_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

void run_task5_1()
{
    printf("\nЗадание №1\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    int x, y, z;
    unsigned char w;

    printf("Введите два целых числа x и y:\n");
    if (scanf("%d %d", &x, &y) != 2) {
        printf("Ошибка ввода\n");
        return;
    }

    // Inline asm: z = x + y; w = OF (знаковое переполнение)
    __asm__ volatile (
        "movl %[x], %%eax\n\t"
        "addl %[y], %%eax\n\t"
        "movl %%eax, %%ebx\n\t"
        "seto %%al\n\t"
        "movb %%al, %[w]\n\t"
        "movl %%ebx, %[z]\n\t"
        : [z] "=r" (z), [w] "=r" (w)
        : [x] "r" (x), [y] "r" (y)
        : "eax", "ebx"
    );

    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = x + y = %d\n", z);
    printf("w (OF flag) = %u\n", w);

    printf("\n=========================================================================\n");
}

#endif