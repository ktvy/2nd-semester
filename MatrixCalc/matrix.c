#include <stdio.h>
#include <stdlib.h>
#include "MatrixOperations.h"

int main(){
    int i,j;
    Matrix a;
    Matrix b;

    printf("Enter values for matrix A: ");
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            scanf("%lf", &a.data[i][j]);
        }
    }

    printf("Enter values for matrix B: ");
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            scanf("%lf", &b.data[i][j]);
        }
    }

    Matrix c = MatrixAddition(a,b);
    for(int i = 0; i < c.rows; i++){
        for (int j = 0; j < c.cols; j++){
            printf("%lf", c.data[i][j]);
        }
        printf("\n");
    }
    return 0;
}