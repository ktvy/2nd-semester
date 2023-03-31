#ifndef MATRIX_OPERATIONS
#define MATRIX_OPERATIONS

typedef struct {
    int rows;
    int cols;
    double data[2][2];
}Matrix;


Matrix MatrixAddition(Matrix a, Matrix b);

#endif