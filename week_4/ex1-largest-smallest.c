#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

This code takes input from the command line
The first element will define what we're looig for (min, max)
The rest will be the set of possible values in which we must find the requied value

*/


// find max function
void find_max (float arr [], int len_arr) {

    // we dont know which value is the biggest, thuse we're taking the fist value 
    // and we'll compare it to the rest to make sure
    float max = arr[0];

    for (int i = 1; i < len_arr; ++i) {

        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("%.2f\n", max);

}

//find min value function
void find_min (float arr [], int len_arr) {

    // the exact same explanation applies for the min
    // the only difference is that the compare sign is smaller than :))
    float min = arr[0];

    for (int i = 1; i < len_arr; ++i) {

        if (arr[i] < min) {
            min = arr[i];
        }
    }

    printf("%.2f\n", min);

}

// this calls the correct funtion, based on the first element
// of the command line (largest, smallest)

void find_checker (char *line, float arr [], int len_arr) {

    if (strcmp(line, "largest") == 0) {
        find_max(arr, len_arr);

    } else if (strcmp(line, "smallest") == 0) {
        find_min(arr, len_arr);

    }

}

// in the main function we are appending the floats to an array
// we we'll alsop have a len to that array
// and we are also finding the first command line argument

int main(int argc, char *argv[])
{

    char * req = argv[1];
    float nr_arr[argc - 2];

    int j = 0;
    for (int i = 2; i < argc; ++i) {

        nr_arr[j] = atof(argv[i]);

        ++j;
    }

    find_checker(req, nr_arr, j);

    return 0;
}