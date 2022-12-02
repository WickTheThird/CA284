//
// Filip Bumbu, printing a number the same number of times as its frequency if the frequency is larger than 3, 30/11/22
// The way I went about this:
//     -> Firstly I have assigned all the numbers from argv to an array;
//     -> Then I have created a frequency function where
//  I take a number using a for loop and check how many times it repeats with a seccond for loop.
//     -> If the frequency is is larger than 3, then it will pass to adding it to the array (whose size it constantly updated with realloc);
//     -> Then I pas it to a printing function which also sorts it for me using insertion sort;
//
//
// Libs used:
// -> #include <stdio.h>
// -> #include <stdlib.h>
// -> #include <string.h>
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// declarations
void find_frequent(int * pArr, int len);
void print_arr(int * pArr, int len);

// main
int main(int argc, char *argv[])
{
    // assigning all numbers to an array
    int *pArr = (int*)malloc((argc - 1)*sizeof(int));

    int counter = 0;
    for (int i = 1; i < argc; ++i, ++counter) {

        *(pArr + counter) = atoi(argv[i]);
    }

    find_frequent(pArr, counter);

    return 0;
}

// finding the freqency of each number
 void find_frequent(int * pArr, int len) {
    //having an initial size
    int size_freq = 1;
    int *freq_nr = (int*)malloc(size_freq*sizeof(int));
    int *temp_ptr; // temporary array for realloc
    int pos = 0; // position in the new temporaty array

    int counter = 0; // counting instances/freqency
    for (int i = 0; i < len; ++i) {

        counter = 0; // reseting

        for (int j = 0; j < len; ++j) {

            if (*(pArr + i) == *(pArr + j)) { // checking
                ++counter; // counting
            }

        }

        if (counter > 3) { // checking if counter has the right value

            if (pos < 1) { // assigning the first position

                *(freq_nr + pos) = *(pArr + i);
                ++pos;

            } else { // after the first pos was assigned we can assign the rest for safety

                ++size_freq;
                temp_ptr = (int*)realloc(freq_nr, (size_freq)*sizeof(int)); // reallocating one number at a time
                *(temp_ptr + pos) = *(pArr + i);

                freq_nr = temp_ptr; // submitting to the original array
                ++pos; //updating next position

            }

        }

    }

    print_arr(freq_nr, size_freq); // printing the array

 }

 void print_arr(int *arr, int len_arr) {

    // sorting using insertion sort to sort array
    int i, j, min_idx;
    
    for (i = 0; i < len_arr; ++i) {

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

    for (int i = 0; i < len_arr; ++i) { // printing the numbers liniarly
        printf("%d\n", *(arr + i));
    }

 }
