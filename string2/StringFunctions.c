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
	for (int i = 0; i < strLength(str) - strLength(substr) + 1; i++) {
			int count = 0;
			for (int j = 0; j < strLength(substr); j++){
				if (substr[j] == str[i + j]){
					count++;
				}
			}
			if (strLength(substr) == count){
				return i;
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
