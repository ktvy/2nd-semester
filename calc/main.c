#include <stdio.h>
#include <stdlib.h>
#include "Operations.h"

int main(){
    int rows, cols;
    printf("Введите количество строк и столбцов матриц: ");
    scanf("%d %d", &rows, &cols);

    // Создание двух матриц заданного размера
    Matrix matrix1 = createMatrix(rows, cols);
    Matrix matrix2 = createMatrix(rows, cols);

    // Ввод элементов матриц
    inputMatrix(&matrix1);
    inputMatrix(&matrix2);

    // Сложение матриц
    Matrix result = Addition(matrix1, matrix2);

    // Вывод результата
    printMatrix(result);

    // Освобождение памяти, занятой матрицами
    freeMatrix(matrix1);
    freeMatrix(matrix2);
    freeMatrix(result);

    return 0;
}