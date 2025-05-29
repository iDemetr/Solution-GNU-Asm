#ifndef task3_6_H
#define task3_6_H

#define N 5

// Макрос для вывода массива с параметризацией массива и делегата вывода
#define PRINT_ARRAY(arr, printer) \
do { \
    for (int i = 0; i < N; i++) { \
        printer(&arr[i]); \
    } \
} while(0)

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void run_task3_6()
{
    printf("\nЗадание №6\n");
    printf("=========================================================================\n");
    
    uint64_t x = 0x123456789ABCDEF0;
    uint64_t y = 0x0FEDCBA987654321;
    uint64_t z = 0;
    uint64_t w = 0;

    printf("Before:\n");
    printf("x = ");
    print32(&x);
    printf("y = ");
    print32(&y);
    printf("z = ");
    print32(&z);
    printf("w = ");
    print32(&w);

    __asm__ volatile (
        "mov %[x], %%rax\n\t"   // rax = x
        "add %[y], %%rax\n\t"   // rax = x + y
        "mov %%rax, %[z]\n\t"   // z = rax

        "mov %[x], %%rbx\n\t"   // rbx = x
        "sub %[y], %%rbx\n\t"   // rbx = x - y
        "mov %%rbx, %[w]\n\t"   // w = rbx
        : [z] "=r" (z), [w] "=r" (w)
        : [x] "r" (x), [y] "r" (y)
        : "rax", "rbx"
    );

    printf("After:\n");
    printf("x = ");
    print32(&x);
    printf("y = ");
    print32(&y);
    printf("z = ");
    print32(&z);
    printf("w = ");
    print32(&w);

    printf("\n=========================================================================\n");
}

#endif