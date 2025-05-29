#ifndef task2_8_H
#define task2_8_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void c16to32(void *p);

void run_task2_8()
{
    printf("\nЗадание №8\n");
    printf("=========================================================================\n");
    
    short m = 21;
    short n = -37;

    printf("Для m = 21:\n");
    c16to32(&m);
    printf("\n");

    printf("Для n = -37:\n");
    c16to32(&n);

    printf("\n=========================================================================\n");
}

// Функция c16to32
void c16to32(void *p) {
    short val16 = *(short*)p;
    
    printf("Исходное 16-битное значение:\n");
    print16(&val16);

    // Расширение знаковое
    int val32_signed = (int)val16;
    
    printf("Знаковое расширение до 32 бит:\n");
    print32(&val32_signed);

    // Расширение беззнаковое
    unsigned int val32_unsigned = (unsigned int)(unsigned short)val16;
    
    printf("Беззнаковое расширение до 32 бит:\n");
    print32(&val32_unsigned);
}

#endif