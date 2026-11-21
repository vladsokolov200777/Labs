#include <stdio.h>
#include <stdlib.h>

int is_natural_string(const char *str) {
    if (str[0] == '\0' || str[0] == '0' || str[0] == '-') {
 return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}

int is_float_string(const char *str) {
    int start = 0;
    if (str[0] == '-' || str[0] == '+') {
     start += 1;
    }
    
    if (str[start] == '\0') {
 return 0;
    }
    
    int dot_count = 0;
    int digit_count = 0;
    
    for (int i = start; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            dot_count++;
            if (dot_count > 1) {
                return 0;
            }
        } 
        else if (str[i] >= '0' && str[i] <= '9') {
            digit_count++;
        } 
        else {
            return 0;
        }
    }

    if (digit_count == 0) {
        return 0;
    }

    return 1;
}

int main() {
    char *N_str = NULL;
    char *M_str = NULL;
    int M, N;

    while (1) {
        printf("Введите N (минимум 2): ");
        if (scanf("%ms", &N_str) != 1) {
            printf("Ошибка чтения.\n");
            free(N_str);
            continue;
        }
        if (is_natural_string(N_str)) {
            N = atoi(N_str);
            free(N_str);
            if (N >= 2) break;
            else printf("Для 15 варианта N должно быть >= 2!\n");
        } else {
            free(N_str); 
            printf("Число должно быть натуральным!\n");
        }
    }

    while (1) {
        printf("Введите M (минимум 3): ");
        if (scanf("%ms", &M_str) != 1) {
            printf("Ошибка чтения.\n");
            free(M_str); 
            continue;
        }
        if (is_natural_string(M_str)) {
            M = atoi(M_str);
            free(M_str);
            if (M >= 3) break;
            else printf("Для 15 варианта M должно быть >= 3!\n");
        } else {
            printf("Число должно быть натуральным!\n");
            free(M_str); 
        }
    }
    
    float *Matrix = (float*)malloc(N * M * sizeof(float));
    
    printf("\nВведите элементы матрицы:\n");
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         char *element = NULL;
         float value;
         
         while (1) {
          printf("Элемент [%i][%i]: ", i, j);
          if (scanf("%ms", &element) != 1) {
                  printf("Ошибка чтения.\n");
                  free(element);
           continue;
          }
          if (is_float_string(element)) {
               value = atof(element);
           free(element);
           break;
          } else {
           free(element); 
           printf("Некорректный ввод! Введите число.\n");
          }
     }
        Matrix[i * M + j] = value;
    }
    }
   
    printf("\n--- Задача 1 ---\n");
    float *B = (float*)malloc(N * sizeof(float));
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < M; j++) {
            sum += Matrix[i * M + j];
        }
        B[i] = sum / M;
        printf("Строка %d: %.2f\n", i + 1, B[i]);
    }

    printf("\n--- Задача 2 ---\n");
    float min_val = Matrix[0 * M + 2];
    int min_row = 0;
    for (int i = 1; i < N; i++) {
        if (Matrix[i * M + 2] < min_val) {
            min_val = Matrix[i * M + 2];
            min_row = i;
        }
    }
    printf("Минимум в 3-м столбце: %.2f (в строке %d)\n", min_val, min_row + 1);

    printf("\n--- Задача 3 ---\n");
    int a23_index = 1 * M + 2;
    int min_index = min_row * M + 2;

    float temp = Matrix[a23_index];
    Matrix[a23_index] = Matrix[min_index];
    Matrix[min_index] = temp;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("| %.1f ", Matrix[i * M + j]);
        }
        printf("|\n");
    }

    free(Matrix);
    free(B);

    return 0;
}

