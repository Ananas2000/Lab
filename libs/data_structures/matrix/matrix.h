#ifndef UNTITLED_MATRIX_H
#define UNTITLED_MATRIX_H
#include <stdbool.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

int getSum(int *a, int n);

void freeMemMatrix(matrix *m);

void freeMemMatrices(matrix *ms, int nMatrices);

void inputMatrix(matrix *m);

void inputMatrices(matrix *ms, int nMatrices);

void outputMatrix(matrix m);

void outputMatrices(matrix *ms, int nMatrices);

void swapRows(matrix m, int i1, int i2);

void swapColumns(matrix m, int j1, int j2);

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int*, int));

void selectionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int*, int));

bool isSquareMatrix(matrix *m);

bool areTwoMatricesEqual(matrix *m1, matrix *m2);

bool isEMatrix(matrix *m);

bool isSymmetricMatrix(matrix *m);

void transposeSquareMatrix(matrix *m);

void transposeMatrix(matrix *m);

position getMinValuePos(matrix m);

position getMaxValuePos(matrix m);

matrix createMatrixFromArray(const int *a, int nRows, int nCols);

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols);

void test_swap_rows();

void test_swap_columns();

void test_is_square_matrix_true();

void test_is_square_matrix_false();

void test_is_ematrix_true();

void test_is_ematrix_false();

void test_is_symmetric_matrix_true();

void test_is_symmetric_matrix_false();

void test_transpose_square_matrix();

void test_transpose_matrix();

void test_get_min_value_pos();

void test_get_max_value_pos();

void tests();

void swapRowsWithMinAndMaxEls(matrix *m);

int getMax(int *a, int n);

void sortRowsByMinElement(matrix *m);

int getMin(int *a, int n);

void sortColsByMinElement(matrix m);

matrix mulMatrices(matrix m1, matrix m2);

void getSquareOfMatrixIfSymmetric(matrix *m);

bool isUnique(int *a, int n);

void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

bool isMutuallyInverseMatrices(matrix m1, matrix m2);

void test_SwapRowsWithMinAndMaxEls1();

void test_SwapRowsWithMinAndMaxEls2();

void test_sortRowsByMinElement_1();

void test_sortRowsByMinElement_2();

void test_sortColsByMinElement_1();

void test_sortColsByMinElement_2();

void test_getSquareOfMatrixIfSymmetric_1();

void test_getSquareOfMatrixIfSymmetric_2();

void test_getSquareOfMatrixIfSymmetric_3();

void test_transposeIfMatrixHasNotEqualSumOfRows_1();

void test_transposeIfMatrixHasNotEqualSumOfRows_2();

void test_transposeIfMatrixHasNotEqualSumOfRows_3();

void test_transposeIfMatrixHasNotEqualSumOfRows_4();

void test_isMutuallyInverseMatrices_1();

void test_isMutuallyInverseMatrices_2();

void test_isMutuallyInverseMatrices_3();

int max(int a, int b);

long long findSumOfMaxesOfPseudoDiagonal(matrix m);

void test_findSumOfMaxesOfPseudoDiagonal();

int getMinInArea(matrix m);

void test_getMinInArea_1();

void test_getMinInArea_2();

void test_getMinInArea_3();

float getDistance(int *a, int n);

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(int *, int));

void sortByDistances(matrix m);

void test_sortByDistances();

#endif