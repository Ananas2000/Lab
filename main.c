#include <stdint.h>
#include <stdio.h>
#include "libs/data_structures/bitset/bitset.h"
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"
#include "libs/data_structures/matrix/matrix.h"
#include "libs/data_structures/string/string_.h"
#include "libs/data_structures/file/file_.h"
#include <windows.h>
#include <locale.h>
#include <assert.h>

int** task_1(int n, int query[][4], size_t size) {
    matrix result = getMemMatrix(n, n);

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            result.values[i][j] = 0;
        }
    }

    for (size_t i = 0; i < size; i++) {
        for (size_t row = query[i][0]; row <= query[i][2] && row < n; row++) {
            for (size_t col = query[i][1]; col <= query[i][3] && col < n; col++) {
                result.values[row][col]++;
            }
        }
    }

    return result.values;
}

void test_task_1() {
    int query[2][4] = {{1, 1, 2, 2}, {0, 0, 1, 1}};
    int n = 3;
    int **result = task_1(n, query, 2);
    int true_data[3][3] = {{1, 1, 0}, {1, 2, 1}, {0, 1, 1}};

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            assert(true_data[i][j] == result[i][j]);
        }
    }

    int query_2[1][4] = {{0, 0, 5, 5}};
    int n_2 = 3;
    int **result_2 = task_1(n_2, query_2, 1);
    int true_data_2[3][3] = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

    for (size_t i = 0; i < n_2; i++) {
        for (size_t j = 0; j < n_2; j++) {
            assert(true_data_2[i][j] == result_2[i][j]);
        }
    }
}








int main() {
    test_task_1();
    
    return 0;
}