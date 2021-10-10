#include <stdio.h>

#define m 3
#define n 3
#define p 3

/*
 * (15 points) An n × m two-dimensional matrix can be multiplied by another m × p matrix to give a
 * matrix whose elements are the sum of the products of the elements within a row from the first
 * matrix and the associated elements of a column of the second matrix.
 * Both matrices should either be square matrices, or the number of columns of the first matrix
 * should equal the number of rows of the second matrix.
 *
 * To calculate each element of the resultant matrix, multiply the first element of a given row
 * from the first matrix and the first element of a given column in the second matrix, add that
 * to the product of the second element of the same row and the second element of the same column,
 * and keep doing so until the last elements of the row and column have been multiplied and added
 * to the sum.
 *
 * Write a C program to calculate the product of 2 matrices and store the result in a third matrix.
 */
int main() {
    int mat1[m][n] = {
            {2, 3, 4},
            {4, 5, 6},
            {7, 8, 9}
    };

    int mat2[n][p] = {
            {4, 5, 6},
            {2, 3, 4},
            {0, 1, 2}
    };

    int result[m][p] = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}