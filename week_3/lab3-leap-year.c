#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void find_leap_year(int starting_year, int ending_year) {

    for (int i = starting_year; i <= ending_year; ++i) {

        if (i % 4 == 0 && i % 100 != 0) {

            printf("%d\n", i);

        } else if (i % 400 == 0) {

            printf("%d\n", i);

        }
    }
}

int main(int argc, char *argv[])
{

        int starting_year = atoi(argv[1]);
        int ending_year = atoi(argv[2]);

        find_leap_year(starting_year, ending_year);

        return 0;
}