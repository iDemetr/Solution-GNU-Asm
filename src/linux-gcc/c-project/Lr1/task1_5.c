#ifndef task1_5_H
#define task1_5_H

#include <stdio.h>
#include <stdlib.h>

#define N 5
#define R 3

void run_task1_5()
{
    printf("\nЗадание №5\n");
    
    // Инициализация массива
    unsigned int Ml[N] = {0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA};
    
    printf("=========================================================================\n");
    

    printf("Адрес начала массива Ml (Ml): %p\n", (void*)Ml);
    printf("Адрес Ml[0]: %p\n", (void*)&Ml[0]);
    printf("Адрес Ml[1]: %p\n", (void*)&Ml[1]);

    printf("Размер элемента массива Ml: %zu байт\n", sizeof(Ml[0]));

    // Создаём статическую матрицу MM типа unsigned int
    unsigned int MM[R][N] = {0};

    printf("\nАдреса элементов матрицы MM:\n");
    printf("MM[0][0]: %p\n", (void*)&MM[0][0]);
    printf("MM[0][1]: %p\n", (void*)&MM[0][1]);
    printf("MM[1][0]: %p\n", (void*)&MM[1][0]);
    printf("MM[1][1]: %p\n", (void*)&MM[1][1]);

    /*
    Анализ:
    - Адрес Ml и &Ml[0] совпадают, это начало массива.
    - Адрес Ml[1] должен быть на sizeof(unsigned int) байт дальше.
    - В памяти элементы массива расположены подряд (contiguous).
    - Аналогично, в матрице MM элементы каждой строки расположены подряд.
    - Адрес MM[0][1] на sizeof(unsigned int) байт дальше MM[0][0].
    - Адрес MM[1][0] находится на sizeof(unsigned int)*N байт дальше MM[0][0].
    */

    // Как воспроизвести структуру матрицы на динамическом массиве:
    // Нужно выделить память под R*N элементов типа unsigned int:
    unsigned int *dynamic_MM = (unsigned int*)malloc(R * N * sizeof(unsigned int));
    if (!dynamic_MM) {
        puts("Ошибка выделения памяти");
        return;
    }

    // Индекс в одномерном массиве для элемента [i][j]:
    // idx = i * N + j;

    printf("\nДля динамического массива:\n");
    printf("Адрес dynamic_MM: %p\n", (void*)dynamic_MM);
    printf("Адрес элемента dynamic_MM[0]: %p\n", (void*)&dynamic_MM[0]);
    printf("Адрес элемента dynamic_MM[1]: %p\n", (void*)&dynamic_MM[1]);
    printf("Адрес элемента dynamic_MM[N]: %p (начало второй строки)\n", (void*)&dynamic_MM[N]);

    // Освобождаем память
    free(dynamic_MM);

    printf("\n=========================================================================\n");
    
    printf("\n");
}

#endif