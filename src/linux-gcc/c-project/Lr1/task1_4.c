#include <stdint.h>   // для uint64_t
#include <stddef.h>   // для size_t, wchar_t, ptrdiff_t
#include <stdbool.h>  // для bool
#include <stdio.h>    // для printf и других функций ввода-вывода

#include "task1_4.h"

// Функция ввода элемента M[i] с проверкой для целочисленных типов
int input_element_int(void *element, const char *fmt) {
    int ret = scanf(fmt, element);
    if (ret != 1) {
        puts("Ошибка ввода! Попробуйте ещё раз.");
        // Очищаем буфер ввода
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        return 0;
    }
    return 1;
}

// Функция ввода элемента M[i] с проверкой для плавающей точки
int input_element_float(void *element, const char *fmt) {
    int ret = scanf(fmt, element);
    if (ret != 1) {
        puts("Ошибка ввода! Попробуйте ещё раз.");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
        return 0;
    }
    return 1;
}