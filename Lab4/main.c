#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"

int main() {
    int sizes[] = {10, 1000, 10000, 100000};
    int count = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));

    printf("%-12s %-15s %-15s %-15s\n",
           "Размер", "Пузырьком", "Вставками", "Слиянием");

    for (int i = 0; i < count; i++) {
        int n = sizes[i];

        int *original = malloc(n * sizeof(int));
        int *bubble = malloc(n * sizeof(int));
        int *insertion = malloc(n * sizeof(int));
        int *merge = malloc(n * sizeof(int));
        int *temp = malloc(n * sizeof(int));

        if (!original || !bubble || !insertion || !merge || !temp) {
            printf("Ошибка выделения памяти\n");
            free(original);
            free(bubble);
            free(insertion);
            free(merge);
            free(temp);
            return 1;
        }

        for (int j = 0; j < n; j++) {
            original[j] = rand();
            bubble[j] = original[j];
            insertion[j] = original[j];
            merge[j] = original[j];
        }

        clock_t start = clock();
        bubble_sort(bubble, n);
        clock_t end = clock();
        double bubble_time = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        insertion_sort(insertion, n);
        end = clock();
        double insertion_time = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        merge_sort(merge, temp, 0, n - 1);
        end = clock();
        double merge_time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%-12d %-15.6f %-15.6f %-15.6f\n",
               n, bubble_time, insertion_time, merge_time);

        free(original);
        free(bubble);
        free(insertion);
        free(merge);
        free(temp);
    }

    return 0;
}
