#include <stdio.h>
#include <stdlib.h>
#include "StringFunctions.h"


int main() {
	char string[100];
	char substring[100];
	printf("Enter string: ");
	scanf("%s", string);
	printf("Enter substing: ");
	scanf("%s", substring);
	printf("Does this substring exist: ");
	if (SubstringFinder(string,substring) >= 0){
		printf("Yes!\n");
	}
	else{
		printf("No!\n");
	}
	printf("%d", strLength("Hello"));
	printf("Count of substring in a string: %d\n", CountOfOccurences(string,substring));
	return 0;
}