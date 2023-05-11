#include "Operations.h"
#include <stdio.h>
#include <stdlib.h>

Matrix createMatrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    matrix.data = (double **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix.data[i] = (double *) malloc(cols * sizeof(int));
    }
    return matrix;
}

void freeMatrix(Matrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        free(matrix.data[i]);
    }
    free(matrix.data);
}

void inputMatrix(Matrix *matrix) {
    printf("Введите элементы матрицы: ");
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            scanf("%le", &matrix->data[i][j]);
        }
    }
}

void printMatrix(Matrix matrix) {
    printf("Полученная матрица: ");
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            printf("%f ", matrix.data[i][j]);
        }
        printf("\n");
    }
}

Matrix Addition(Matrix matrix1, Matrix matrix2) {
    if (matrix1.rows != matrix2.rows || matrix1.cols != matrix2.cols) {
        printf("Ошибка: размеры матриц не совпадают\n");
        exit(1);
    }
    Matrix result = createMatrix(matrix1.rows, matrix1.cols);
    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix1.cols; j++) {
            result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }
    return result;
}