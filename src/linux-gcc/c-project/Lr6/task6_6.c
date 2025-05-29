#ifndef task6_6_H
#define task6_6_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

// Макрос для вывода массива с параметризацией массива и делегата вывода
#define PRINT_ARRAY(arr, printer) \
do { \
    size_t n = sizeof(arr) / sizeof(arr[0]); \
    for (int i = 0; i < n; i++) { \
        printer(&arr[i]); \
    } \
} while(0)

void printSystemInfo();

int mce_si(void *p, size_t N);

void run_task6_6()
{
    printf("\nЗадание №6\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    int arr[] = {2, 3, 4, 5, 6};
    size_t N = sizeof(arr) / sizeof(arr[0]);

    int prod = mce_si(arr, N);
    
    printf("Array:\n");
    PRINT_ARRAY(arr, print32);
    printf("Product of array elements = \n");
    print32(&prod);

    printf("=========================================================================\n");
}

int mce_si(void *p, size_t N) {
    int *arr = (int *)p;
    int result = 1;
    size_t i;

    for (i = 0; i < N; i++) {
        int val = arr[i];
        __asm__ (
            "imull %1, %0"
            : "+r" (result)
            : "r" (val)
        );
    }

    return result;
}

#endif