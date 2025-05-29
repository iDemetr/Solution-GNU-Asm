#ifndef task7_1_H
#define task7_1_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

float harmonic_sum_float_forward(int N);
float harmonic_sum_float_backward(int N);
double harmonic_sum_double_forward(int N);
double harmonic_sum_double_backward(int N);

void run_task7_1()
{
    printf("\nЗадание №1\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    int Ns[] = {1000, 1000000, 1000000000};
    int count = sizeof(Ns)/sizeof(Ns[0]);

    for (int idx = 0; idx < count; idx++) {
        int N = Ns[idx];
        printf("N = %e\n", (double)N);

        float Sf = harmonic_sum_float_forward(N);
        float Sb = harmonic_sum_float_backward(N);

        double Sd = harmonic_sum_double_forward(N);
        double Sb_d = harmonic_sum_double_backward(N);

        printf("float sum forward:  ");
        print32(&Sf);
        printf("float sum backward: ");
        print32(&Sb);

        printf("double sum forward:  ");
        print64(&Sd);
        printf("double sum backward: ");
        print64(&Sb_d);
    }

    printf("=========================================================================\n");
}

// Сумма float от 1 до N (наивный порядок)
float harmonic_sum_float_forward(int N) {
    float sum = 0.0f;
    for (int i = 1; i <= N; i++) {
        float term = 1.0f / (float)i;
        sum += term;
    }
    return sum;
}

// Сумма float от N до 1 (обратный порядок)
float harmonic_sum_float_backward(int N) {
    float sum = 0.0f;
    for (int i = N; i >= 1; i--) {
        float term = 1.0f / (float)i;
        sum += term;
    }
    return sum;
}

// Сумма double от 1 до N (наивный порядок)
double harmonic_sum_double_forward(int N) {
    double sum = 0.0;
    for (int i = 1; i <= N; i++) {
        double term = 1.0 / (double)i;
        sum += term;
    }
    return sum;
}

// Сумма double от N до 1 (обратный порядок)
double harmonic_sum_double_backward(int N) {
    double sum = 0.0;
    for (int i = N; i >= 1; i--) {
        double term = 1.0 / (double)i;
        sum += term;
    }
    return sum;
}

#endif