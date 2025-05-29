#ifndef task4_1_H
#define task4_1_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

int64_t f1(int64_t x, int64_t y);

void run_task4_1()
{
    printf("\nЗадание №1\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    int64_t x = 5;
    int64_t y = 3;
    int64_t result = f1(x, y);

    printf("f1 (\nx= ");
    print64(&x);
    printf(",\ny= ");
    print64(&y); 
    printf(") =\n");
    print64(&result);

    printf("\n=========================================================================\n");
}

int64_t f1(int64_t x, int64_t y) {
    int64_t result;
    __asm__ (
        "lea (%1, %2, 8), %0\n\t"  // result = x + 8*y
        "sub $7, %0"
        : "=&r" (result)            // output operand
        : "r" (x), "r" (y)          // input operands
    );
    return result;
}

#endif