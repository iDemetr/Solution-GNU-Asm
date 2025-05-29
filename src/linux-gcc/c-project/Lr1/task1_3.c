#include <stdint.h>   // для uint64_t
#include <stddef.h>   // для size_t, wchar_t, ptrdiff_t
#include <stdbool.h>  // для bool
#include <stdio.h>    // для printf и других функций ввода-вывода

#include "task1_3.h"

// Функция для вывода двоичного представления одного значения
void print_binary_val(unsigned long long val, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        putchar((val & (1ULL << i)) ? '1' : '0');
    }
}

// Вспомогательная функция для вывода двоичного формата с ведущими нулями
void print_binary_array(const void *arr, size_t elem_size, int is_signed) {
    unsigned char *bytes = (unsigned char *)arr;
    for (int i = 0; i < N; ++i) {
        unsigned long long val = 0;
        // Скопируем байты элемента в val (учитывая порядок байт)
        for (size_t b = 0; b < elem_size; ++b) {
            val |= ((unsigned long long)bytes[i * elem_size + b]) << (8 * b);
        }
        // Выводим биты с ведущими нулями
        print_binary_val(val, 8 * elem_size);
        putchar(i == N - 1 ? '\n' : ' ');
    }
}