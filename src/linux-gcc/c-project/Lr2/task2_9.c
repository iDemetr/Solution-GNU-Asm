#ifndef task2_9_H
#define task2_9_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void ab16(void *p);

void run_task2_9()
{
    printf("\nЗадание №9\n");
    printf("=========================================================================\n");
    
    short m = 21;
    short n = -37;

    printf("Результаты для m = 21:\n");
    ab16(&m);
    printf("\n");

    printf("Результаты для n = -37:\n");
    ab16(&n);

    printf("\n=========================================================================\n");
}

void ab16(void *p) {
    short sx = *(short*)p;                      // знаковое 16-битное
    unsigned short ux = *(unsigned short*)p;    // беззнаковое 16-битное

    printf("Исходное значение:\n");
    print16(p);

    printf("а1) беззнаковое умножение на 2: ");
    print16(&(unsigned short){ux * 2});

    printf("а2) знаковое умножение на 2: ");
    print16(&(short){sx * 2});

    printf("а3) беззнаковое деление на 2: ");
    print16(&(unsigned short){ux / 2});

    printf("а4) знаковое деление на 2: ");
    print16(&(short){sx / 2});

    printf("а5) остаток от беззнакового деления на 16: ");
    print16(&(unsigned short){ux % 16});

    printf("а6) округление вниз до числа, кратного 16: ");
    print16(&(unsigned short){ux & ~0xF});

    printf("б1) беззнаковый сдвиг влево на 1 бит: ");
    print16(&(unsigned short){ux << 1});

    printf("б2) знаковый сдвиг влево на 1 бит: ");
    print16(&(short){sx << 1});

    printf("б3) беззнаковый сдвиг вправо на 1 бит: ");
    print16(&(unsigned short){ux >> 1});

    printf("б4) знаковый сдвиг вправо на 1 бит: ");
    print16(&(short){sx >> 1});

    printf("б5) расчёт x & 15: ");
    print16(&(short){sx & 15});

    printf("б6) расчёт x & -16: ");
    print16(&(short){sx & (-16)});
}

#endif