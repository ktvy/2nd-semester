#include <stdio.h>
#include <stdlib.h>
#include "StringFunctions.h"


int main() {
	char* string, substring;
	printf("Enter string: ");
	scanf("%s", &string);
	printf("Enter substing: ");
	scanf("%s", &substring);
	printf("Does this substring exist: ");
	if (SubstringFinder(string,substring)){
		printf("Yes!\n");
	}
	else{
		printf("No!\n");
	}
	printf("Count of substring in a string: ", CountOfOccurences(string,substring));
	return 0;
}