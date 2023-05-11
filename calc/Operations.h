#ifndef OPERATIONS
#define OPERATIONS

typedef struct {
    int rows;
    int cols;
    double **data;
}Matrix;

Matrix Addition(Matrix matrix1, Matrix matrix2);
Matrix createMatrix(int rows, int cols);
void freeMatrix(Matrix matrix);
void inputMatrix(Matrix *matrix);
void printMatrix(Matrix matrix);

#endif