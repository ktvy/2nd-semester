#include "operations.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,j,rows,cols;
    Matrix a,b;
    a.rows = rows;
    a.cols = cols;
    a.data = (double**)malloc(a.rows * sizeof(double*));
    for (i = 0; i < a.rows; i++){
        a.data[i] = (double*)malloc(a.cols * sizeof(double));
    }
    
    printf("Enter count of rows: ");
    scanf("%d", &rows);

    printf("Enter count of colums: ");
    scanf("%d",&cols);

    printf("Enter values for matrix A: ");
    for (i = 0; i < a.rows; i++){
        for (j = 0; j < a.cols; j++){
            scanf("%lf", &a.data[i][j]);
        }
    }
    b.rows = rows;
    b.cols = cols;
    b.data = (double**)malloc(b.rows * sizeof(double*));
    for (i = 0; i < b.rows; i++){
        b.data[i] = (double*)malloc(b.cols * sizeof(double));
    }
     printf("Enter values for matrix A: ");
    for (i = 0; i < b.rows; i++){
        for (j = 0; j < b.cols; j++){
            scanf("%lf", &b.data[i][j]);
        }
    }
    Matrix c = MatrixAddition(a,b);

    for(i = 0; i < c.rows; i++){
        for(j = 0; j < c.cols; j++){
            printf("%.2lf", c.data[i][j]);
        }
        printf("\n");
    }
    return 0;
}