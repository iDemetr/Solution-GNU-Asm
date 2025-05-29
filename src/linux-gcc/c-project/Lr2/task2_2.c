
#include <stdio.h>
#include <stdint.h>

#include "task2_2.h"

void viewPointer(void *p) {
    char *p1 = (char *)p;
    unsigned short *p2 = (unsigned short *)p;
    double *p3 = (double *)p;

    printf("Адреса указателей:\n");
    printf("p  = %p\n", p);
    printf("p1 = %p\n", (void *)p1);
    printf("p2 = %p\n", (void *)p2);
    printf("p3 = %p\n", (void *)p3);

    printf("\nАдреса p_i + 1:\n");
    printf("p1 + 1 = %p (разница %ld байт)\n", (void *)(p1 + 1), (char *)(p1 + 1) - (char *)p1);
    printf("p2 + 1 = %p (разница %ld байт)\n", (void *)(p2 + 1), (char *)(p2 + 1) - (char *)p2);
    printf("p3 + 1 = %p (разница %ld байт)\n", (void *)(p3 + 1), (char *)(p3 + 1) - (char *)p3);

    printf("\nРазмеры типов:\n");
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(unsigned short) = %zu\n", sizeof(unsigned short));
    printf("sizeof(double) = %zu\n", sizeof(double));
}

void printPointer(void *p) {
    char *p1 = (char *)p;
    unsigned short *p2 = (unsigned short *)p;
    double *p3 = (double *)p;

    printf("Значения по адресам:\n");

    // Для char — выводим как символы и шестнадцатеричные значения
    printf("*p1 = '%c' (0x%02X)\n", *p1, (unsigned char)*p1);
    printf("*(p1+1) = '%c' (0x%02X)\n", *(p1 + 1), (unsigned char)*(p1 + 1));

    // Для unsigned short — выводим в hex
    printf("*p2 = 0x%04X\n", *p2);
    printf("*(p2+1) = 0x%04X\n", *(p2 + 1));

    // Для double — выводим в формате %g (число с плавающей точкой)
    printf("*p3 = %g\n", *p3);
    printf("*(p3+1) = %g\n", *(p3 + 1));
}
