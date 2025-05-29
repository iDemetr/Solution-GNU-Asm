#ifndef task6_5_H
#define task6_5_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

int mul16(int x);

void run_task6_5()
{
    printf("\nЗадание №5\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    int x = 7;
    int z = mul16(x);
    printf("16 * %d = %d\n", x, z);

    printf("=========================================================================\n");
}

int mul16(int x) {
    int z;
    __asm__ (
        "sal $4, %1\n\t"
        "movl %1, %0"
        : "=r"(z)
        : "r"(x)
    );
    return z;
}

#endif