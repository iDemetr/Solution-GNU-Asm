#ifndef task2_3_H
#define task2_3_H

void printDump(void *p, size_t N);
void printSystemInfo();

void run_task2_3()
{
    printf("\nЗадание №3\n");
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

    printf("\n=========================================================================\n");
}

#endif