#include <stdio.h>

void oct(int n) {
	if (n > 7) {
		oct(n / 8);
	}
	printf("%d", n % 8);
}

int main() {
	int n;
	printf("Введите натуральное число: ");
	if (scanf("%d", &n) != 1 || n <= 0) {
		printf("Ошибка: нужно ввести натуральное число!\n");
		return 1;
	}
	oct(n);
	printf("\n");
	return 0;
}
