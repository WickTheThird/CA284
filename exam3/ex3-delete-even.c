//
// Filip Bumbu, creating an array composed only of odd numbers, 30/11/22
// The way I went about this:
//     -> I have created an array composed only of numbers from stdin;
//     -> Then I have a function that returns how many odd numbers there are;
//     -> After that, I have reallocated the the memory of the array with the odd numbers;
//
// Libs used:
// -> #include <stdio.h>
// -> #include <stdlib.h>
// -> #include <string.h>
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//declarations
int find_odds(int * pArr, int len);
void print_arr(int * pArr, int len);

//main
int main(int argc, char *argv[])
{
    // main array
    int *pArr = (int*)malloc((argc - 1)*sizeof(int));

    // temporary array
    int *tmp_arr;

    // the nr of odds
    int new_len;

    // assigning the numbers stdin to an array
    int counter = 0;
    for (int i = 1; i < argc; ++i, ++counter) {
        *(pArr + counter) = atoi(argv[i]);
    }

    //assigning the nr of odds into a variable
    new_len = find_odds(pArr, argc - 1);

    // reallocating the new memory
    tmp_arr = (int*)realloc(pArr, new_len*sizeof(int));

    // assigning the odds to the tmp array
    counter = 0;
    for (int i = 0; i <= argc - 1; ++i) {

        if (atoi(argv[i]) % 2 == 1) {
            *(tmp_arr + counter) = atoi(argv[i]);
            ++counter;
        }
    }

    // assigning the tmp array to the original array
    pArr = tmp_arr;

    //printing the array
    print_arr(pArr, counter);

    //freeing the memory
    free(tmp_arr);

    return 0;
}

// finding how many odds there are
int find_odds(int * pArr, int len) {

    int odd_len = 0;

    for (int i = 0; i < len; ++i) {

        if (*(pArr + i) % 2 != 0) {
            ++odd_len;
        }

    }

    return odd_len;

}

//printing the array
void print_arr(int * pArr, int len) {

    // adding up the odds
    int total = 0;
    for (int i = 0; i < len; ++i) {
            printf("%d\n", *(pArr + i));
            total += *(pArr + i);
        }
    // the total
    printf("%d\n", total);
}
