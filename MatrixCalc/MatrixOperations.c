#include "MatrixOperations.h"
#include <stdio.h>

Matrix MatrixAddition(Matrix a, Matrix b){
    Matrix c;
    c.rows = a.rows;
    c.cols = a.cols;

    for(int i = 0; i < a.rows; i++){
        for (int j = 0; j < b.rows; j++){
            c.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return c;
}

