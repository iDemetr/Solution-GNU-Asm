#ifndef task6_4_H
#define task6_4_H

#include <stdio.h>
#include <stdint.h>

void print16(void *p);
void print32(void *p);
void print64(void *p);

void printSystemInfo();

void unsigned_div_mod(uint32_t x, uint32_t y, uint32_t *z, uint32_t *w);
void signed_div_mod(int32_t x, int32_t y, int32_t *z, int32_t *w);

void run_task6_4()
{
    printf("\nЗадание №4\n");
    printf("=========================================================================");
    printSystemInfo();
    printf("=========================================================================\n");
    
    int32_t x = -3;
    int32_t y = 2;

    uint32_t uz, uw;
    int32_t sz, sw;

    unsigned_div_mod((uint32_t)x, (uint32_t)y, &uz, &uw);
    signed_div_mod(x, y, &sz, &sw);

    printf("x= %d, y= %d\n", x, y);
    printf("Unsigned division: z = %u, w = %u\n", uz, uw);
    printf("Signed division: z = %d, w = %d\n", sz, sw);
    
    printf("=========================================================================\n");
}

// Беззнаковое деление и остаток
void unsigned_div_mod(uint32_t x, uint32_t y, uint32_t *z, uint32_t *w) {
    uint32_t num = x + 2;

    __asm__ (
        "divl %4"
        : "=a" (*z), "=d" (*w)
        : "a" (num), "d" (0), "r" (y)
    );
}

// Знаковое деление и остаток
void signed_div_mod(int32_t x, int32_t y, int32_t *z, int32_t *w) {
    int32_t num = x + 2;

    __asm__ (
        "cltd\n\t"          // Расширить eax в edx:eax (знаковое расширение)
        "idivl %4"
        : "=a" (*z), "=d" (*w)
        : "a" (num), "d" (0), "r" (y)
    );
}

#endif