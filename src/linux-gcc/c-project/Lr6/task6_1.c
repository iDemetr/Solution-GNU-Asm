#ifndef task6_1_H
#define task6_1_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

void fc16_c(void *p);

void run_task6_1()
{
    printf("\nЗадание №1\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    unsigned short x;

    printf("Введите число x :");
    if (scanf("%d", &x) != 1) {
        printf("Ошибка ввода\n");
        return;
    }

    fc16_c(&x);

    printf("=========================================================================\n");
}

// Функция округления вниз и вверх до кратного 32 без ветвлений
void fc16_c(void *p) {
    uint16_t *x_ptr = (uint16_t*)p;
    uint16_t x = *x_ptr;
    uint16_t D = 32;
    uint16_t mask = ~(D - 1);  // 0xFFE0 для D=32

    uint16_t x1 = x & mask;           // округление вниз
    uint16_t x2 = (x + D - 1) & mask; // округление вверх

    // Печать исходного и результатов
    print16(&x);
    print16(&x1);
    print16(&x2);
}

#endif