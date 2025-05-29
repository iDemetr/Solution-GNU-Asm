#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <wchar.h>

#define PRINT_SIZE(type) printf("Размер %s = %zu байт\n", #type, sizeof(type))

void print_os();
void print_cpu_arch();
void print_compiler_version();

void printSizeOfAll();

int main() {
    printf("\nЗадание №2\n");
    printf("============================================\n");
    
    print_os();
    print_cpu_arch();
    print_compiler_version();
    
    printSizeOfAll();
    return 5 * 5;
}

void printSizeOfAll(){
    
    printf("\nИнформация о размерах стандартных типов:\n");

    PRINT_SIZE(char);
    PRINT_SIZE(char*);
    PRINT_SIZE(bool);
    PRINT_SIZE(wchar_t);
    PRINT_SIZE(short);
    PRINT_SIZE(unsigned short);
    PRINT_SIZE(int);
    PRINT_SIZE(long);
    PRINT_SIZE(long long);
    PRINT_SIZE(float);
    PRINT_SIZE(double);
    PRINT_SIZE(double*);
    PRINT_SIZE(long double);
    PRINT_SIZE(size_t);
    PRINT_SIZE(ptrdiff_t);
    PRINT_SIZE(void*);
}

void print_cpu_arch() {
#if defined(__x86_64__) || defined(_M_X64)
    printf("Архитектура процессора: x86_64 (64-бит)\n");
#elif defined(__i386) || defined(_M_IX86)
    printf("Архитектура процессора: x86 (32-бит)\n");
#elif defined(__arm__) || defined(_M_ARM)
    printf("Архитектура процессора: ARM\n");
#elif defined(__aarch64__)
    printf("Архитектура процессора: ARM64\n");
#elif defined(__mips__)
    printf("Архитектура процессора: MIPS\n");
#else
    printf("Архитектура процессора: неизвестна\n");
#endif
}

void print_compiler_version() {
#if defined(__clang__)
    printf("Compiler: Clang/LLVM\n");
    printf("Version: %d.%d.%d\n", __clang_major__, __clang_minor__, __clang_patchlevel__);
#elif defined(__GNUC__)
    printf("Compiler: GCC\n");
    printf("Version: %d.%d.%d\n", __GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
#elif defined(_MSC_VER)
    printf("Compiler: Microsoft Visual C++\n");
    printf("Version: %d\n", _MSC_VER);
#else
    printf("Unknown compiler\n");
#endif
}

void print_os() {
#if defined(_WIN32) || defined(_WIN64)
    printf("ОС: Windows\n");
#elif defined(__linux__)
    printf("ОС: Linux\n");
#elif defined(__APPLE__) && defined(__MACH__)
    printf("ОС: macOS\n");
#else
    printf("ОС: Неизвестная\n");
#endif
}