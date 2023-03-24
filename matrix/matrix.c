#include <stdio.h>
#include "MatrixOperations.c"

int main(){
    int a[2][2], b[2][2], c[2][2]
    int i,j;

    printf_s("Enter values for matrix A: ");
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            scanf_s("%d", &a[i][j]);
        }
    }

    printf_s("Enter values for matrix B: ");
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            scanf_s("%d", &b[i][j]);
        }
    }

    printf_s(MatrixSum(a,b));
}