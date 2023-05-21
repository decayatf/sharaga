#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "sub.h"

int main() {
    int n;
    printf("введите размер матрыцы: ");
    scanf("%d", &n);

    double** matrix1 = (double**)malloc(n * sizeof(double*));
    double** matrix2 = (double**)malloc(n * sizeof(double*));
    double** result;
    
    for (int i = 0; i < n; i++) {
        // выделяем место в матрицах
        matrix1[i] = (double*)malloc(n * sizeof(double));
        matrix2[i] = (double*)malloc(n * sizeof(double));

        for (int j = 0; j < n; j++) {
            printf("ввод для строки %d и столбца %d\n", i+1, j+1);
            printf("для матрицы 1: ");
            scanf("%lf", &matrix1[i][j]);

            printf("для матрицы 2: ");
            scanf("%lf", &matrix2[i][j]);
        }
    }

    char oper;
    printf("введите операцию: ");
    scanf(" %c", &oper);

    switch (oper)
    {
    case '+':
        result = matrixSum(matrix1, matrix2, n); 
        break;
    case '-':
        result = matrixDif(matrix1, matrix2, n); 
        break;
    case '*':
        result = matrixPow(matrix1, matrix2, n); 
        break;
    default:
        printf("операция не найдена");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f\t", result[i][j]);
        }
        printf("\n");
    }
    scanf(" %c");
    return 0;
}