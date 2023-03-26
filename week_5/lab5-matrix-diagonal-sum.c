#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calc_matrix_diagonal(int dim, int arr [], int len_arr) {

    int total = 0;

    int j = 0;
    for (int i = 0; i < dim; ++i) {

       if (j < 0) {
           j += (dim + 1);
           total += arr[j];
       } else {
           total += arr[j];
           j += (dim + 1);
       }

    }

    return total;

}

int main(int argc, char *argv[])
{

    int dim = atoi(argv[1]);
    int matrix [argc - 2];
    
    int j = 0;
    for (int i = 2; i < argc; ++i) {
        matrix[j] = atoi(argv[i]);
        ++j;
    }

    printf("%d\n", calc_matrix_diagonal(dim, matrix, j));

    return 0;
}
