#include "MatrixOperations.h"
#include <stdio.h>

void MatrixSum(a,b){
    int c[2][2];
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf_s("\n");
    return c;
}