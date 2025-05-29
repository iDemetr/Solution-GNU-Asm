#ifndef task2_4_H
#define task2_4_H

#include <stdio.h>
#include <limits.h>
#include <float.h>

void run_task2_4()
{
    printf("\nЗадание №4\n");
    printf("=========================================================================\n");
    
    printf("Целочисленные типы:\n");

    printf("char:                   min = %d, max = %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char:          min = 0, max = %u\n", UCHAR_MAX);

    printf("short:                  min = %d, max = %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short:         min = 0, max = %u\n", USHRT_MAX);

    printf("int:                    min = %d, max = %d\n", INT_MIN, INT_MAX);
    printf("unsigned int:           min = 0, max = %u\n", UINT_MAX);

    printf("long long:              min = %lld, max = %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long:     min = 0, max = %llu\n", ULLONG_MAX);

    printf("\nПлавающие типы:\n");
    printf("float:                  min = %e, max = %e\n", FLT_MIN, FLT_MAX);
    printf("double:                 min = %e, max = %e\n", DBL_MIN, DBL_MAX);

    printf("\n=========================================================================\n");
}

#endif