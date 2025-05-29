#include <stdio.h>
#include <stdint.h>

extern int64_t f1(int64_t x, int64_t y);

int64_t f1(int64_t x, int64_t y) {
    int64_t result;
    __asm__ (
        "lea (%1, %2, 8), %0\n\t"  // result = x + 8*y
        "sub $7, %0"
        : "=&r" (result)            // output operand
        : "r" (x), "r" (y)          // input operands
    );
    return result;
}

int main() {
    int64_t x = 5, y = 3;
    printf("f1(%lld, %lld) = %lld\n", x, y, f1(x, y));
    return 0;
}
