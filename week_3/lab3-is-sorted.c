#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void quicksort(int arr [], int first_term, int last_term) {

    int i, j, pivot, temp;

    if (first_term < last_term) {
        pivot = first_term;

        i = first_term;
        j = last_term;

        while (i < j) {

            while (arr[i] <= arr[pivot] && i < last_term)
            i++;

            while (arr[j] >= arr[pivot])
            j--;

            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        quicksort(arr, first_term, j - 1);
        quicksort(arr, j + 1, last_term);

    }
}


int main(int argc, char *argv[])
{

    int nr_li[argc - 1];

    int j = 0;
    for (int i = 1; i < argc; ++i) {
        nr_li[j] = atoi(argv[i]);
        j++;
    }

    quicksort( nr_li, 0, argc - 2 );

    for (int i = 0; i < argc  - 1; ++i)
    printf("%d\n", nr_li[i]);

    return 0;
}
