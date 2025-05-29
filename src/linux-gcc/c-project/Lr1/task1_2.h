#ifndef task1_2_H
#define task1_2_H

#include <stdio.h>

#define PRINT_SIZE(type) printf("Размер %s = %zu байт\n", #type, sizeof(type))

void print_os();
void print_cpu_arch();
void print_compiler_version();

void printSizeOfAll();

void run_task1_2()
{
    printf("\nЗадание №2\n");
    printf("=========================================================================\n");
    
    print_os();
    print_cpu_arch();
    print_compiler_version();
    
    printSizeOfAll();
}

void printSystemInfo()
{
    printf("\nSystemInfo\n");
    printf("=========================================================================\n");
    
    print_os();
    print_cpu_arch();
    print_compiler_version();
}

#endif