#ifndef task7_6_H
#define task7_6_H

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

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();
//int checkAVXorSSE();

double mce_sd(void *p, size_t N);

void run_task7_6()
{
    printf("\nЗадание №6\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    double arr[] = {1.5, 2.0, 3.0};
    size_t N = sizeof(arr) / sizeof(arr[0]);

    double prod = mce_sd(arr, N);
    printf("Array:\n");
    PRINT_ARRAY(arr, print64);
    printf("Product of array elements = \n");
    print64(&prod);

    printf("=========================================================================\n");
}

double mce_sd(void *p, size_t N) {
    double *arr = (double *)p;
    double result = 1.0;
    for (size_t i = 0; i < N; i++) {
        result *= arr[i];
    }
    return result;
}

#endif