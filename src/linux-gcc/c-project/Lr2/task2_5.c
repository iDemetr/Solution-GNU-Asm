#ifndef task2_5_H
#define task2_5_H

#include <stdio.h>

#define toUshort *(unsigned short*)
#define toshort *(short*)

void print16(void *p);

void run_task2_5()
{
    printf("\nЗадание №5\n");
    printf("=========================================================================\n");
    
    unsigned short umin = 0x0000;          // минимальное беззнаковое
    unsigned short umax = 0xFFFF;          // максимальное беззнаковое
    short smin = (short)0x8000;            // минимальное знаковое (-32768)
    short smax = 0x7FFF;                   // максимальное знаковое (32767)

    print16(&umin);
    print16(&umax);
    print16(&smin);
    print16(&smax);

    // Вариант 17: (17-1)%2 + 1 = 1
    short x = 9;
    short y = -9;
    short a = 1;
    short b = 2;

    print16(&x);
    print16(&y);
    print16(&a);
    print16(&b);


    printf("\n=========================================================================\n");
}

void print16(void *p) {
    // Интерпретируем указатель как unsigned short и short
    // Вывод шестнадцатеричного представления беззнакового числа (4 символа с ведущими нулями) %04X
    // Вывод двоичного представления (от старшего бита к младшему) %08b
    // Вывод десятичного беззнакового числа %u
    // Вывод десятичного знакового числа с явным знаком %+d
    printf("%04X %08b %u %+d \n", toUshort p,  toUshort p, toUshort p,  toshort p);
}

#endif