#ifndef task5_8_H
#define task5_8_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void print_matrix(int *M, size_t R, size_t C);
void mre(void *pM, size_t R, size_t C, size_t j);

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

void run_task5_8()
{
    printf("\nЗадание №8\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
   
    size_t R = 4, C = 5;
    int *M = (int*)malloc(R * C * sizeof(int));
    if (!M) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        return;
    }

    // Заполнение матрицы числами от 0 до R*C-1
    for (size_t i = 0; i < R; i++) {
        for (size_t k = 0; k < C; k++) {
            M[i*C + k] = (int)(i*C + k);
        }
    }

    printf("Исходная матрица:\n");
    print_matrix(M, R, C);

    size_t j = 2; // например, заменяем 3-й столбец (индексация с 0)
    mre(M, R, C, j);

    printf("Матрица после замены столбца %zu на -1:\n", j);
    print_matrix(M, R, C);

    free(M);

    printf("=========================================================================\n");
}

void print_matrix(int *M, size_t R, size_t C) {
    for (size_t i = 0; i < R; i++) {
        for (size_t k = 0; k < C; k++) {
            printf("%d ", M[i*C + k]);
        }
        printf("\n");
    }
}

void mre(void *pM, size_t R, size_t C, size_t j) {
    __asm__ volatile (
        // Загружаем параметры в регистры
        "mov %[pM], %%rdi\n\t"     // rdi = указатель на матрицу (M)
        "mov %[R], %%rcx\n\t"      // rcx = количество строк (R)
        "mov %[C], %%r8\n\t"       // r8 = количество столбцов (C)
        "mov %[j], %%r9\n\t"       // r9 = индекс столбца (j)
        "xor %%r10, %%r10\n\t"     // r10 = счётчик строк (i) = 0
        
        // Проверка на нулевые размеры
        "test %%rcx, %%rcx\n\t"
        "jz 2f\n\t"
        
        "1:\n\t"
        // Вычисляем адрес элемента M[i][j] = M + (i * C + j) * sizeof(int)
        "mov %%r10, %%rax\n\t"     // rax = i
        "mul %%r8\n\t"             // rax = i * C
        "add %%r9, %%rax\n\t"      // rax = i * C + j
        "movl $-1, (%%rdi, %%rax, 4)\n\t" // M[i][j] = -1
        
        // Увеличиваем счётчик и проверяем условие
        "inc %%r10\n\t"
        "cmp %%rcx, %%r10\n\t"
        "jl 1b\n\t"
        
        "2:\n\t"
        : // Нет выходных операндов
        : [pM] "r" (pM), [R] "r" (R), [C] "r" (C), [j] "r" (j)
        : "rax", "rcx", "rdi", "r8", "r9", "r10", "memory", "cc"
    );
}

#endif