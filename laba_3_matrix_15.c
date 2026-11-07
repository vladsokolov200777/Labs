#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    
    // ввод размеров с проверкой на корректность
    printf("Введите количество строк N (минимум 2): ");
    while (scanf("%d", &N) != 1 || N < 2) {
        printf("Ошибка! Введите целое число >= 2: ");
        while (getchar() != '\n');
    }

    printf("Введите количество столбцов M (минимум 3): ");
    while (scanf("%d", &M) != 1 || M < 3) {
        printf("Ошибка! Введите целое число >= 3: ");
        while (getchar() != '\n');
    }

    // выделение памяти под матрицу
    int **A = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        A[i] = (int*)malloc(M * sizeof(int));
    }

    // заполнение матрицы
    printf("Введите элементы матрицы (%d x %d):\n", N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // массив B для средних арифметических по строкам
    float *B = (float*)malloc(N * sizeof(float)); 
    printf("\nЗадача 1. Средние арифметические строк:\n");
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < M; j++) {
            sum += A[i][j];
        }
        B[i] = (float)sum / M; // приводим к float для точного деления
        printf("Строка %d: %.2f\n", i + 1, B[i]);
    }

    // поиск минимума в 3 столбце (индекс 2)
    int min_val = A[0][2];
    int min_row = 0;

    for (int i = 1; i < N; i++) {
        if (A[i][2] < min_val) {
            min_val = A[i][2];
            min_row = i;
        }
    }
    printf("\nМинимальный элемент 3-го столбца: %d (в строке %d)\n", min_val, min_row + 1);

    // меняем минимум и элемент a23 (индексы 1 и 2)
    int temp = A[1][2];
    A[1][2] = A[min_row][2];
    A[min_row][2] = temp;

    printf("\nЗадача 3. Матрица после обмена:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    // очистка памяти
    for (int i = 0; i < N; i++) free(A[i]);
    free(A);
    free(B);

    return 0;
}
