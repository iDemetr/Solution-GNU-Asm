#ifndef task4_4_H
#define task4_4_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

void run_task4_4()
{
    printf("\nЗадание №4\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    short i16;
    int i32;
    long long i64;
    float f32;
    double f64;

    // Форматная строка для scanf: %hd (short), %d (int), %lld (long long), %f (float), %lf (double)
    scanf("%hd %d %lld %f %lf", &i16, &i32, &i64, &f32, &f64);

    // Форматная строка для printf — выводим в том же порядке
    printf("i16=%hd i32=%d i64=%lld f32=%f f64=%lf\n", i16, i32, i64, f32, f64);

    printf("=========================================================================\n");
}

#endif