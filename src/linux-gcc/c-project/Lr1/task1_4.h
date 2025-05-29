#ifndef task1_4_H
#define task1_4_H

#include <stdio.h>

#define N 5

// Макрос для вывода массива с параметризацией типа, формата и модификаторов
#define PRINT_ARRAY(arr, type, format_str) \
    do { \
        for (int i = 0; i < N; i++) { \
            printf(format_str "%c", (type)(arr[i]), (i == N-1) ? '\n' : ' '); \
        } \
    } while(0)
    
// Функция вывода целочисленного массива во всех форматах
#define PRINT_INT_ARRAY_ALL(arr, type, signed_type, fmt_hex, fmt_unsigned, fmt_signed, elem_size) do { \
    printf(#arr " in hex (X):\n"); \
    PRINT_ARRAY(arr, type, fmt_hex); \
    printf(#arr " in binary (b):\n"); \
    PRINT_ARRAY(Mb, unsigned char, "%08b"); \
    printf(#arr " unsigned decimal (u):\n"); \
    PRINT_ARRAY(arr, type, fmt_unsigned); \
    printf(#arr " signed decimal with plus (d):\n"); \
    PRINT_ARRAY(arr, signed_type, fmt_signed); \
} while(0)

// Функция вывода массива с плавающей точкой во всех форматах
#define PRINT_FLOAT_ARRAY_ALL(arr, type, fmt_A, fmt_e, fmt_f) do { \
    printf(#arr " in hex exp (A):\n"); \
    PRINT_ARRAY(arr, type, fmt_A); \
    printf(#arr " in decimal exp (e):\n"); \
    PRINT_ARRAY(arr, type, fmt_e); \
    printf(#arr " in decimal fixed (f):\n"); \
    PRINT_ARRAY(arr, type, fmt_f); \
} while(0)

int input_element_int(void *element, const char *fmt);
int input_element_float(void *element, const char *fmt);

void run_task1_4()
{
    printf("\nЗадание №4\n");
    
    // Инициализация массивов
    unsigned char Mb[N] = {0xED, 0xED, 0xED, 0xED, 0xED};
    unsigned short Ms[N] = {0xFADE, 0xFADE, 0xFADE, 0xFADE, 0xFADE};
    unsigned int Ml[N] = {0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA};
    unsigned long long Mq[N] = {0xC1A551F1AB1EULL, 0xC1A551F1AB1EULL, 0xC1A551F1AB1EULL, 0xC1A551F1AB1EULL, 0xC1A551F1AB1EULL};

    // Вариант 17: x = 8/3 для float/double
    float Mfs[N];
    double Mfl[N];
    for (size_t i = 0; i < N; i++) {
        Mfs[i] = 8.0f / 3.0f;
        Mfl[i] = 8.0 / 3.0;
    }
    
    printf("=========================================================================\n");
    
    // --- Mb ---
    PRINT_INT_ARRAY_ALL(Mb, unsigned char, signed char, "%02hhX", "%hhu", "%+hhd", sizeof(Mb[0]));
    printf("Введите новое значение Mb[2] (целое число 0..255): ");
    while (!input_element_int(&Mb[2], "%hhu")) {
        printf("Повторите ввод Mb[2]: ");
    }
    PRINT_INT_ARRAY_ALL(Mb, unsigned char, signed char, "%02hhX", "%hhu", "%+hhd", sizeof(Mb[0]));

    // --- Ms ---
    PRINT_INT_ARRAY_ALL(Ms, unsigned short, short, "%04hX", "%hu", "%+hd", sizeof(Ms[0]));
    printf("Введите новое значение Ms[2] (целое число 0..65535): ");
    while (!input_element_int(&Ms[2], "%hu")) {
        printf("Повторите ввод Ms[2]: ");
    }
    PRINT_INT_ARRAY_ALL(Ms, unsigned short, short, "%04hX", "%hu", "%+hd", sizeof(Ms[0]));

    // --- Ml ---
    PRINT_INT_ARRAY_ALL(Ml, unsigned int, int, "%08X", "%u", "%+d", sizeof(Ml[0]));
    printf("Введите новое значение Ml[2] (целое число 0..4294967295): ");
    while (!input_element_int(&Ml[2], "%u")) {
        printf("Повторите ввод Ml[2]: ");
    }
    PRINT_INT_ARRAY_ALL(Ml, unsigned int, int, "%08X", "%u", "%+d", sizeof(Ml[0]));

    // --- Mq ---
    PRINT_INT_ARRAY_ALL(Mq, unsigned long long, long long, "%016llX", "%llu", "%+lld", sizeof(Mq[0]));
    printf("Введите новое значение Mq[2] (целое число 0..18446744073709551615): ");
    while (!input_element_int(&Mq[2], "%llu")) {
        printf("Повторите ввод Mq[2]: ");
    }
    PRINT_INT_ARRAY_ALL(Mq, unsigned long long, long long, "%016llX", "%llu", "%+lld", sizeof(Mq[0]));

    // --- Mfs ---
    PRINT_FLOAT_ARRAY_ALL(Mfs, float, "%A", "%.2e", "%f");
    printf("Введите новое значение Mfs[2] (число с плавающей точкой): ");
    while (!input_element_float(&Mfs[2], "%f")) {
        printf("Повторите ввод Mfs[2]: ");
    }
    PRINT_FLOAT_ARRAY_ALL(Mfs, float, "%A", "%.2e", "%f");

    // --- Mfl ---
    PRINT_FLOAT_ARRAY_ALL(Mfl, double, "%A", "%.2e", "%f");
    printf("Введите новое значение Mfl[2] (число с плавающей точкой): ");
    while (!input_element_float(&Mfl[2], "%lf")) {
        printf("Повторите ввод Mfl[2]: ");
    }
    PRINT_FLOAT_ARRAY_ALL(Mfl, double, "%A", "%.2e", "%f");

    printf("\n=========================================================================\n");
    
    printf("\n");
}

#endif