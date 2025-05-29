#ifndef task7_3_H
#define task7_3_H

#include <stdio.h>
#include <stdint.h>

// Макрос для вывода массива с параметризацией массива и делегата вывода
#define PRINT_ARRAY(arr, printer) \
do { \
    size_t n = sizeof(arr) / sizeof(arr[0]); \
    for (int i = 0; i < n; i++) { \
        printer(&arr[i]); \
    } \
} while(0)

#define showABCD printf("a = "); print32(&a); \
    printf("b = "); print32(&b); \
    printf("c = "); print32(&c); \
    printf("d = "); print32(&d);
    
#define showXY printf("x = "); \
    print32(&x); \
    printf("y = "); \
    print32(&y);

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();
//int checkAVXorSSE();

void inc32_asm(void *p);
void inc32_c(void *p);

void run_task7_3()
{
    printf("\nЗадание №6\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    // Инициализация переменных
    float a = 1.0f;
    float b = 2.0f;
    float c = 12345689.0f;
    float d = 123456891.0f;

    // Значения x=5, y=-5, a,b,c,d
    int x = 5;
    int y = -5;

    // Печать исходных значений
    printf("Исходные значения:\n");
    showXY
    showABCD

    // Применяем inc32_asm к float-переменным
    inc32_asm(&a);
    inc32_asm(&b);
    inc32_asm(&c);
    inc32_asm(&d);

    printf("\nПосле inc32_asm:\n");
    showABCD

    // Для сравнения применяем inc32_c к x и y
    inc32_c(&x);
    inc32_c(&y);

    printf("\nПосле inc32_c:\n");
    showXY
    
    printf("=========================================================================\n");
}

void inc32_c(void *p) {
    int *ip = (int *)p;
    (*ip)++;
}

void inc32_asm(void *p) {
    __asm__ volatile (
        "incl (%0)"
        :
        : "r"(p)
        : "memory"
    );
}

#endif