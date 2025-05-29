#ifndef task2_7_H
#define task2_7_H

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define toUInt64(p) (*(uint64_t*)(p))
#define toInt64(p)  (*(int64_t*)(p))
#define toDouble(p) (*(double*)(p))

void print64(void *p);

void run_task2_7()
{
    printf("\nЗадание №6\n");
    printf("=========================================================================\n");
    
        // 1. Целочисленные значения long long и unsigned long long
    long long x_ll = 9LL;
    long long y_ll = -9LL;
    unsigned long long a_ull = 1ULL;
    unsigned long long b_ull = 2ULL;
    unsigned long long c_ull = 12345678ULL;
    unsigned long long d_ull = 123456789ULL;

    printf("Целочисленные значения:\n");

    printf("x_ll = 9:\n");
    print64(&x_ll);
    printf("\n");

    printf("y_ll = -9:\n");
    print64(&y_ll);
    printf("\n");

    printf("a_ull = 1:\n");
    print64(&a_ull);
    printf("\n");

    printf("b_ull = 2:\n");
    print64(&b_ull);
    printf("\n");

    printf("c_ull = 12345678:\n");
    print64(&c_ull);
    printf("\n");

    printf("d_ull = 123456789:\n");
    print64(&d_ull);
    printf("\n");

    // 2. Double значения x и a
    double x_d = 9.0;
    double a_d = 1.0;

    printf("Double значения:\n");

    printf("x_d = 9.0:\n");
    print64(&x_d);
    printf("\n");

    printf("a_d = 1.0:\n");
    print64(&a_d);
    printf("\n");

    // 3. Различия одного и того же значения в float и double
    float f_val = 9.0f;
    double d_val = 9.0;

    printf("Сравнение float и double для 9.0:\n");
    printf("float:  %08X (hex), %.7f (decimal)\n", *(uint32_t*)&f_val, f_val);
    printf("double: %016llX (hex), %.15f (decimal)\n", *(unsigned long long*)&d_val, d_val);
    printf("\n");

    printf("\n=========================================================================\n");
}

void print64(void *p) {
    printf("%016llX %lb %llu %+lld %+a %+e %+.2f\n", toUInt64(p), toUInt64(p), toUInt64(p), toInt64(p), toDouble(p), toDouble(p), toDouble(p));
}

#endif