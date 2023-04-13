#ifndef OPERATIONS
#define OPERATIONS

typedef struct {
    int rows;
    int cols;
    double **data;
}Matrix;

Matrix MatrixAddition(Matrix a, Matrix b);

#endif