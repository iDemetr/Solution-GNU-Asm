#ifndef task2_2_H
#define task2_2_H

void viewPointer(void *p);
void printPointer(void *p);

void run_task2_2()
{
    printf("\nЗадание №2\n");
    printf("=========================================================================\n");
    
    // Тест 1: long long 0x1122334455667788
    long long ll = 0x1122334455667788LL;
    printf("=== Тест 1: long long 0x1122334455667788 ===\n");
    viewPointer(&ll);
    printPointer(&ll);

    printf("\n");

    // Тест 2: строка "0123456789abcdef"
    char str[] = "0123456789abcdef";
    printf("=== Тест 2: строка \"0123456789abcdef\" ===\n");
    viewPointer(str);
    printPointer(str);

    printf("\n=========================================================================\n");
}

#endif