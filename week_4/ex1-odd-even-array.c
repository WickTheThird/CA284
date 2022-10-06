#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

    This task is supposed to add all the odds 
    and subbstract from the first even number
    the rest of the even numbers

*/

// adding the odds
void adding_odds(int arr [], int len_arr) {

    // the total will resort to 0 in case there are no elements
    // otherwise it will take the first element and add it
    int total = 0;

    if (len_arr > 0) {
        total = arr[0];
    }

    for (int i = 1; i < len_arr; ++i) {

        total += arr[i];

    }

    printf("%d\n", total);

}

// subtract the evens
void subtract_evens(int arr [], int len_arr) {

    // the samne logic applies to the subtract_evens
    // the only difference being that you are subtracting
    // from the first element

    int total = 0;

    if (len_arr > 0) {

        total = arr[0];

    }

    for (int i = 1; i < len_arr; ++i) {

        total -= arr[i];

    }

    printf("%d\n", total);

}

/*

the main loop takes all the evens and adds them to an array
ssame thibg withg the odds but a different array
and them sends the array and len of the array to the
corresponding function

*/

int main(int argc, char *argv[])
{

    int evens [argc  - 1];
    int odds [argc - 1];

    int e = 0;
    int o = 0;

    for (int i = 1; i <= argc - 1; ++i) {

        if (atoi(argv[i]) % 2 == 0) {
            evens[e] = atoi(argv[i]);
            ++e;
        } else {
            odds[o] = atoi(argv[i]);
            ++o;
        }
    }

    adding_odds(odds, o);
    subtract_evens(evens, e);

    return 0;

}
