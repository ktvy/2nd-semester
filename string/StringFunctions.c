#include <stdio.h>
#include <stdlib.h>
#include "StringFunctions.h"

int strLength(char* str) {
	unsigned counter = 0;
	while (str[counter] != '\0') {
		counter++;
	}
	return counter;
}

int SubstringFinder(char* str, char* substr) {
	for (int i = 0; i < strLength(str); i++) {
		for (int j = i, k = 0; k < strLength(substr) && str[j] == substr[k]; j++, k++) {
			if (k = strLength(substr) - 1) {
				i++;
				return i;
			}
		}
	}
	return 0;
}

int CountOfOccurences(char* str, char* substr) {
	int counter = 0;
	while (SubstringFinder(str, substr)) {
		counter++;
		str += SubstringFinder(str, substr);
	}
	return counter;
}
