#include "operations.h"
#include <stdio.h>

Matrix MatrixAddition(Matrix a, Matrix b){
    Matrix c;
    c.rows = a.rows;
    c.cols = b.cols;
    c.data = (double**)malloc(c.rows * sizeof(double*));
    for (int i = 0; i < c.rows; i++){
        for (int j = 0; j < c.cols; j++){
            c.data[i] = (double*)malloc(c.cols * sizeof(double));
            for (int j = 0; j < c.cols; j++){
                c.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }
    }
    return c;
}