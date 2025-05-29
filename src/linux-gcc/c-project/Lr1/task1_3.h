#ifndef task1_3_H
#define task1_3_H

#include <stdio.h>

#define N 5

// Макрос для вывода массива с параметризацией типа, формата и модификаторов
#define PRINT_ARRAY(arr, type, format_str) \
do { \
    for (int i = 0; i < N; i++) { \
        printf(format_str "%c", (type)(arr[i]), (i == N-1) ? '\n' : ' '); \
    } \
} while(0)


void print_binary_array(const void *arr, size_t elem_size, int is_signed);

void run_task1_3()
{
    printf("\nЗадание №3\n");
    
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
    
    // 1. Целочисленные массивы: вывод 4 раза (X, b, u, d)
    // Форматы с ведущими нулями для X:
    // Mb: 2*1=2, Ms:4, Ml:8, Mq:16
    // 1) Шестнадцатеричный формат с ведущими нулями (0xED → "ED")
    printf("Массив Mb в шестнадцатеричном формате (%%02hhX):\n");
    PRINT_ARRAY(Mb, unsigned char, "%02hhX");
    // 2) Двоичный формат с ведущими нулями
    printf("Массив Mb в двоичном формате (%%08b):\n");
    PRINT_ARRAY(Mb, unsigned char, "%08b");  //print_binary_array(Mb, sizeof(Mb[0]), 0);
    // 3) Десятичный беззнаковый формат
    printf("Массив Mb в десятичном беззнаковом формате (%%hhu):\n");
    PRINT_ARRAY(Mb, unsigned char, "%hhu");
    // 4) Десятичный знаковый формат с плюсом для положительных
    printf("Массив Mb в десятичном знаковом формате (%%+hhd):\n");
    PRINT_ARRAY(Mb, signed char, "%+hhd");

    printf("=========================================================================\n");
    
    // 1) Шестнадцатеричный формат с ведущими нулями (0xED → "ED")
    printf("Массив Ms в шестнадцатеричном формате (%%04hX):\n");
    PRINT_ARRAY(Ms, unsigned short, "%04hX");
    // 2) Двоичный формат с ведущими нулями
    printf("Массив Ms в двоичном формате (%%08b):\n");
    PRINT_ARRAY(Mb, unsigned short, "%08b"); //print_binary_array(Ms, sizeof(Ms[0]), 0);
    // 3) Десятичный беззнаковый формат
    printf("Массив Ms в десятичном беззнаковом формате (%%hu):\n");
    PRINT_ARRAY(Ms, unsigned short, "%hu");
    // 4) Десятичный знаковый формат с плюсом для положительных
    printf("Массив Ms в десятичном знаковом формате (%%+hd):\n");
    PRINT_ARRAY(Ms, short, "%+hd");

    printf("=========================================================================\n");
    
    // 1) Шестнадцатеричный формат с ведущими нулями (0xED → "ED")
    printf("Массив Ml в шестнадцатеричном формате (%%08X):\n");
    PRINT_ARRAY(Ml, unsigned int, "%08X");
    // 2) Двоичный формат с ведущими нулями
    printf("Массив Ml в двоичном формате (%%08b):\n");
    print_binary_array(Ml, sizeof(Ml[0]), 0);
    // 3) Десятичный беззнаковый формат
    printf("Массив Ml в десятичном беззнаковом формате (%%u):\n");
    PRINT_ARRAY(Ml, unsigned int, "%u");
    // 4) Десятичный знаковый формат с плюсом для положительных
    printf("Массив Ml в десятичном знаковом формате (%%+d):\n");
    PRINT_ARRAY(Ml, int, "%+d");

    printf("=========================================================================\n");
    
    // 1) Шестнадцатеричный формат с ведущими нулями (0xED → "ED")
    printf("Массив Mq в шестнадцатеричном формате (%%016llX):\n");
    PRINT_ARRAY(Mq, unsigned long long, "%016llX");
    // 2) Двоичный формат с ведущими нулями
    printf("Массив Mq в двоичном формате (самописная ф-я):\n");
    print_binary_array(Mq, sizeof(Mq[0]), 0);
    // 3) Десятичный беззнаковый формат
    printf("Массив Mq в десятичном беззнаковом формате (%%llu):\n");
    PRINT_ARRAY(Mq, unsigned long long, "%llu");
    // 4) Десятичный знаковый формат с плюсом для положительных
    printf("Массив Mq в десятичном знаковом формате (%%+lld):\n");
    PRINT_ARRAY(Mq, long long, "%+lld");

    printf("=========================================================================\n");

    // 2. Плавающая точка: 3 раза (A, e, f)
    printf("Массив Mfs в шестнадцатеричном экспоненциальном формате (%%A):\n");
    PRINT_ARRAY(Mfs, float, "%A");
    printf("Массив Mfs в десятичном экспоненциальном формате (%%.2e):\n");
    PRINT_ARRAY(Mfs, float, "%.2e");
    printf("Массив Mfs в десятичном формате с запятой (%%.2f):\n");
    PRINT_ARRAY(Mfs, float, "%f");

    printf("=========================================================================\n");
    
    printf("Массив Mfl в шестнадцатеричном экспоненциальном формате (%%A):\n");
    PRINT_ARRAY(Mfl, double, "%A");
    printf("Массив Mfl в десятичном экспоненциальном формате (%%.2e):\n");
    PRINT_ARRAY(Mfl, double, "%.2e");
    printf("Массив Mfl в десятичном формате с запятой (%%.2f):\n");
    PRINT_ARRAY(Mfl, double, "%f");

    printf("=========================================================================\n");
    
    // 5-й раз Mb в символьном формате (без модификатора)
    printf("\nMb in char format (%%c):\n");
    PRINT_ARRAY(Mb, unsigned char, "%c");

    printf("\n=========================================================================\n");
    
    // Демонстрация ширины поля вывода
    printf("\nMb in hex with width 6 (%%06hhX):\n");
    PRINT_ARRAY(Mb, unsigned char, "%06hhX"); // ширина больше w0=2, добавятся нули слева

    printf("\nMb in hex with width 1 (%%01hhX):\n");
    PRINT_ARRAY(Mb, unsigned char, "%01hhX"); // ширина меньше w0=2, выводится без усечения

    printf("\nMb in hex with width 6 и минусом (%%-6hhX):\n");
    PRINT_ARRAY(Mb, unsigned char, "%-6hhX"); // выравнивание по левому краю, справа пробелы

    printf("\n=========================================================================\n");
    
    printf("\n");
}

#endif