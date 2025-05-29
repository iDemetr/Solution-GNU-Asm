#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

void print_os();
void print_cpu_arch();
void print_compiler_version();
void printSystemInfo();

void printDump(void *p, size_t N) {
    unsigned char *p1 = (unsigned char *)p;
    for (size_t i = 0; i < N; i++) {
        printf("%02hhX", p1[i]);
        if (i + 1 < N) printf(" ");
    }
    printf("\n");
}

int main() {
    // Установка локали для корректного вывода wchar_t
    setlocale(LC_ALL, "");

    printf("\nЗадание №2\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");

    // а) int x
    int x = 0x12345678;
    printf("int x = 0x12345678, хранение в памяти (байты):\n");
    printDump(&x, sizeof(x));
    // Если младший байт в начале (0x78), значит Little-Endian

    // б) double x
    double d = 12345.6789;
    printf("double d = %g, хранение в памяти (байты):\n", d);
    printDump(&d, sizeof(d));

    // в) строки "abcdef" и "абвгде"
    char str1[] = "abcdef";
    char str2[] = "абвгде";  // зависит от кодировки исходного файла и консоли
    printf("Строка \"abcdef\" (включая завершающий нуль):\n");
    printDump(str1, sizeof(str1));  // sizeof включает '\0'
    printf("Строка \"абвгде\" (включая завершающий нуль):\n");
    printDump(str2, sizeof(str2));

    // г) широкие строки L"abcdef" и L"абвгде"
    wchar_t wstr1[] = L"abcdef";
    wchar_t wstr2[] = L"абвгде";
    printf("Широкая строка L\"abcdef\" (включая завершающий нуль):\n");
    printDump(wstr1, sizeof(wstr1));
    printf("Широкая строка L\"абвгде\" (включая завершающий нуль):\n");
    printDump(wstr2, sizeof(wstr2));

    return 0;
}

void printSystemInfo()
{
    printf("\nSystemInfo\n");
    printf("=========================================================================\n");
    
    print_os();
    print_cpu_arch();
    print_compiler_version();
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