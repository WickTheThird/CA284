#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// MULTIPLICATION OF MATRICES

void multipy_matrices (int m1, int n1, int matrix1 [], int m2, int n2, int matrix2 []) {

    if (n1 == m2) {

        // MATRIX 1

        int len_matrix1 = m1 * n1;
        int matrix1_ind = 0;

        //MATRIX 2

        int len_matrix2 = m2 * n2;
        int matrix2_ind = 0;

        // SETTING UP A TOTAL

        int total = 0;

        // MAIN OPERATION
        for (int row = 0; row < m1; ++row) {
            for (int col = 0; col < n2; ++col) {
               
                total = 0;

                if (matrix2_ind == n2) {
                    matrix2_ind -= (n2);
                }

                if (matrix1_ind == (n1 * (row + 1))) {
                    matrix1_ind -= (n1);
                }

                for (int j = 0; j < n1; ++j) {
                    if (j == 0) {
                        total += (matrix1[matrix1_ind] * matrix2[matrix2_ind]);
                    } else {
                        total += (matrix1[matrix1_ind] * matrix2[matrix2_ind + n2 * j]);
                    }

                    ++matrix1_ind;
                }

                if (col == n2 - 1) {
                    printf("%d", total);
                } else {
                    printf("%d ", total);
                }
            
                ++matrix2_ind;

            }
            printf("\n");
        }

    } else {
        printf ("Not a valid multiplication matrix\n");
    }

}


int main(int argc, char *argv[])
{

    int m1 = atoi(argv[1]);
    int n1 = atoi(argv[2]);
    int len_matrix1 = m1 * n1;
    int matrix1[len_matrix1];

    int counter = 0;
    for (int i = 3; counter < len_matrix1; ++i) {
        matrix1[counter] = atoi(argv[i]);
        ++counter;
    }

    int m2 = atoi(argv[(m1 * n1) + 3]);
    int n2 = atoi(argv[(m1 * n1) + 4]);
    int len_matrix2 = m2 * n2;
    int matrix2[len_matrix2];

    int counter2 = 0;
    for (int j = (m1 * n1) + 5; counter2 < len_matrix2; ++j) {
        matrix2[counter2] = atoi(argv[j]);
        ++counter2;
    }

    multipy_matrices(m1, n1, matrix1, m2, n2, matrix2);

    return 0;
}
