#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Filip Bumbu, printing middle items of a sorted array, 03/11/22
// The way I went about this:
//     -> I have added all the numbers into an array (and also convert them to ints).
//     -> With this I would have control over any oerations (if needed) and would have
// have the length of the array ready for use.
//     -> After that I have used an external function called sort to first sort
// (using insertion sort) and then pass a reference of the array to the find_mid function
// which then loops through the half the lenght of the array and prints the element at that
// position together with the element at that position - 1.
//
// Libs used:
// -> #include <stdio.h>
// -> #include <stdlib.h>
// -> #include <string.h>
//

// declarations
int * sort(int arr[], int len_arr);
void find_mid(int arr[], int len_arr);

// the main
int main(int argc, char *argv[])
{       // putting elements in a new array
        int arr[argc - 1];

        int counter = 0; 
        char *p;

        for (int i = 1; i < argc; ++i, ++counter) {
           *(arr + counter) = atoi(*(argv + i));
        }
        // finding and printing the mids
        find_mid(sort(arr, counter), counter);

        return 0;
}

// sorting
int * sort(int arr[], int len_arr) {

    // sorting using insertion sort
    int i, j, min_idx;
    
    for (i = 0; i < len_arr - 1; ++i) {

        min_idx = i;
        for (j = i + 1; j < len_arr; ++j) {
              if (*(arr + j) < *(arr + min_idx))
                min_idx = j;
        }

        if(min_idx != i) {
            // swapping
            int temp = *(arr + min_idx);
            *(arr + min_idx) = *(arr + i);
            *(arr + i) = temp;
            
        }
    }

    return arr;
}

// find the mids
void find_mid(int arr[], int len_arr) {

    int mid = len_arr / 2;
    
    for (int i = 0; i < len_arr; ++i) {

        if (i == mid || i == mid - 1) {
            printf("%d\n", *(arr + i));
        }
    }
}
