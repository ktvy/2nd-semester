#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_atoi(char* string) {
	int i = 0;
	while (i < strlen(string) && string[i] == ' ') {
		i++;
	}
	if (i < strlen(string) && string[i] == '-') {
		i++;
		int n = 0;
		while (i < strlen(string) && '0' <= string[i] && string[i] <= '9') {
			int d = string[i] - '0';
			i++;
			if (n > INT_MIN || (n == INT_MIN && d <= -(INT_MIN))) {
				n = n * 10 - d;
			}
			else {
				return INT_MIN;
			}
		}
		return n;
	}
	else {
		if (i < strlen(string) && string[i] == '+') {
			i++;
		}
		int n = 0;
		while (i < strlen(string) && '0' <= string[i] && string[i] <= '9') {//пока символ в пределах строки и от 0 до 9
			int d = string[i] - '0';//получаем цифру за вычетом кода нуля
			i++;
			if (n < INT_MAX || (n == INT_MAX && d <= INT_MAX)) {
				n = n * 10 + d; //умножаем на 10 и получаем следующую цифру
			}
			else {
				return INT_MAX;
			}
		}
		return n;
	}
}

int main(int argc, char * argv[]) {
	int i = 0;
	for (i = 1; i < argc; i++) {
		printf_s("%d\n",my_atoi(argv[i]));
	}
}