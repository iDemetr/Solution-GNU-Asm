#include <stdio.h>

#define N 5

void run_task1_6(){
    unsigned int Ml[N] = {0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA, 0xADE1A1DA};
    unsigned int Ml_before[N];

    // Копируем исходный массив
    for (int i = 0; i < N; ++i) {
        Ml_before[i] = Ml[i];
    }

    printf("Массив Ml до ввода:\n");
    for (int i = 0; i < N; ++i) {
        printf("Ml[%d] = %u (0x%X)\n", i, Ml[i], Ml[i]);
    }

    printf("Введите %d новых значений для массива Ml через пробел:\n", N);

    int count = scanf("%u %u %u %u %u", &Ml[0], &Ml[1], &Ml[2], &Ml[3], &Ml[4]);

    if (count == EOF) {
        puts("Ошибка ввода: достигнут конец файла или ошибка.");
        return;
    }

    if (count < N) {
        printf("Введено %d элементов, не введено %d элементов.\n", count, N - count);
    } else {
        puts("Все элементы введены успешно.");
    }

    printf("Массив Ml после ввода:\n");
    for (int i = 0; i < N; ++i) {
        printf("Ml[%d] = %u (0x%X)\n", i, Ml[i], Ml[i]);
    }

    // Подсчёт изменённых элементов
    int changed = 0;
    for (int i = 0; i < N; ++i) {
        if (Ml[i] != Ml_before[i]) {
            changed++;
        }
    }

    printf("Количество изменённых элементов: %d\n", changed);

    if (changed != count) {
        printf("Внимание: количество изменённых элементов (%d) не совпадает с количеством введённых (%d).\n", changed, count);
    }
}
