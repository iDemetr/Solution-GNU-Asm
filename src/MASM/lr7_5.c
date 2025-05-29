#ifndef task7_5_H
#define task7_5_H

//#pragma comment(lib, "m")  // Явное указание линковать с libm

#include <math.h>
#include <stdio.h>
#include <stdint.h>

int main()
{
    printf("\nЗадание №5\n");
    printf("=========================================================================\n");
    
    double x, y;
    printf("Введите x y: ");
    if (scanf("%lf %lf", &x, &y) != 2) {
        printf("Ошибка ввода\n");
        return 1;
    }

    double z = atan2(x, y);
    printf("atan2(%.3f, %.3f) = %e\n", x, y, z);

    printf("=========================================================================\n");
}

#endif