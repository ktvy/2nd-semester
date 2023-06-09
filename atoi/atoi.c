#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

int my_atoi(char* str)
{
 int i = 0;
 while (isspace(str[i])) {
  i++;
 }
 
 if (i < strlen(str) && (('0' <= str[i] && str[i] <= '9') || (str[i] == '-') || (str[i] == '+'))) {
  if (str[i] == '-') {
   i++;
   int result = 0;
   while (i < strlen(str) && ('0' <= str[i] && str[i] <= '9')) {
    int number = str[i] - '0';
    i++;
    if (result > INT_MIN / 10 || (result == INT_MIN / 10 && number <= -(INT_MIN % 10))) {
     result = result * 10 - number;
    }
    else {
     return INT_MIN;
    }
   }
   return result;
  }
  else {
   if (str[i] == '+') {
    i++;
   }
   int result = 0;
   while (i < strlen(str) && ('0' <= str[i] && str[i] <= '9')) {
    int number = str[i] - '0';
    i++;
    if (result < INT_MAX / 10 || (result == INT_MAX / 10 && number <= INT_MAX % 10)) {
     result = result * 10 + number;
    }
    else {
     return INT_MAX;
    }
   }
   return result;
  }
 }
 else {
  return 0;
 }
}

int main(int argc, char** argv)
{
 int i;
 for (i = 1; i < argc; i++) {
  printf("%d ", my_atoi(argv[i]));
 }
 return 0;
}