#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>

#include "task2_3.h"

void printDump(void *p, size_t N) {
    unsigned char *p1 = (unsigned char *)p;
    for (size_t i = 0; i < N; i++) {
        printf("%02hhX", p1[i]);
        if (i + 1 < N) printf(" ");
    }
    printf("\n");
}