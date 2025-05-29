#ifndef task6_3_H
#define task6_3_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

int calc_z(int x, int y);

void run_task6_3()
{
    printf("\nЗадание №3\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    int x = 5;
    int y = 3;

    int z = calc_z(x, y);
    printf("z = 12 - %d - %d^2 = %d\n", x, y, z);
    
    printf("=========================================================================\n");
}

// Функция округления вниз и вверх до кратного 32 без ветвлений
int calc_z(int x, int y) {
    int z;
    int y_sq;

    // Вычисляем y^2
    __asm__ (
        "imull %1, %1;"   // y = y * y
        : "+r" (y)
    );

    y_sq = y;

    // Вычисляем z = 12 - x - y_sq
    __asm__ (
        "movl $12, %0;"
        "subl %1, %0;"
        "subl %2, %0;"
        : "=&r" (z)
        : "r" (x), "r" (y_sq)
    );

    return z;
}

#endif